#include "book_search.h"
#include "ui_book_search.h"
#include <iostream>
#include <QScrollBar>
#include <QMessageBox>
Book_search::Book_search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Book_search)
{
    ui->setupUi(this);

    this->book_list.UpdateList();
    this->user.updateList();
    this->account.updateList();
    this->request.updateList();
    //u
    //QStringList user;
    //user <<QString::fromStdString(this->login_acc.getName())<< "userpage"<<"logout";
    //ui->user_page->addItems(user);
    ///

    ui->bookname->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->author->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

            //hover for lits, and color
    QPalette palette;
    palette.setColor(QPalette::Highlight,QColor(222,174,59));
    ui->bookname->setPalette(palette);
    ui->bookname->setMouseTracking(true);
    ui->author->setPalette(palette);
    ui->author->setMouseTracking(true);
    ui->type->setPalette(palette);
    ui->type->setMouseTracking(true);
    ui->bookname->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    ui->author->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    ui->type->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    ui->searchbox->setPalette(palette);
    ui->searchmethod->setPalette(palette);
    ui->user_page->setPalette(palette);

    /// scroll bar connect
    connect(ui->type->verticalScrollBar(),&QSlider::valueChanged,ui->author->verticalScrollBar(),&QSlider::setValue);
    connect(ui->type->verticalScrollBar(),&QSlider::valueChanged,ui->bookname->verticalScrollBar(),&QSlider::setValue);
    connect(ui->bookname->verticalScrollBar(),&QSlider::valueChanged,ui->author->verticalScrollBar(),&QSlider::setValue);
    connect(ui->bookname->verticalScrollBar(),&QSlider::valueChanged,ui->type->verticalScrollBar(),&QSlider::setValue);
    connect(ui->author->verticalScrollBar(),&QSlider::valueChanged,ui->bookname->verticalScrollBar(),&QSlider::setValue);
    connect(ui->author->verticalScrollBar(),&QSlider::valueChanged,ui->type->verticalScrollBar(),&QSlider::setValue);
    ui->bookname->verticalScrollBar()->hide();
    ui->author->verticalScrollBar()->hide();


    //add search method box
    QStringList search_method;
    search_method <<"Search By Name"<<"Search By Author"<<"Search By Genre";
    ui->searchmethod->addItems(search_method);
    //separate into pages
    ui->spinBox->setValue(1);
    ///
    ui->borrow->show();
    ui->edit->hide();
    ui->Login->show();
    update_list();

}

void Book_search::receive(Account info){
    this->login_acc = info;
    QStringList user;
    ui->user_page->clear();
    user<< QString::fromStdString(this->login_acc.getName())<<"userpage"<<"logout";
    ui->user_page->addItems(user);
    if(this->login_acc.getRID() >=4) ui->borrow->hide();
    if(this->login_acc.getRID() >=2 ){
        ui->edit->show();
    }
    ui->Login->hide();


}

Book_search::~Book_search()
{
    this->book_list.SaveList();
    this->user.saveList();
    this->account.saveList();
    this->request.saveList();
    delete ui;
}

void Book_search::update_list(){
    enum search_method{By_Name, By_Author, By_Genre};
    ui->bookname->clear();
    ui->author->clear();
    ui->type->clear();
    std::string search_str(ui->searchbox->text().toStdString());
    int ini_in = (ui->spinBox->value() -1)*20, term_in=(ui->spinBox->value())*20 ;
    int count=0;
    if(ui->searchbox->text() != NULL){
        for(int i = 0;i < this->book_list.returnList().size();i++){
            std::string temp;
            switch(ui->searchmethod->currentIndex()){
            case By_Name:
                temp = this->book_list.returnList().at(i).Bookname;
                break;
            case By_Author:
                temp = this->book_list.returnList().at(i).Publisher;
                break;
            case By_Genre:
                temp = this->book_list.returnList().at(i).Type;
                break;
            }
            QString temp_QS  = QString::fromStdString(temp);
            QString search_QS = QString::fromStdString(search_str);
            if(temp_QS.contains(search_QS,Qt::CaseInsensitive)){
                if(count >= ini_in && count <= term_in){
                    ui->bookname->addItem(QString::fromStdString(this->book_list.returnList().at(i).Bookname));
                    ui->author->addItem(QString::fromStdString(this->book_list.returnList().at(i).Publisher));
                    ui->type->addItem(QString::fromStdString(this->book_list.returnList().at(i).Type));
                }
                count++;
            }
        }
    }else{
        for(int i = 0; i < this->book_list.returnList().size();i ++){
            if(count >= ini_in && count <= term_in){
                ui->bookname->addItem(QString::fromStdString(this->book_list.returnList().at(i).Bookname));
                ui->author->addItem(QString::fromStdString(this->book_list.returnList().at(i).Publisher));
                ui->type->addItem(QString::fromStdString(this->book_list.returnList().at(i).Type));
            }
            count++;
        }
    }
    this->count_the_no_book = count;
}

