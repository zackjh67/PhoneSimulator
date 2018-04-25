/********************************************************************************
** Form generated from reading UI file 'notificationviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATIONVIEWER_H
#define UI_NOTIFICATIONVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotificationViewer
{
public:
    QGridLayout *gridLayout;
    QLabel *contactNameLbl;
    QLabel *messageLabel;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *NotificationViewer)
    {
        if (NotificationViewer->objectName().isEmpty())
            NotificationViewer->setObjectName(QStringLiteral("NotificationViewer"));
        NotificationViewer->resize(400, 441);
        NotificationViewer->setStyleSheet(QLatin1String("QLabel#messageLabel {\n"
"	color:white;\n"
"}\n"
"QLabel#contactNameLbl {\n"
"	color:rgb(255, 85, 0)\n"
"}"));
        gridLayout = new QGridLayout(NotificationViewer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        contactNameLbl = new QLabel(NotificationViewer);
        contactNameLbl->setObjectName(QStringLiteral("contactNameLbl"));
        QFont font;
        font.setPointSize(11);
        contactNameLbl->setFont(font);

        gridLayout->addWidget(contactNameLbl, 0, 1, 1, 1);

        messageLabel = new QLabel(NotificationViewer);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        QFont font1;
        font1.setPointSize(10);
        messageLabel->setFont(font1);
        messageLabel->setScaledContents(true);
        messageLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(messageLabel, 1, 1, 1, 1);

        textEdit = new QTextEdit(NotificationViewer);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 3, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 130, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);


        retranslateUi(NotificationViewer);

        QMetaObject::connectSlotsByName(NotificationViewer);
    } // setupUi

    void retranslateUi(QWidget *NotificationViewer)
    {
        NotificationViewer->setWindowTitle(QApplication::translate("NotificationViewer", "Form", Q_NULLPTR));
        contactNameLbl->setText(QApplication::translate("NotificationViewer", "FROM", Q_NULLPTR));
        messageLabel->setText(QApplication::translate("NotificationViewer", "Message", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NotificationViewer: public Ui_NotificationViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATIONVIEWER_H
