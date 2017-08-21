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
    option <<"Add Account"<<"Edit User" << "Edit Account";
    ui->option->addItems(option);

    /// tab account - role box add
    ui->user->setReadOnly(true);
    ui->user->setPalette(palette);
    ui->Account->setPalette(palette);
    ui->pass->setPalette(palette);

    ui->tabWidget->setTabText(0,"Add User");
    ui->tabWidget->setTabText(1,"Edit Account");
    ui->tabWidget->setTabText(2,"User Page");

    ui->user_name_up->setReadOnly(true);
    ui->user_mail_up->setReadOnly(true);
    ui->user_pro_up->setReadOnly(true);
    ui->user_id_up->setReadOnly(true);
    ui->dateEdit_up->setReadOnly(true);
    ui->account_up->setReadOnly(true);
    ui->Account_edit_user->setReadOnly(true);

    ui->user_name_up->setPalette(palette);
    ui->Account_edit_user->setPalette(palette);
    ui->user_mail_up->setPalette(palette);
    ui->user_pro_up->setPalette(palette);
    ui->user_id_up->setPalette(palette);
    ui->dateEdit_up->setPalette(palette);
    ui->account_up->setPalette(palette);
    ui->new_p_user->setPalette(palette);
    ui->old_p_user->setPalette(palette);
    ui->Account_edit->setPalette(palette);
    ui->name->setPalette(palette);
    ui->mailbox->setPalette(palette);
    ui->ID->setPalette(palette);
    ui->dateEdit->setPalette(palette);
    ui->occu->setPalette(palette);
    ui->Search_Box->setPalette(palette);
    ui->search->setPalette(palette);
    ui->reset_pw_box->clear();

}

void Account_management::receive(UsersMgr user_r, AccountsMgr acc_r,Account log_acc){
    this->user = user_r;
    this->account = acc_r;
    this->login_acc = log_acc;
    if(this->login_acc.getRID() < 4){
        ui->tabWidget->setTabEnabled(2,true);
        ui->tabWidget->setCurrentIndex(2);
        ui->tabWidget->setTabEnabled(1,false);
        ui->tabWidget->setTabEnabled(0,false);
        bool found =false;
        for(int i = 0;i<this->user.getUserList().size();i++){
            for(int j =0; j < this->user.getUserList().at(i).getAIDList().size();j++){
                int temp_id = this->user.getUserList().at(i).getAIDList().at(j);
                if(this->login_acc.getAID() == temp_id){
                    ui->user_name_up->setText( QString::fromStdString(
                                                   this->user.getUserList().at(i).getInfo().name));
                    ui->user_mail_up->setText( QString::fromStdString(
                                                   this->user.getUserList().at(i).getInfo().email));
                    ui->user_pro_up->setText( QString::fromStdString(
                                                  this->user.getUserList().at(i).getInfo().occupation));
                    ui->user_id_up->setText( QString::fromStdString(
                                                 this->user.getUserList().at(i).getInfo().id));
                    date bod;

                    bod = this->user.getUserList().at(i).getInfo().DoB;
                    QDate date(QDate(bod.year,bod.month,bod.year));
                    ui->dateEdit_up->setDate(date);
                    found = true;
                    ui->Account_edit_user->setText(QString::fromStdString(this->login_acc.getName()));
                    ui->Account_edit->setText(QString::fromStdString(this->login_acc.getName()));

                    break;

                }
            }
            if(found == true) break;
        }
    }else{
        ui->tabWidget->setTabEnabled(2,false);
        ui->tabWidget->setCurrentIndex(0);
        ui->tabWidget->setTabEnabled(1,true);
        ui->tabWidget->setTabEnabled(0,true);
    }

    get_username();
    //


}

Account_management::~Account_management()
{
    delete ui;

}

