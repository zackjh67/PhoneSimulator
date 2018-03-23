/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QPushButton *sendButton;
    QLabel *label;
    QLabel *label_2;
    QListWidget *notificationListWidget;
    QTextEdit *textEdit;

    void setupUi(QWidget *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName(QStringLiteral("MainScreen"));
        MainScreen->resize(411, 499);
        sendButton = new QPushButton(MainScreen);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(280, 460, 71, 23));
        sendButton->setMouseTracking(false);
        sendButton->setAutoDefault(false);
        label = new QLabel(MainScreen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 141, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(MainScreen);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 330, 141, 51));
        label_2->setFont(font);
        notificationListWidget = new QListWidget(MainScreen);
        new QListWidgetItem(notificationListWidget);
        notificationListWidget->setObjectName(QStringLiteral("notificationListWidget"));
        notificationListWidget->setGeometry(QRect(10, 40, 391, 301));
        textEdit = new QTextEdit(MainScreen);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 380, 301, 71));

        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QWidget *MainScreen)
    {
        MainScreen->setWindowTitle(QApplication::translate("MainScreen", "MainScreen", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainScreen", "Send", Q_NULLPTR));
        label->setText(QApplication::translate("MainScreen", "Phone Simulator", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainScreen", "Type your reply", Q_NULLPTR));

        const bool __sortingEnabled = notificationListWidget->isSortingEnabled();
        notificationListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = notificationListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainScreen", "New Item", Q_NULLPTR));
        notificationListWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
