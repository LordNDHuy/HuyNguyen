/********************************************************************************
** Form generated from reading UI file 'userpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPAGE_H
#define UI_USERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userpage
{
public:
    QLineEdit *username;
    QLabel *username_lable;
    QLineEdit *email;
    QLabel *email_label;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *userpage)
    {
        if (userpage->objectName().isEmpty())
            userpage->setObjectName(QStringLiteral("userpage"));
        userpage->resize(624, 381);
        username = new QLineEdit(userpage);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(120, 30, 191, 31));
        username_lable = new QLabel(userpage);
        username_lable->setObjectName(QStringLiteral("username_lable"));
        username_lable->setGeometry(QRect(30, 40, 71, 16));
        email = new QLineEdit(userpage);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(120, 70, 191, 31));
        email_label = new QLabel(userpage);
        email_label->setObjectName(QStringLiteral("email_label"));
        email_label->setGeometry(QRect(30, 80, 71, 16));
        treeWidget = new QTreeWidget(userpage);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(70, 120, 541, 221));

        retranslateUi(userpage);

        QMetaObject::connectSlotsByName(userpage);
    } // setupUi

    void retranslateUi(QWidget *userpage)
    {
        userpage->setWindowTitle(QApplication::translate("userpage", "Form", Q_NULLPTR));
        username_lable->setText(QApplication::translate("userpage", "Username", Q_NULLPTR));
        email_label->setText(QApplication::translate("userpage", "Email", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class userpage: public Ui_userpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPAGE_H
