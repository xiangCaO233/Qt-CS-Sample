#include "StandardClient.h"

StandardClient::StandardClient(QObject* parent) : QObject(parent) {
    m_Socket = new QTcpSocket(this);
    connect(m_Socket, &QTcpSocket::connected, this,
            &StandardClient::onConnected);
    connect(m_Socket, &QTcpSocket::readyRead, this,
            &StandardClient::onReadyRead);
    connect(m_Socket, &QTcpSocket::disconnected, this,
            &StandardClient::onDisconnected);
    connect(m_Socket, &QTcpSocket::errorOccurred, this,
            &StandardClient::onError);
}

StandardClient::~StandardClient() = default;

void StandardClient::connectToServer(const QString& host, quint16 port) {
    qDebug() << "正在连接到服务器...";
    m_Socket->connectToHost(host, port);
}

void StandardClient::disconnectFromServer() { m_Socket->disconnectFromHost(); }

void StandardClient::onConnected() {
    qDebug() << "已成功连接到服务器!";
    // 发送一条消息
    m_Socket->write("你好，服务器!");
}

void StandardClient::onReadyRead() {
    QByteArray data = m_Socket->readAll();
    qDebug() << "收到服务器回复:" << data;
}

void StandardClient::onDisconnected() { qDebug() << "已与服务器断开连接。"; }

void StandardClient::onError(QAbstractSocket::SocketError socketError) {
    qDebug() << "连接错误:" << m_Socket->errorString();
}
