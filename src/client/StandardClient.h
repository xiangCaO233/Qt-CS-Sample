#ifndef QTIP_STANDARDCLIENT_H
#define QTIP_STANDARDCLIENT_H

#include <QObject>
#include <QTcpSocket>

class StandardClient : public QObject {
    Q_OBJECT
   public:
    explicit StandardClient(QObject* parent = nullptr);
    ~StandardClient();
    void connectToServer(const QString& host, quint16 port);
    void disconnectFromServer();

   private slots:
    void onConnected();
    void onReadyRead();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);

   private:
    QTcpSocket* m_Socket;
    QString m_Name;
};

#endif  // QTIP_STANDARDCLIENT_H
