/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *logonbutton;
    QLabel *status;
    QGroupBox *groupBox;
    QPushButton *loginbutton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *usrname;
    QLabel *pwd_lable;
    QLineEdit *pwd;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(436, 296);
        logonbutton = new QPushButton(login);
        logonbutton->setObjectName(QStringLiteral("logonbutton"));
        logonbutton->setGeometry(QRect(40, 250, 80, 23));
        logonbutton->setFlat(true);
        status = new QLabel(login);
        status->setObjectName(QStringLiteral("status"));
        status->setGeometry(QRect(250, 190, 121, 21));
        groupBox = new QGroupBox(login);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 391, 201));
        loginbutton = new QPushButton(groupBox);
        loginbutton->setObjectName(QStringLiteral("loginbutton"));
        loginbutton->setGeometry(QRect(140, 170, 111, 31));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(14);
        loginbutton->setFont(font);
        loginbutton->setFlat(true);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(31, 48, 341, 101));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        usrname = new QLineEdit(layoutWidget);
        usrname->setObjectName(QStringLiteral("usrname"));

        gridLayout->addWidget(usrname, 0, 1, 1, 1);

        pwd_lable = new QLabel(layoutWidget);
        pwd_lable->setObjectName(QStringLiteral("pwd_lable"));

        gridLayout->addWidget(pwd_lable, 1, 0, 1, 1);

        pwd = new QLineEdit(layoutWidget);
        pwd->setObjectName(QStringLiteral("pwd"));
        pwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(pwd, 1, 1, 1, 1);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", Q_NULLPTR));
        logonbutton->setText(QApplication::translate("login", "Register", Q_NULLPTR));
        status->setText(QString());
        groupBox->setTitle(QString());
        loginbutton->setText(QApplication::translate("login", "Login", Q_NULLPTR));
        label->setText(QApplication::translate("login", "UserName", Q_NULLPTR));
        pwd_lable->setText(QApplication::translate("login", "PassWord", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
