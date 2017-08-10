/********************************************************************************
** Form generated from reading UI file 'login_notification.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_NOTIFICATION_H
#define UI_LOGIN_NOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_login_notification
{
public:

    void setupUi(QDialog *login_notification)
    {
        if (login_notification->objectName().isEmpty())
            login_notification->setObjectName(QStringLiteral("login_notification"));
        login_notification->resize(400, 300);

        retranslateUi(login_notification);

        QMetaObject::connectSlotsByName(login_notification);
    } // setupUi

    void retranslateUi(QDialog *login_notification)
    {
        login_notification->setWindowTitle(QApplication::translate("login_notification", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login_notification: public Ui_login_notification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_NOTIFICATION_H
