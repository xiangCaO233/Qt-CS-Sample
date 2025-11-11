#ifndef QTIP_MAINSERVER_H
#define QTIP_MAINSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MainServer : public QObject {
    Q_OBJECT
   public:
    explicit MainServer(QObject* parent = nullptr);
    ~MainServer();

    // 启动服务器
    void startServer(short port);

    // 关闭服务器
    void stopServer();

    // 服务器是否存活
    bool alive();

   private slots:
    // 新连接
    void onNewConnection();

    // 新可读取数据
    void onReadyRead();

    // 新断开连接
    void onClientDisconnect();

   private:
    QTcpServer* m_Server;
    QList<QTcpSocket*> m_Clients;
};

#endif  // QTIP_MAINSERVER_H
