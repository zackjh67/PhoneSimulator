#include "notificationviewer.h"
#include "ui_notificationviewer.h"
#include <QDebug>



NotificationViewer::NotificationViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationViewer)
{
    ui->setupUi(this);
    //ui->messageLabel->hide();
}

NotificationViewer::~NotificationViewer()
{
    delete ui;
}

void NotificationViewer::setContact(QString contact)
{
    ui->contactNameLbl->setText(contact);
}

void NotificationViewer::setMessage(QString message)
{
    ui->messageLabel->setText(message);
}

void NotificationViewer::emitReplySig()
{
    qDebug() << "reply sent";
    qDebug() << ui->textEdit->toPlainText();
    QString reply = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    emit replySent(reply);

}

void NotificationViewer::slotKeyboardDone(QString keyboardInput)
{
    //this->currentText = keyboardInput;
    qDebug() << keyboardInput;
    ui->textEdit->setText(keyboardInput);
}
