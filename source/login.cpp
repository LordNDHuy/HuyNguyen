#include "login.h"
#include "ui_login.h"
#include "Book.h"
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setColor(QPalette::Highlight,QColor(222,174,59));
    ui->usrname->setPalette(palette);
    ui->pwd->setPalette(palette);
    this->admin.setAID(0);
    this->admin.setName("admin");
    this->admin.setRole(7);
    this->admin.setState(true);
    this->admin.setHash("admin");

}


Login::~Login()
{
    delete ui;

}

void Login::receive(AccountsMgr list){
    this->account = list;
}

int Login::on_loginbutton_clicked()
{
    Account login_acc;
    std::string User_name = ui->usrname->text().toStdString(),
            pass = ui->pwd->text().toStdString();
    if(User_name == this->admin.getName()&&pass == this->admin.getHash()){
        login_acc = this->admin;
        Book_search *book_search = new Book_search;
        book_search->receive(login_acc);
        book_search->show();
        this->close();
    }else{
        int check   =    this->account.verify(User_name,pass);
        ui->usrname->clear();
        ui->pwd->clear();
        ui->status->clear();
        if (check == SUCCESS){
            ui->status->setText("Success");
            std::cout << "success \n";
            for(int i = 0;i<this->account.getList().size();i++){
                if(User_name == this->account.getList().at(i).getName()){
                    login_acc = this->account.getList().at(i);
                    Book_search *book_search = new Book_search;
                    book_search->receive(login_acc);
                    book_search->show();
                    this->close();
                    break;
                }
            }
        }else if(check == INVALID_PWD){
            ui->status->setText("Wrong Pass");
            std::cout <<"wrong pass\n";
        }else {
            ui->status->setText("Wrong Name");
            std::cout <<"wrong name\n";
        }
    }

}

void Login::on_pwd_returnPressed()
{
    on_loginbutton_clicked();
}