void Book_search::on_edit_clicked()
{
    edit_book *edit = new edit_book;
    edit->receiver(this->book_list,this->login_acc,this->request,this->account);
    edit->show();
    this->close();
}

void Book_search::on_user_page_currentIndexChanged(int index)
{
    switch(index){
    case user_name:
        break;
    case user_page:{
            Account_management *new_win = new Account_management;
            new_win->receive(this->user, this->account,this->login_acc);
            new_win->show();
            this->close();
            ui->user_page->setCurrentIndex(0);
        break;
    }
    case logout:
        ui->user_page->clear();
        ui->Login->show();
        ui->edit->hide();
        Account anno_acc;
        this->login_acc = anno_acc;
        break;
    }
}

void Book_search::on_searchbox_textChanged(const QString &arg1)
{
    ui->spinBox->setValue(1);
    update_list();
}

void Book_search::on_bookname_currentRowChanged(int currentRow)
{
    ui->bookname->setCurrentRow(currentRow);
    ui->author->setCurrentRow(currentRow);
    ui->type->setCurrentRow(currentRow);
}

void Book_search::on_author_currentRowChanged(int currentRow)
{
    on_bookname_currentRowChanged(currentRow);
}

void Book_search::on_type_currentRowChanged(int currentRow)
{
    on_bookname_currentRowChanged(currentRow);
}

void Book_search::on_Login_clicked()
{
    this->close();
    Login *log_in = new Login;
    log_in->receive(this->account);
    log_in->show();
}

void Book_search::on_spinBox_valueChanged(int arg1)
{
    int page_no = this->count_the_no_book/20;
    if(this->count_the_no_book%20 != 0){
        page_no++;
    }
    if(this->count_the_no_book <=20) page_no =1;
    if(arg1 == 0) ui->spinBox->setValue(1);
    else if(arg1 > page_no){
        std::string info_str= "Max page :" + std::to_string(page_no);
        QMessageBox::information(this,"Info",QString::fromStdString(info_str));
        ui->spinBox->setValue(1);
    }else update_list();
}

void Book_search::on_searchmethod_currentIndexChanged(int index)
{
    ui->searchbox->clear();

}

void Book_search::on_borrow_clicked()
{
    if(this->login_acc.getName() == ""){
        QMessageBox message(QMessageBox::Information, "Login Request",
                                QObject::tr("Please Login to borrow books.\n\n"
                                            "Contact the Librarian if you do not have an account"),
                                QMessageBox::NoButton ,
                                this, Qt::FramelessWindowHint);
            message.show();
            message.exec();
    }else{
        unsigned int request_id;
        for(int i = 0 ; i < this->book_list.returnList().size();i++){
            QString temp =QString::fromStdString(this->book_list.returnList().at(i).Bookname);
            if(temp == this->search_book){
                request_id = this->book_list.returnList().at(i).BookID;
                break;
            }
        }
        int request_result = this->request.RequestBook(this->login_acc.getAID(),request_id);
        if(request_result == SUCCESSFUL){
            QMessageBox::information(this,"Request Result", "Book Requested, Contact Librarian for information");
        }else QMessageBox::information(this,"Request Result", "We currently run out of this book, pleaze come back later");
    }
}

void Book_search::on_bookname_currentTextChanged(const QString &currentText)
{
    this->search_book = currentText;
}
