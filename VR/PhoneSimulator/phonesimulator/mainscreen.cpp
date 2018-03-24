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

    //create an instance of NotificationGetter
    notificationGetter = new NotificationGetter(this);

    //connects notificationGetter's signal to fire MainScreen's onnotifposted slot
    connect(notificationGetter, SIGNAL(notifPosted(QString)),
            this, SLOT(onNotifPosted(QString)));

    //start thread to listen for notifications
    notificationGetter->start();
}

MainScreen::~MainScreen()
{
    delete ui;
}

/*
 * Updates GUI when notification is posted.
 * @param notification  the notification that has been posted.
 */
void MainScreen::onNotifPosted(QString notification)
{
    //logic to add notification to feed
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText(notification);
    //listWidget->insertItem(row, newItem);
    ui->notificationListWidget->insertItem(0, newItem);


}


//void MainScreen::on_connectButton_clicked()
//{
//    //logic to add notification to feed
//    QListWidgetItem *newItem = new QListWidgetItem;
//    newItem->setText("second item yo");
//    //listWidget->insertItem(row, newItem);
//    ui->notificationListWidget->insertItem(0, newItem);
//}

void MainScreen::on_sendButton_clicked()
{
    emit showKeyboard();
    //quits for now just as a test
    //QApplication::quit();
    //notificationGetter->start();
}

void MainScreen::on_notificationListWidget_itemClicked(QListWidgetItem *item)
{
    item->setText("You clicked the box, guy!");
}

void MainScreen::SlotKeyboardDone(QString keyboardInput){
    ui->textEdit->setText(keyboardInput);
}



