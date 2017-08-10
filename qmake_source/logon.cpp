#include "logon.h"
#include "ui_logon.h"

logon::logon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logon)
{
    ui->setupUi(this);
    this->setWindowTitle("Register");
}

logon::~logon()
{
    delete ui;
}

void logon::on_pushButton_clicked()
{
    QString acc, pass,email;
    acc = ui->username->text();
    pass = ui->password->text();
    email = ui->mailbox->text();
    std::string account,pwd,mail;
    account = acc.toUtf8().constData();
    pwd = pass.toUtf8().constData();
    mail = email.toUtf8().constData();
    std::fstream info;
    if((account =="")||(pwd =="")||(mail=="")){

        ui->statusbox->setText("Invalid Inputs");
        ui->mailbox->clear();
        ui->password->clear();
        ui->username->clear();
    }else{
        std::fstream newuserfile;
        std::string newuser;
        newuser ="."+account;
        newuserfile.open(newuser,std::ios::out);
        newuserfile<<"harry potter1"<<'\n'<<"aug-01"<<'\n'<<"aug-20"<<'\n';
        newuserfile.close();
        info.open(".account",std::ios::out|std::ios::app);
        info << account<<'\n'<<pwd<<'\n'<<mail<<'\n'<<"-----------------------------------\n";
        info.close();
        this->close();
        login *a = new login;
        a->show();
    }

}

void logon::on_password_returnPressed()
{
    on_pushButton_clicked();
}
