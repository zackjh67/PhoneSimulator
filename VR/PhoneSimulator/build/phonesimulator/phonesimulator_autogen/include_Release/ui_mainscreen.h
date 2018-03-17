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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QPushButton *sendButton;
    QPushButton *connectButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName(QStringLiteral("MainScreen"));
        MainScreen->resize(349, 236);
        sendButton = new QPushButton(MainScreen);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(250, 170, 75, 23));
        sendButton->setMouseTracking(false);
        sendButton->setAutoDefault(false);
        connectButton = new QPushButton(MainScreen);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(30, 170, 75, 23));
        label = new QLabel(MainScreen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 251, 51));
        QFont font;
        font.setPointSize(28);
        label->setFont(font);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(MainScreen);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 80, 101, 51));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);

        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QWidget *MainScreen)
    {
        MainScreen->setWindowTitle(QApplication::translate("MainScreen", "MainScreen", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainScreen", "Send", Q_NULLPTR));
        connectButton->setText(QApplication::translate("MainScreen", "Connect", Q_NULLPTR));
        label->setText(QApplication::translate("MainScreen", "Hello World!", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainScreen", "Change Me!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
