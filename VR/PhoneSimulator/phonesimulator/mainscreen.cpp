#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "notificationviewer.h"
#include <QLayoutItem>
#include <QDebug>
#include <QGraphicsEffect>

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

    ui->backButton->hide();
    ui->keyboardButton->hide();

    viewer = new NotificationViewer;
    connect(this, &MainScreen::sendClickSig, viewer, &NotificationViewer::emitReplySig);
    connect(viewer, &NotificationViewer::replySent,
            this, &MainScreen::toggleViews);

    //add stacked viewer
    ui->stackedWidget->addWidget(viewer);

    //setup icons
    QString path = QApplication::applicationDirPath() + "/res/icons/newIcon.png";
    newIcon = new QIcon(path);
    path = QApplication::applicationDirPath() + "/res/icons/newIconPressed.png";
    newIconPressed = new QIcon(path);
    path = QApplication::applicationDirPath() + "/res/icons/sendIcon.png";
    sendIcon = new QIcon(path);
    path = QApplication::applicationDirPath() + "/res/icons/sendIconPressed.png";
    sendIconPressed = new QIcon(path);
    path = QApplication::applicationDirPath() + "/res/icons/backIcon.png";
    backIcon = new QIcon(path);
    path = QApplication::applicationDirPath() + "/res/icons/backIconPressed.png";
    backIconPressed = new QIcon(path);
    path = QApplication::applicationDirPath() + "/res/icons/keyboardIcon.png";
    keyboardIcon = new QIcon(path);
    path = QApplication::applicationDirPath() + "/res/icons/keyboardIconPressed.png";
    keyboardIconPressed = new QIcon(path);
    path = QApplication::applicationDirPath() + "/res/icons/messageIcon.png";
    messageIcon = new QIcon(path);

    ui->sendButton->setIcon(*newIcon);
    ui->keyboardButton->setIcon(*keyboardIcon);
    ui->backButton->setIcon(*backIcon);

    iconState = 0;
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
    //set styles
    newItem->setTextColor(QColor("white"));
    newItem->setIcon(*messageIcon);
    //newItem->setBackgroundColor(QColor("black")); //#ff5500


    newItem->setSizeHint((QSize(40, 40)));
    QFont f = newItem->font();
    f.setPointSize(16);
    newItem->setFont(f);

    //set message accordingly
    newItem->setText(notification[TICKER_KEY].toString());

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
    if(ui->stackedWidget->currentIndex() == 0){
        QJsonObject reply;
        reply.insert("nTicker", "Zack Hern: Just a test for now!");

        onNotifPosted(reply);
    } else {
        emit sendClickSig();
    }
}

void MainScreen::on_notificationListWidget_itemClicked(QListWidgetItem *item)
{
    //set current notification to the item
    this->currentNotif = item;

    QStringList params = item->text().split(": ");

    this->viewer->setContact(params[0]);
    this->viewer->setMessage(params[1]);

    //ui->sendButton->icon().swap(sendIcon);
    ui->sendButton->setIcon(*sendIcon);
    iconState = 1;

    ui->stackedWidget->setCurrentWidget(viewer);
    ui->backButton->show();
    ui->keyboardButton->show();
}

void MainScreen::toggleViews(QString replyMessage)
{
    qDebug() << "view toggled!";
    ui->sendButton->setIcon(*newIcon);
    iconState = 0;
    ui->stackedWidget->setCurrentIndex(0);

    ui->backButton->hide();
    ui->keyboardButton->hide();

    if(replyMessage.compare("BACK") != 0){

    //create jsonobject from listitem
    QJsonObject orig = currentNotif->data(Qt::UserRole).toJsonObject();
    //parse ticker
    QStringList params = orig[TICKER_KEY].toString().split(": ");
    //qDebug() << params;

    qDebug() << params[1];

    QJsonObject reply;
    qDebug() << params.front();
    reply.insert("who", params.front());
    params.pop_front();
    qDebug() << "param again" << params.front();
    reply.insert("message", replyMessage);

        emit sendReply(reply);

    //dismiss item from list
    ui->notificationListWidget->removeItemWidget(currentNotif);
    delete currentNotif;
    }

}




void MainScreen::on_sendButton_pressed()
{
    switch(iconState){
        case 0:
            ui->sendButton->setIcon(*newIconPressed);
        break;
        case 1:
            ui->sendButton->setIcon(*sendIconPressed);
        break;
    default:
        ui->sendButton->setIcon(*newIconPressed);
        break;
    }
    ui->sendButton->setIconSize(QSize(98, 98));
}

void MainScreen::on_sendButton_released()
{
    switch(iconState){
        case 0:
            ui->sendButton->setIcon(*newIcon);
        break;
        case 1:
            ui->sendButton->setIcon(*sendIcon);
        break;
    default:
        ui->sendButton->setIcon(*newIcon);
        break;
    }
    ui->sendButton->setIconSize(QSize(100, 100));
}

void MainScreen::on_keyboardButton_pressed()
{
    ui->keyboardButton->setIcon(*keyboardIconPressed);
    ui->keyboardButton->setIconSize(QSize(98, 98));
}

void MainScreen::on_keyboardButton_released()
{
    ui->keyboardButton->setIcon(*keyboardIcon);
    ui->keyboardButton->setIconSize(QSize(100, 100));
}

void MainScreen::on_backButton_pressed()
{
    ui->backButton->setIcon(*backIconPressed);
    ui->backButton->setIconSize(QSize(98, 98));
}

void MainScreen::on_backButton_released()
{
    ui->backButton->setIcon(*backIcon);
    ui->backButton->setIconSize(QSize(100, 100));
}

void MainScreen::on_keyboardButton_clicked()
{
    emit showKeyboard();
}

void MainScreen::on_backButton_clicked()
{
    toggleViews("BACK");
}

void MainScreen::createNewMessage()
{

}
