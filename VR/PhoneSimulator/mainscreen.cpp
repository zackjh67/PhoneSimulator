#include "mainscreen.h"
#include "ui_mainscreen.h"

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

void MainScreen::on_pushButton_clicked()
{
    //backend not yet setup
}

void MainScreen::on_sendButton_clicked()
{
    //quits for now just as a test
    QApplication::quit();
}

void MainScreen::on_label_2_linkActivated(const QString &link)
{

}
