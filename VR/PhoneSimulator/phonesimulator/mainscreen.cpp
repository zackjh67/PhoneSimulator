#include "mainscreen.h"
#include "ui_mainscreen.h"

/*
 * Main QWidget.
 * @author Zachary Hern
 * @version 3/18/17
 */
MainScreen::MainScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
}

MainScreen::~MainScreen()
{
    delete ui;
}

/*
 * Updates GUI when notification is posted.
 * @param notification  the notification that has been posted.
 */
void MainScreen::onNotifPosted(QJsonObject notification)
{
    //TODO:
    //if groupID exists look up in map and group merge with group

    //Create new item to put into list widget
    QListWidgetItem *newItem = new QListWidgetItem;
    //set message accordingly
    newItem->setText(notification[MESSAGE_KEY].toString());

    //create variant for data
    QVariant var;
    var = notification;

    //pass original notification id and group id to item
    newItem->setData(Qt::UserRole, var);

    //insert into beginning of widget
    ui->notificationListWidget->insertItem(0, newItem);
}

void MainScreen::on_sendButton_clicked()
{
    //create jsonobject from listitem
    QJsonObject reply = currentNotif->data(Qt::UserRole).toJsonObject();
    //add user reply from keyboard into it
    reply.insert("reply", currentText);

    //if there is text in the text box, send a reply to given notification
    if(!ui->textEdit->toPlainText().isEmpty()){
        emit sendReply(reply);
    }
}

void MainScreen::on_notificationListWidget_itemClicked(QListWidgetItem *item)
{
    //set current notification to the item
    this->currentNotif = item;

    //show keyboard to reply
    emit showKeyboard();

    //dismiss item from list
    //ui->notificationListWidget->removeItemWidget(item);
}

void MainScreen::slotKeyboardDone(QString keyboardInput){
    //save keyboard input as current text
    this->currentText = keyboardInput;

    ui->textEdit->setText(keyboardInput);
}



