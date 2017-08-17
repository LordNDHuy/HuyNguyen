#include "account_management.h"
#include "ui_account_management.h"
#include <iostream>
#include <QMessageBox>
Account_management::Account_management(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Account_management)
{
    ui->setupUi(this);
    this->setWindowTitle("Register");
    ui->tabWidget->setTabText(0,"User Infomation");
    ui->tabWidget->setTabText(1,"Account");


    this->user.updateList();
    this->account.updateList();
    get_username();

    //ui->Username_list->setCurrentRow(0);
    for(int i = 0; i < this->search_list->User_name.size();i++){
        std::cout << this->search_list->Uid.at(i)<<'\t'<<this->search_list->User_name.at(i).toStdString()<<'\n';
    }
    //
    QPalette palette;
    palette.setColor(QPalette::Highlight,QColor(222,174,59));
    ui->Username_list->setPalette(palette);
    ui->Username_list->setMouseTracking(true);
    ui->Username_list->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    ui->acc_list->setPalette(palette);
    ui->acc_list->setMouseTracking(true);
    ui->acc_list->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");

    /// option add
    QStringList option;
    option <<"Add Account"<<"Edit Account" << "Delete user";
    ui->option->addItems(option);

    /// tab account - role box add
    ui->user->setReadOnly(true);
    ui->user->setPalette(palette);
    ui->Account->setPalette(palette);
    ui->pass->setPalette(palette);



}

Account_management::~Account_management()
{
    this->user.saveList();
    this->account.saveList();
    delete ui;

}

void Account_management::on_option_currentIndexChanged(int index)
{
    if(index == 0){
        ui->Username_list->clearSelection();
        ui->user->clear();
        ui->add_box->show();
        ui->remove_box->hide();
        ui->Remove_u->hide();
    }else if(index == 1){
        ui->Username_list->clearSelection();
        ui->user->clear();

        ui->add_box->hide();
        ui->remove_box->hide();
        ui->Remove_u->show();
    }else{
        ui->Username_list->clearSelection();
        ui->user->clear();
        ui->add_box->hide();
        ui->remove_box->show();
        ui->Remove_u->hide();
    }
}

void Account_management::on_Register_clicked()
{
    info new_account;
    new_account.name = ui->name->text().toStdString();
    new_account.email = ui->mailbox->text().toStdString();
    new_account.id = ui->ID->text().toStdString();
    new_account.occupation = ui->occu->text().toStdString();
    new_account.DoB.date = ui->dateEdit->date().toString("dd").toInt();
    new_account.DoB.month = ui->dateEdit->date().toString("MM").toInt();
    new_account.DoB.year = ui->dateEdit->date().toString("yyyy").toInt();
    this->user.createNew(new_account);

    //clear input
    ui->name->clear();
    ui->mailbox->clear();
    ui->ID->clear();
    ui->occu->clear();
    ui->dateEdit->clear();
    //
    get_username();
}

void Account_management::on_occu_returnPressed()
{
    on_Register_clicked();
}

void Account_management::get_username(){
    ui->Username_list->clear();
    QS_user temp_list;
    for(int i = 0;i< user.getUserList().size();i++){
        QString temp;
        std::string tempname;
        tempname = user.getUserList().at(i).getInfo().name;
        temp = QString::fromStdString(tempname);
        //ui->Username_list->addItem(temp);
        temp_list.User_name.push_back(temp);
        temp_list.Uid.push_back(user.getUserList().at(i).getUID());
    }
    *search_list = temp_list;

    ui->Username_list->addItems(search_list->User_name);

}



