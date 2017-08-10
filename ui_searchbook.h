/********************************************************************************
** Form generated from reading UI file 'searchbook.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBOOK_H
#define UI_SEARCHBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchbook
{
public:
    QListWidget *bookname;
    QListWidget *author;
    QLineEdit *searchbox;
    QPushButton *searchbutton;
    QComboBox *searchmethod;
    QPushButton *Logon;
    QPushButton *Login;
    QLabel *loginstatus;
    QPushButton *borrow;
    QComboBox *user_page;
    QListWidget *year;
    QSpinBox *spinBox;

    void setupUi(QWidget *searchbook)
    {
        if (searchbook->objectName().isEmpty())
            searchbook->setObjectName(QStringLiteral("searchbook"));
        searchbook->resize(806, 512);
        bookname = new QListWidget(searchbook);
        bookname->setObjectName(QStringLiteral("bookname"));
        bookname->setGeometry(QRect(10, 110, 321, 301));
        author = new QListWidget(searchbook);
        author->setObjectName(QStringLiteral("author"));
        author->setGeometry(QRect(330, 110, 161, 301));
        searchbox = new QLineEdit(searchbook);
        searchbox->setObjectName(QStringLiteral("searchbox"));
        searchbox->setGeometry(QRect(10, 50, 321, 31));
        searchbutton = new QPushButton(searchbook);
        searchbutton->setObjectName(QStringLiteral("searchbutton"));
        searchbutton->setGeometry(QRect(110, 83, 81, 23));
        searchbutton->setFlat(true);
        searchmethod = new QComboBox(searchbook);
        searchmethod->setObjectName(QStringLiteral("searchmethod"));
        searchmethod->setGeometry(QRect(350, 50, 141, 31));
        searchmethod->setFrame(false);
        Logon = new QPushButton(searchbook);
        Logon->setObjectName(QStringLiteral("Logon"));
        Logon->setGeometry(QRect(347, 430, 80, 23));
        Logon->setFlat(true);
        Login = new QPushButton(searchbook);
        Login->setObjectName(QStringLiteral("Login"));
        Login->setGeometry(QRect(470, 430, 80, 23));
        Login->setFlat(true);
        loginstatus = new QLabel(searchbook);
        loginstatus->setObjectName(QStringLiteral("loginstatus"));
        loginstatus->setGeometry(QRect(460, 20, 120, 16));
        loginstatus->setLayoutDirection(Qt::LeftToRight);
        loginstatus->setAlignment(Qt::AlignCenter);
        borrow = new QPushButton(searchbook);
        borrow->setObjectName(QStringLiteral("borrow"));
        borrow->setGeometry(QRect(640, 210, 80, 23));
        borrow->setFlat(true);
        user_page = new QComboBox(searchbook);
        user_page->setObjectName(QStringLiteral("user_page"));
        user_page->setGeometry(QRect(500, 40, 79, 23));
        year = new QListWidget(searchbook);
        year->setObjectName(QStringLiteral("year"));
        year->setGeometry(QRect(490, 110, 101, 301));
        spinBox = new QSpinBox(searchbook);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(30, 460, 47, 24));

        retranslateUi(searchbook);

        QMetaObject::connectSlotsByName(searchbook);
    } // setupUi

    void retranslateUi(QWidget *searchbook)
    {
        searchbook->setWindowTitle(QApplication::translate("searchbook", "Form", Q_NULLPTR));
        searchbutton->setText(QApplication::translate("searchbook", "Search", Q_NULLPTR));
        Logon->setText(QApplication::translate("searchbook", "Register", Q_NULLPTR));
        Login->setText(QApplication::translate("searchbook", "Login", Q_NULLPTR));
        loginstatus->setText(QString());
        borrow->setText(QApplication::translate("searchbook", "Borrow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class searchbook: public Ui_searchbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBOOK_H
