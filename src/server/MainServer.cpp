#include "MainServer.h"

#include <qdebug.h>

MainServer::MainServer(QObject* parent) : QObject(parent) {
    // 初始化服务器
    m_Server = new QTcpServer(this);
    // 连接 服务器连接信号 到 本类的 有连接发生的槽
    connect(m_Server, &QTcpServer::newConnection, this,
            &MainServer::onNewConnection);
}

MainServer::~MainServer() { m_Server->close(); }

// 启动服务器
void MainServer::startServer(short port) {
    if (port <= 0) {
        qDebug() << "非法端口";
        return;
    }
    if (m_Server->listen(QHostAddress::Any, port)) {
        qDebug() << "服务器已启动,监听端口:" << port;
    } else {
        qDebug() << "启动服务器监听失败";
    }
}

// 关闭服务器
void MainServer::stopServer() {
    // 停止服务器，不再接受新连接
    m_Server->close();
    qDebug() << "服务器已停止监听。";

    // 遍历并断开所有现有客户端的连接
    qDebug() << "正在断开所有客户端连接...";
    for (const auto& client : m_Clients) {
        // 请求客户端优雅地断开连接
        // 这会触发客户端socket的disconnected()信号
        client->disconnectFromHost();
    }
}

// 服务器是否存活
bool MainServer::alive() { return m_Server->isListening(); }

// 新连接
void MainServer::onNewConnection() {
    // 获取客户端socket
    auto clientSocket = m_Server->nextPendingConnection();
    m_Clients.append(clientSocket);
    qDebug() << "接收到新客户端连接:" << clientSocket->peerAddress().toString();

    // 将客户端的行为连接到槽
    connect(clientSocket, &QTcpSocket::readyRead, this,
            &MainServer::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this,
            &MainServer::onClientDisconnect);
}

// 新可读取数据
void MainServer::onReadyRead() {
    // 获取信号(数据)发送对象
    auto clientSender = qobject_cast<QTcpSocket*>(sender());
    if (clientSender) {
        // 读取发送的数据
        auto recv_data = clientSender->readAll();
        qDebug() << QString("收到来自(%1)的消息:[%2]")
                        .arg(QString("%1:%2")
                                 .arg(clientSender->peerAddress().toString())
                                 .arg(clientSender->localPort()))
                        .arg(recv_data);
    }
}

// 新断开连接
void MainServer::onClientDisconnect() {
    auto clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket) {
        m_Clients.removeAll(clientSocket);
        clientSocket->deleteLater();
        qDebug() << "客户端:" << clientSocket->peerAddress().toString()
                 << " 已断开连接";
    }
}
