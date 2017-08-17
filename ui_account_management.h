/********************************************************************************
** Form generated from reading UI file 'account_management.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNT_MANAGEMENT_H
#define UI_ACCOUNT_MANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Account_management
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_6;
    QLineEdit *name;
    QLineEdit *mailbox;
    QLineEdit *ID;
    QDateEdit *dateEdit;
    QLabel *label_7;
    QLineEdit *occu;
    QPushButton *Register;
    QWidget *tab_2;
    QListWidget *Username_list;
    QLineEdit *Search_Box;
    QPushButton *search;
    QComboBox *option;
    QLabel *label_9;
    QLineEdit *user;
    QGroupBox *remove_box;
    QPushButton *remove;
    QListWidget *acc_list;
    QGroupBox *add_box;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_2;
    QCheckBox *user_2;
    QLabel *label_2;
    QLineEdit *pass;
    QLineEdit *Account;
    QLabel *label_8;
    QCheckBox *sysadmin;
    QCheckBox *lib;
    QLabel *label_4;
    QPushButton *add;
    QPushButton *Remove_u;
    QLabel *statusbox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Account_management)
    {
        if (Account_management->objectName().isEmpty())
            Account_management->setObjectName(QStringLiteral("Account_management"));
        Account_management->resize(648, 485);
        centralWidget = new QWidget(Account_management);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 601, 391));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 40, 341, 221));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        name = new QLineEdit(layoutWidget);
        name->setObjectName(QStringLiteral("name"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        mailbox = new QLineEdit(layoutWidget);
        mailbox->setObjectName(QStringLiteral("mailbox"));

        gridLayout->addWidget(mailbox, 1, 1, 1, 1);

        ID = new QLineEdit(layoutWidget);
        ID->setObjectName(QStringLiteral("ID"));

        gridLayout->addWidget(ID, 2, 1, 1, 1);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 3, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        occu = new QLineEdit(layoutWidget);
        occu->setObjectName(QStringLiteral("occu"));

        gridLayout->addWidget(occu, 4, 1, 1, 1);

        Register = new QPushButton(tab);
        Register->setObjectName(QStringLiteral("Register"));
        Register->setGeometry(QRect(250, 280, 80, 23));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(14);
        Register->setFont(font);
        Register->setFlat(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Username_list = new QListWidget(tab_2);
        Username_list->setObjectName(QStringLiteral("Username_list"));
        Username_list->setGeometry(QRect(20, 60, 251, 231));
        Search_Box = new QLineEdit(tab_2);
        Search_Box->setObjectName(QStringLiteral("Search_Box"));
        Search_Box->setGeometry(QRect(20, 10, 171, 31));
        search = new QPushButton(tab_2);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(200, 13, 80, 23));
        search->setFlat(true);
        option = new QComboBox(tab_2);
        option->setObjectName(QStringLiteral("option"));
        option->setGeometry(QRect(310, 10, 111, 23));
        option->setFrame(false);
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(310, 60, 57, 23));
        user = new QLineEdit(tab_2);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(373, 60, 186, 23));
        remove_box = new QGroupBox(tab_2);
        remove_box->setObjectName(QStringLiteral("remove_box"));
        remove_box->setGeometry(QRect(280, 80, 301, 221));
        remove = new QPushButton(remove_box);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(90, 191, 121, 21));
        remove->setFont(font);
        remove->setFlat(true);
        acc_list = new QListWidget(remove_box);
        acc_list->setObjectName(QStringLiteral("acc_list"));
        acc_list->setGeometry(QRect(28, 35, 251, 141));
        add_box = new QGroupBox(tab_2);
        add_box->setObjectName(QStringLiteral("add_box"));
        add_box->setGeometry(QRect(280, 80, 301, 221));
        layoutWidget_2 = new QWidget(add_box);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 20, 251, 162));
        gridLayout_2 = new QGridLayout(layoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        user_2 = new QCheckBox(layoutWidget_2);
        user_2->setObjectName(QStringLiteral("user_2"));

        gridLayout_2->addWidget(user_2, 3, 2, 1, 1);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        pass = new QLineEdit(layoutWidget_2);
        pass->setObjectName(QStringLiteral("pass"));

        gridLayout_2->addWidget(pass, 4, 2, 1, 1);

        Account = new QLineEdit(layoutWidget_2);
        Account->setObjectName(QStringLiteral("Account"));

        gridLayout_2->addWidget(Account, 0, 2, 1, 1);

        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 4, 0, 1, 1);

        sysadmin = new QCheckBox(layoutWidget_2);
        sysadmin->setObjectName(QStringLiteral("sysadmin"));

        gridLayout_2->addWidget(sysadmin, 1, 2, 1, 1);

        lib = new QCheckBox(layoutWidget_2);
        lib->setObjectName(QStringLiteral("lib"));

        gridLayout_2->addWidget(lib, 2, 2, 1, 1);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        add = new QPushButton(add_box);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(110, 190, 80, 23));
        add->setFlat(true);
        Remove_u = new QPushButton(tab_2);
        Remove_u->setObjectName(QStringLiteral("Remove_u"));
        Remove_u->setGeometry(QRect(310, 150, 211, 23));
        Remove_u->setFont(font);
        Remove_u->setFlat(true);
        tabWidget->addTab(tab_2, QString());
        statusbox = new QLabel(centralWidget);
        statusbox->setObjectName(QStringLiteral("statusbox"));
        statusbox->setGeometry(QRect(30, 220, 111, 21));
        Account_management->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Account_management);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 648, 20));
        Account_management->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Account_management);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Account_management->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Account_management);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Account_management->setStatusBar(statusBar);
        QWidget::setTabOrder(tabWidget, Search_Box);
        QWidget::setTabOrder(Search_Box, search);
        QWidget::setTabOrder(search, Username_list);
        QWidget::setTabOrder(Username_list, user);
        QWidget::setTabOrder(user, acc_list);
        QWidget::setTabOrder(acc_list, Account);
        QWidget::setTabOrder(Account, sysadmin);
        QWidget::setTabOrder(sysadmin, lib);
        QWidget::setTabOrder(lib, user_2);
        QWidget::setTabOrder(user_2, pass);
        QWidget::setTabOrder(pass, add);
        QWidget::setTabOrder(add, remove);
        QWidget::setTabOrder(remove, option);
        QWidget::setTabOrder(option, name);
        QWidget::setTabOrder(name, mailbox);
        QWidget::setTabOrder(mailbox, ID);
        QWidget::setTabOrder(ID, dateEdit);
        QWidget::setTabOrder(dateEdit, occu);
        QWidget::setTabOrder(occu, Register);
        QWidget::setTabOrder(Register, Remove_u);

        retranslateUi(Account_management);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Account_management);
    } // setupUi

    void retranslateUi(QMainWindow *Account_management)
    {
        Account_management->setWindowTitle(QApplication::translate("Account_management", "Account_management", Q_NULLPTR));
        label_3->setText(QApplication::translate("Account_management", "Email", Q_NULLPTR));
        label_5->setText(QApplication::translate("Account_management", "Date Of Birth", Q_NULLPTR));
        label->setText(QApplication::translate("Account_management", "Full Name", Q_NULLPTR));
        label_6->setText(QApplication::translate("Account_management", "ID number", Q_NULLPTR));
        dateEdit->setDisplayFormat(QApplication::translate("Account_management", "dd/MM/yyyy", Q_NULLPTR));
        label_7->setText(QApplication::translate("Account_management", "Occupation", Q_NULLPTR));
        Register->setText(QApplication::translate("Account_management", "Register", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Account_management", "Tab 1", Q_NULLPTR));
        search->setText(QApplication::translate("Account_management", "Search", Q_NULLPTR));
        label_9->setText(QApplication::translate("Account_management", "User", Q_NULLPTR));
        remove_box->setTitle(QString());
        remove->setText(QApplication::translate("Account_management", "Remove", Q_NULLPTR));
        add_box->setTitle(QString());
        user_2->setText(QApplication::translate("Account_management", "User", Q_NULLPTR));
        label_2->setText(QApplication::translate("Account_management", "Account", Q_NULLPTR));
        label_8->setText(QApplication::translate("Account_management", "Password", Q_NULLPTR));
        sysadmin->setText(QApplication::translate("Account_management", "SysAdmin", Q_NULLPTR));
        lib->setText(QApplication::translate("Account_management", "Librarian", Q_NULLPTR));
        label_4->setText(QApplication::translate("Account_management", "Role", Q_NULLPTR));
        add->setText(QApplication::translate("Account_management", "Add", Q_NULLPTR));
        Remove_u->setText(QApplication::translate("Account_management", "Remove User", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Account_management", "Tab 2", Q_NULLPTR));
        statusbox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Account_management: public Ui_Account_management {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_MANAGEMENT_H