void Account_management::on_Username_list_currentTextChanged(const QString &currentText)
{
    ui->user->setText(currentText);
    ui->Account->clear();
    ui->pass->clear();
    ui->sysadmin->setChecked(false);
    ui->lib->setChecked(false);
    ui->user_2->setChecked(false);
    int current_id;
    if(ui->option->currentIndex()==0){
        for(int i = 0;i<this->search_list->User_name.size();i++){
            if(this->search_list->User_name.at(i) == currentText){
                current_id = i;
                std::cout <<current_id;
                break;
            }
        }
        //std::cout <<this->search_list->User_name.at(current_id).toStdString()<<'\t'<< this->search_list->Uid.at(current_id)<<'\n';
    }else{
        ui->acc_list->clear();
        for(int i = 0;i<this->search_list->User_name.size();i++){
            if(this->search_list->User_name.at(i) == currentText){
                current_id = i;
                break;
            }
        }
        std::vector<Account> U_acc_list = account.getList(current_id+1);
        for(int i =0;i <U_acc_list.size();i++){
            ui->acc_list->addItem(QString::fromStdString(U_acc_list.at(i).getName()));
       }
    }
}


void Account_management::on_Search_Box_textChanged(const QString &arg1)
{
    QRegExp search_string(arg1,Qt::CaseInsensitive, QRegExp::Wildcard);
    ui->Username_list->clear();
    QStringList temp_list = this->search_list->User_name.filter(search_string);
    ui->Username_list->addItems(temp_list);
}

void Account_management::on_add_clicked()
{
    unsigned int current_id;
    if(ui->user->text()!=NULL){
        QString current_text = ui->Username_list->currentItem()->text();

        for(int i = 0;i<this->search_list->User_name.size();i++){
            if(this->search_list->User_name.at(i) == current_text){
                current_id = i; // user id here dont know why it is i,but not search_list.uid.at(i)
                break;
            }
        }
        std::string acc = ui->Account->text().toStdString(),pass = ui->pass->text().toStdString();
        if(acc !=""){
            unsigned int user_id = this->search_list->Uid.at(current_id);
            ui->Account->clear();
            ui->pass->clear();
            RoleID role;
            role.setSysadmin(ui->sysadmin->isTristate());
            role.setLibra(ui->lib->isTristate());
            role.setUSr(ui->user_2->isTristate());
            account.createNew(acc,pass,role,user_id);
        }
    }
}

void Account_management::on_remove_clicked()
{
    if(ui->acc_list->currentRow() != -1){

        QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning",
                                                        "Do you want to remove this Account?",QMessageBox::Yes| QMessageBox::No);

        if(reply == QMessageBox::Yes){
            int current_id;
            std::string currentText = ui->user->text().toStdString();
            for(int i = 0;i<this->search_list->User_name.size();i++){
                if(this->search_list->User_name.at(i).toStdString() == currentText){
                    current_id = this->search_list->Uid.at(i);
                    std::cout << current_id<<'\n';
                    //this->remove_list.erase(this->remove_list.begin()+ui->acc_list->currentRow());
                    break;
                }
            }
            std::vector<Account> U_acc_list = account.getList(current_id);
            unsigned int current_acc;
            for(int i = 0; i<U_acc_list.size();i++){
                std::string temp_acc =  ui->acc_list->currentItem()->text().toStdString();
                if(U_acc_list.at(i).getName() == temp_acc){
                    current_acc = U_acc_list.at(i).getAID();
                    break;
                }
            }
            account.delAccount(current_id,current_acc);
            U_acc_list = account.getList(current_id);
            ui->acc_list->clear();
            for(int i =0;i <U_acc_list.size();i++){
                ui->acc_list->addItem(QString::fromStdString(U_acc_list.at(i).getName()));
            }
        }


    }
}

void Account_management::get_UID(unsigned int &userID){
    QString current_text = ui->Username_list->currentItem()->text();

    for(int i = 0;i<this->search_list->User_name.size();i++){
        if(this->search_list->User_name.at(i) == current_text){
            userID = this->search_list->Uid.at(i);
            break;
        }
    }
}


void Account_management::on_Remove_u_clicked()
{
    if(ui->Username_list->currentRow() != -1){

        QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning",
                                                        "Do you want to remove this User?",QMessageBox::Yes| QMessageBox::No);

        if(reply == QMessageBox::Yes){
            unsigned int userId;
            Account_management::get_UID(userId);
            user.delUser(userId);
            ui->Username_list->clear();
            get_username();
        }
    }
}
