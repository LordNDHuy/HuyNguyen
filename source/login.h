#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <iostream>
#include "Account.h"
#include "UsrInfo.h"
#include "book_search.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void receive(AccountsMgr);
private slots:
    int on_loginbutton_clicked();

    void on_pwd_returnPressed();

private:
    Ui::Login *ui;
    UsersMgr user;
    AccountsMgr account;
    Account admin;

};

#endif // LOGIN_H
