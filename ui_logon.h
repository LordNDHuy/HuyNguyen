/********************************************************************************
** Form generated from reading UI file 'logon.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGON_H
#define UI_LOGON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logon
{
public:
    QPushButton *pushButton;
    QLabel *statusbox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *username;
    QLabel *label_3;
    QLineEdit *mailbox;
    QLabel *label_2;
    QLineEdit *password;

    void setupUi(QWidget *logon)
    {
        if (logon->objectName().isEmpty())
            logon->setObjectName(QStringLiteral("logon"));
        logon->resize(400, 300);
        pushButton = new QPushButton(logon);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 220, 80, 23));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(14);
        pushButton->setFont(font);
        pushButton->setFlat(true);
        statusbox = new QLabel(logon);
        statusbox->setObjectName(QStringLiteral("statusbox"));
        statusbox->setGeometry(QRect(40, 220, 111, 21));
        widget = new QWidget(logon);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 40, 341, 151));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        username = new QLineEdit(widget);
        username->setObjectName(QStringLiteral("username"));

        gridLayout->addWidget(username, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        mailbox = new QLineEdit(widget);
        mailbox->setObjectName(QStringLiteral("mailbox"));

        gridLayout->addWidget(mailbox, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        password = new QLineEdit(widget);
        password->setObjectName(QStringLiteral("password"));
        password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password, 2, 1, 1, 1);


        retranslateUi(logon);

        QMetaObject::connectSlotsByName(logon);
    } // setupUi

    void retranslateUi(QWidget *logon)
    {
        logon->setWindowTitle(QApplication::translate("logon", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("logon", "Register", Q_NULLPTR));
        statusbox->setText(QString());
        label->setText(QApplication::translate("logon", "Username", Q_NULLPTR));
        label_3->setText(QApplication::translate("logon", "Email", Q_NULLPTR));
        label_2->setText(QApplication::translate("logon", "Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class logon: public Ui_logon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGON_H
