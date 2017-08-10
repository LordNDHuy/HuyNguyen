#include "login.h"
#include "ui_login.h"
#include <QString>
#include "searchbook.h"
#include <iostream>
#include "logon.h"
#include <vector>
const std::string pwd = "admin";
const std::string usr = "admin";

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("Log in");
}

login::~login()
{
    delete ui;
}
//temporary account
typedef struct{
    std::string username;
    std::string password;
    std::string email;
}user;

std::vector<user> getdata();
void login::on_loginbutton_clicked()
{
    QString usrname_input = ui->usrname->text();
    std::string usr_input =    usrname_input.toUtf8().constData();
    QString pwd_input = ui->pwd->text();
    std::string password_input =    pwd_input.toUtf8().constData();
    searchbook *searchwindow = new searchbook;
    ui->status->hide();
    std::string usr_signal = "anno";
    std::vector<user> account;
    account =  getdata();
    if((usr_input == usr) && (password_input == pwd)){
        this->close();
        username = usrname_input;
        password = pwd_input;
        usr_signal = usr_input;
    }else{
        for(int i = 0;i < account.size();i++){
            if ((usr_input == account[i].username) && (password_input==account[i].password)){
                this->close();
                username = usrname_input;
                password = pwd_input;
                usr_signal = usr_input;
                break;
            }
        }
    }
    if((usr_input =="") && (password_input == "")){
        ui->status->setText(tr("Nothing input"));
        usr_signal = "anno";
    }
    searchwindow->show_window(usr_signal);
    searchwindow->move(200,100);

    this->close();

}



void login::on_logonbutton_clicked()
{
    logon *log_on = new logon;
    log_on->show();
    log_on->move(400,250);
    this->hide();
}


void login::on_pwd_returnPressed()
{
    on_loginbutton_clicked();
}
///read account

std::vector<user> getdata(){
    std::fstream file;
    std::vector<user> data;
    file.open(".account");
    std::string account;
    while (file)
    {
        user temp;
        getline(file, account);
        temp.username = account;
        getline(file, account);
        temp.password = account;
        getline(file, account);
        temp.email = account;
        data.push_back(temp);
        getline(file, account);

    }

    return data;
}
