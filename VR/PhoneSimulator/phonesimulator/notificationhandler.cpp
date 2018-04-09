#include "notificationhandler.h"
#include <QMessageBox>
#include "mainscreen.h"

NotificationHandler::NotificationHandler(QObject *parent) : QObject(parent)
  , tcpSocket(new QTcpSocket(this))
{
    //data stream in
    in.setDevice(tcpSocket);
    //in.setVersion(QDataStream::Qt_DefaultCompiledVersion);

    //connect socket signals to slots
    connect(tcpSocket, &QIODevice::readyRead, this, &NotificationHandler::getNotification);

    //TODO figure error signal out later
    //    connect(tcpSocket, qOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
    //            this, &NotificationHandler::displayError);
}

//connect to localhost server
void NotificationHandler::connectToServer(){
    tcpSocket->connectToHost("localhost", 8415);
}

//Thanks Qt -> http://doc.qt.io/qt-5/qtnetwork-fortuneclient-example.html
//nvm
void NotificationHandler::displayError(QAbstractSocket::SocketError socketError)
{
//    switch (socketError) {
//    case QAbstractSocket::RemoteHostClosedError:
//        break;
//    case QAbstractSocket::HostNotFoundError:
//        QMessageBox::information(this, tr("Phone Simulator"),
//                                 tr("The host was not found. Please check the "
//                                    "host name and port settings."));
//        break;
//    case QAbstractSocket::ConnectionRefusedError:
//        QMessageBox::information(this, tr("Phone Simulator"),
//                                 tr("The connection was refused by the peer. "
//                                    "Make sure the fortune server is running, "
//                                    "and check that the host name and port "
//                                    "settings are correct."));
//        break;
//    default:
//        QMessageBox::information(this, tr("Phone Simulator"),
//                                 tr("The following error occurred: %1.")
//                                 .arg(tcpSocket->errorString()));
//    }
}

//fires only if socket connected
void NotificationHandler::getNotification()
{
    //get message from socket
    QString message = tcpSocket->readAll();

    //JDoc from QString
    QJsonDocument jDoc = QJsonDocument::fromJson(message.toUtf8());

    //JsonObject from JDoc
    QJsonObject notif = jDoc.object();

    //send signal to GUI and Controller
    emit sigNotifReceived(notif);
}

void NotificationHandler::sendReply(QJsonObject reply)
{

    //convert json to doc
    QJsonDocument jd (reply);
    //doc to byteArray
    QByteArray bytesToSend = jd.toJson();

    //feed bytes to send into stream
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_DefaultCompiledVersion3);
    out << bytesToSend;

    tcpSocket->write(block);
}