void Account_management::on_option_currentIndexChanged(int index)
{
    get_username();
    if(index == 0){
        ui->Username_list->clearSelection();
        ui->user->clear();
        ui->add_box->show();
        ui->remove_box->hide();
        ui->Remove_u->hide();
        ui->reset_box->hide();
        ui->pass_ed->hide();
    }else if(index == 1){
        ui->Username_list->clearSelection();
        ui->user->clear();
        ui->add_box->hide();
        ui->remove_box->hide();
        ui->Remove_u->show();
        ui->pass_ed->hide();
        ui->reset_box->hide();
    }else{
        ui->Username_list->clearSelection();
        ui->user->clear();
        ui->add_box->hide();
        ui->remove_box->show();
        ui->Remove_u->hide();
        ui->reset_box->show();
        //ui->pass_ed->show();
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
            role.setSysadmin(ui->sysadmin->isChecked());
            role.setLibra(ui->lib->isChecked());
            role.setUSr(ui->user_2->isChecked());
            bool sys = ui->sysadmin->isChecked(), lib = ui->lib->isChecked(), us= ui->user_2->isChecked();
            if(sys == false && lib == false && us == false){
                QMessageBox::warning(this,"Warning","No Role chosen");
            }else {
                int check =  account.createNew(acc,pass,role,user_id);
                if (check == INVALID_NAME){
                    QMessageBox::warning(this,"Warning","UserName taken");

                }else  QMessageBox::information(this,"Success","Successfully create new Account");

            }
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
            std::vector<Account> U_acc_list = this->account.getList(current_id);
            unsigned int current_acc;
            std::string temp = this->current_acc_list_item.toStdString();
            for(int i = 0; i<U_acc_list.size();i++){
                if(U_acc_list.at(i).getName() == temp){
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

void Account_management::on_pushButton_clicked()
{
    Login *log_in = new Login();
    this->hide();
    log_in->show();
}


void Account_management::on_change_pas_clicked()
{
    std::string oldpass = ui->old_p->text().toStdString(),
            newpass = ui->new_p->text().toStdString();
    if(oldpass != newpass&&newpass != ""){
        int AID;
        std::string currentText = ui->Account_edit->text().toStdString();
        for(int i = 0;i<this->account.getList().size();i++){
            if(this->account.getList().at(i).getName() == currentText){
                AID = this->account.getList().at(i).getAID();
                std::cout << AID<<'\n';
                //this->remove_list.erase(this->remove_list.begin()+ui->acc_list->currentRow());
                break;
            }
        }
        if(this->account.changePassword(AID,oldpass,newpass) == SUCCESS){
            ui->old_p->clear();
            ui->new_p->clear();
            QMessageBox::information(this,"Success","Successfully change Account pass");
        }else if(this->account.changePassword(AID,oldpass,newpass) == INVALID_PWD){
            ui->old_p->clear();
            ui->new_p->clear();
            QMessageBox::information(this,"Warning","Wrong Pass ");
        }
    }else QMessageBox::information(this,"Warning","New password is the same as old password");

}

void Account_management::on_edit_user_pass_clicked()
{
    std::string oldpass = ui->old_p_user->text().toStdString(),
            newpass = ui->new_p_user->text().toStdString();
    if(oldpass != newpass){
        int AID;
        std::string currentText = ui->Account_edit_user->text().toStdString();
        for(int i = 0;i<this->account.getList().size();i++){
            if(this->account.getList().at(i).getName() == currentText){
                AID = this->account.getList().at(i).getAID();
                std::cout << AID<<'\n';
                //this->remove_list.erase(this->remove_list.begin()+ui->acc_list->currentRow());
                break;
            }
        }
        if(this->account.changePassword(AID,oldpass,newpass) == SUCCESS){
            ui->old_p_user->clear();
            ui->new_p_user->clear();
            QMessageBox::information(this,"Success","Successfully change Account pass");
        }else if(this->account.changePassword(AID,oldpass,newpass) == INVALID_PWD){
            ui->old_p_user->clear();
            ui->new_p_user->clear();
            QMessageBox::information(this,"Warning","Wrong Pass ");
        }
    }else QMessageBox::information(this,"Warning","New password is the same as old password");

}

void Account_management::on_acc_list_currentTextChanged(const QString &currentText)
{
    this->current_acc_list_item = currentText;
    ui->reset_pw_box->clear();
    ui->Account_edit->setText(this->current_acc_list_item);
}

void Account_management::on_back_clicked()
{
    Book_search *book_search = new Book_search;
    book_search->receive(this->login_acc);
    book_search->show();
    this->close();
}

void Account_management::on_reset_pwd_clicked()
{
    if(ui->acc_list->currentRow() != -1){
        Account account;
        std::string currentText = this->current_acc_list_item.toStdString();
        for(int i = 0;i<this->account.getList().size();i++){
            if(this->account.getList().at(i).getName() == currentText){
                account = this->account.getList().at(i);
                std::cout << account.getName()<<'\n';
                //this->remove_list.erase(this->remove_list.begin()+ui->acc_list->currentRow());
                break;
            }
        }
        std::string reset_pass = this->account.reset(account);
        ui->reset_pw_box->setText(QString::fromStdString(reset_pass));
    }
}
