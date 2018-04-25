#ifndef NOTIFICATIONHANDLER_H
#define NOTIFICATIONHANDLER_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>
#include <QtNetwork>
#include <QJsonObject>
#include "mainscreen.h"

/* unordered map of QJsonObject vectors */
//typedef std::unordered_map< long, std::vector< QJsonObject >* > notif_list;

class NotificationHandler : public QObject
{
    Q_OBJECT
public:
    explicit NotificationHandler(QObject *parent = 0);


signals:
    void sigNotifReceived(QJsonObject notif);

private slots:
    void displayError(QAbstractSocket::SocketError socketError);

public slots:
    void connectToServer();
    void getNotification();
    void sendReply(QJsonObject reply);
    void sendConnectIntent();

private:
    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
    quint32 size;
    bool connectionSuccessful = false;
};

#endif // NOTIFICATIONHANDLER_H
