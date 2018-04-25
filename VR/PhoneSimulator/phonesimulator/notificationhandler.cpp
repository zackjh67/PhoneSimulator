#include "notificationhandler.h"
#include <QMessageBox>
#include "mainscreen.h"

bool sizeRead = false;

NotificationHandler::NotificationHandler(QObject *parent) : QObject(parent)
  , tcpSocket(new QTcpSocket(this))
{

    //connect socket signals to slots
    connect(tcpSocket, &QAbstractSocket::connected, this, &NotificationHandler::sendConnectIntent); //connected
    connect(tcpSocket, &QIODevice::readyRead, this, &NotificationHandler::getNotification);//ready to be read

    tcpSocket->connectToHost("localhost", 6969);


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
    //QString message = tcpSocket->readAll();
    qDebug() << "Data to be read!";
    //ui->label->setText("Something was sent back");



    QByteArray buffer;

    if(!sizeRead){

        buffer = tcpSocket->read(qint32(4)); //read first 4 bytes

        QDataStream ds(buffer);

        ds >> size;
        qDebug() << "size of header:";
        qDebug() << size;
        sizeRead = true;
        emit tcpSocket->readyRead();

    } else {
        //read the rest of the bytes
        buffer = tcpSocket->read((qint32)size);

        QDataStream ds(buffer);
        QString messageReceived(buffer);

        //ds >> test;
        qDebug() << "message was received";
        qDebug() << messageReceived;
        sizeRead = false;

        //successful connection response
        if(messageReceived.compare("404 OK") == 0){
            qDebug() << "Connected 404 ok";
            //ui->label->setText("Connected");
            //ui->pushButton->setEnabled(true);
        } else {
            //LOGIC

            //JDoc from QString
            QJsonDocument jDoc = QJsonDocument::fromJson(messageReceived.toUtf8());

            //JsonObject from JDoc
            QJsonObject notif = jDoc.object();

            //send signal to GUI and Controller
            emit sigNotifReceived(notif);

        }



}
}

void NotificationHandler::sendReply(QJsonObject reply)
{
        QJsonDocument doc(reply);
            qDebug() << doc.toJson().simplified();

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);

        out << doc.toJson().simplified();

        tcpSocket->write(block, block.size());
}

void NotificationHandler::sendConnectIntent()
{
    QString connstr = "Connect";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out << connstr.toUtf8(); //send in utf encoding- size is appendedto front automtically

    //write to socket
    tcpSocket->write(block, block.size());
}

