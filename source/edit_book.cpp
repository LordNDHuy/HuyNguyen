#include "edit_book.h"
#include "ui_edit_book.h"
#include <iostream>
#include <QMessageBox>
#include <QScrollBar>
edit_book::edit_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_book)
{
    ui->setupUi(this);


    /// theme
    QPalette palette;
    palette.setColor(QPalette::Highlight,QColor(222,174,59));
    ui->Book_list->setPalette(palette);
    ui->Book_list->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    ui->Namebook->setPalette(palette);
    ui->Author->setPalette(palette);
    ui->Number->setPalette(palette);
    ui->genre->setPalette(palette);
    ui->search->setPalette(palette);
    ui->search_2->setPalette(palette);
    ui->search_edit->setPalette(palette);

    ui->Book_list_edit->setPalette(palette);
    ui->Book_list_edit->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    ui->Namebook_edit->setPalette(palette);
    ui->Author_edit->setPalette(palette);
    ui->Number_edit->setPalette(palette);
    ui->genre_edit->setPalette(palette);


    ui->tabWidget->setTabText(0,"Add Book");
    ui->tabWidget->setTabText(1,"Edit Book");
    ui->tabWidget->setTabText(2,"Request");

    ui->re_name->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->re_acc->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

            //hover for lits, and color
    palette.setColor(QPalette::Highlight,QColor(222,174,59));
    ui->re_acc->setPalette(palette);
    ui->re_acc->setMouseTracking(true);
    ui->re_name->setPalette(palette);
    ui->re_name->setMouseTracking(true);
    ui->re_status->setPalette(palette);
    ui->re_status->setMouseTracking(true);
    ui->re_name->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    ui->re_acc->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    ui->re_status->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    /// scroll bar connect
    connect(ui->re_status->verticalScrollBar(),&QSlider::valueChanged,ui->re_name->verticalScrollBar(),&QSlider::setValue);
    connect(ui->re_status->verticalScrollBar(),&QSlider::valueChanged,ui->re_acc->verticalScrollBar(),&QSlider::setValue);
    connect(ui->re_name->verticalScrollBar(),&QSlider::valueChanged,ui->re_acc->verticalScrollBar(),&QSlider::setValue);
    connect(ui->re_name->verticalScrollBar(),&QSlider::valueChanged,ui->re_status->verticalScrollBar(),&QSlider::setValue);
    connect(ui->re_acc->verticalScrollBar(),&QSlider::valueChanged,ui->re_name->verticalScrollBar(),&QSlider::setValue);
    connect(ui->re_acc->verticalScrollBar(),&QSlider::valueChanged,ui->re_status->verticalScrollBar(),&QSlider::setValue);
    ui->re_name->verticalScrollBar()->hide();
    ui->re_acc->verticalScrollBar()->hide();
    ui->number_left_edit->setReadOnly(true);
    //end theme
    update_list();
    update_list_edit();
    update_list_request();
}

edit_book::~edit_book()
{
    delete ui;
}


void edit_book::receiver(BooksCase book_list_r,Account log_acc,Request request, AccountsMgr account){
    this->book_list = book_list_r;
    this->log_acc = log_acc;
    this->request = request;
    this->account = account;
}
void edit_book::update_list_request(){
    this->Ticketsid.clear();
    for(int i = 0 ;i< this->request.returnList().size();i++){
        unsigned int temp_bo_re = this->request.returnList().at(i).bookID;
        for(int j = 0; j<this->book_list.returnList().size();j++){
            unsigned int temp_bo = this->book_list.returnList().at(j).BookID;
            if(temp_bo == temp_bo_re){
                QString temp = QString::fromStdString(this->book_list.returnList().at(j).Bookname);
                ui->re_name->addItem(temp);
                break;
            }
        }
        unsigned int temp_ac_re = this->request.returnList().at(i).accountID;
        for(int j = 0; j<this->account.getList().size();j++){
            unsigned int temp_ac = this->account.getList().at(j).getAID();
            if (temp_ac_re == temp_ac){
                QString temp = QString::fromStdString(this->account.getList().at(j).getName());
                ui->re_acc->addItem(temp);
                break;
            }
        }
        this->Ticketsid.push_back(this->request.returnList().at(i).id);
        if(this->request.returnList().at(i).pending ==true){
            ui->re_status->addItem("Pending");
        }else if(this->request.returnList().at(i).accepted == true){
            ui->re_status->addItem("Accepted");
        }else ui->re_status->addItem("Denied");
    }
}

void edit_book::update_list(){
    ui->Author->clear();
    ui->Namebook->clear();
    ui->Number->clear();
    ui->genre->clear();
    ui->Number->clear();
    ui->Book_list->clearSelection();
    ui->Book_list->clear();
    if(ui->search->text() != NULL){
        std::string search_str(ui->search->text().toStdString());
        for(int i = 0;i < this->book_list.returnList().size();i++){
            std::string temp = this->book_list.returnList().at(i).Bookname;
            QString temp_QS  = QString::fromStdString(temp);
            QString search_QS = QString::fromStdString(search_str);
            if(temp_QS.contains(search_QS,Qt::CaseInsensitive)){
                this->Search_list.push_back(this->book_list.returnList().at(i));
                ui->Book_list->addItem(QString::fromStdString(this->book_list.returnList().at(i).Bookname));
            }
        }
    }else{
        for(int i = 0; i < this->book_list.returnList().size();i ++){
            ui->Book_list->addItem(
                        QString::fromStdString(this->book_list.returnList().at(i).Bookname));
        }
    }

}


void edit_book::update_list_edit(){
    ui->Author_edit->clear();
    ui->Namebook_edit->clear();
    ui->Number_edit->clear();
    ui->genre_edit->clear();
    ui->Number_edit->clear();
    ui->Book_list_edit->clearFocus();
    ui->Book_list_edit->clearMask();
    ui->Book_list_edit->clearSelection();
    ui->Book_list_edit->clear();
    if(ui->search_edit->text() != NULL){
        std::string search_str(ui->search_edit->text().toStdString());
        for(int i = 0;i < this->book_list.returnList().size();i++){
            std::string temp = this->book_list.returnList().at(i).Bookname;
            QString temp_QS  = QString::fromStdString(temp);
            QString search_QS = QString::fromStdString(search_str);
            if(temp_QS.contains(search_QS,Qt::CaseInsensitive)){
                this->Search_list.push_back(this->book_list.returnList().at(i));
                ui->Book_list_edit->addItem(QString::fromStdString(this->book_list.returnList().at(i).Bookname));
            }
        }
    }else{
        for(int i = 0; i < this->book_list.returnList().size();i ++){
            ui->Book_list_edit->addItem(
                        QString::fromStdString(this->book_list.returnList().at(i).Bookname));
        }
    }

}

void edit_book::on_addnew_clicked()
{
    Book info;
    info.Bookname   = ui->Namebook->text().toStdString();
    info.Publisher  = ui->Author->text().toStdString();
    info.Total      = ui->Number->value();
    info.Type       = ui->genre->text().toStdString();
    ui->Book_list->addItem(ui->Namebook->text());
    std::cout << info.Bookname<<'\n';
    ui->Book_list_edit->clear();

    this->book_list.AddBook(info);

    update_list();
}

void edit_book::on_Update_clicked()
{
    Book info;
    std::string temp_bookname = ui->Book_list_edit->currentItem()->text().toStdString();
    for(int i = 0 ; i < this->book_list.returnList().size();i++){
        if(temp_bookname == this->book_list.returnList().at(i).Bookname){
            info = this->book_list.returnList().at(i);
            break;
        }
    }
    info.Bookname   = ui->Namebook_edit->text().toStdString();
    info.Publisher  = ui->Author_edit->text().toStdString();
    info.Total      = ui->Number_edit->value();
    info.Type       = ui->genre_edit->text().toStdString();
    this->book_list.EditBook(info,info.BookID);
    QListWidgetItem *a=ui->Book_list_edit->currentItem();
    a->setFlags(a->flags() | Qt::ItemIsEnabled);
    a->setText(QString::fromStdString(info.Bookname));
    ui->Book_list_edit->editItem(a);
}

void edit_book::on_search_textChanged(const QString &arg1)
{
    update_list();
}

void edit_book::on_remove_clicked()
{
    Book info;
    std::string temp_bookname = ui->Book_list_edit->currentItem()->text().toStdString();
    for(int i = 0 ; i < this->book_list.returnList().size();i++){
        if(temp_bookname == this->book_list.returnList().at(i).Bookname){
            info = this->book_list.returnList().at(i);
            break;
        }
    }
    this->book_list.DeleteBook(info.BookID);
    update_list_edit();
}



void edit_book::on_search_edit_textChanged(const QString &arg1)
{

    update_list_edit();
}

void edit_book::on_tabWidget_currentChanged(int index)
{
    if(index == 0)    update_list();
    else update_list_edit();
}

void edit_book::on_Book_list_edit_currentTextChanged(const QString &currentText)
{
    for(int i = 0;i < this->book_list.returnList().size();i++){
        QString temp_name = QString::fromStdString(this->book_list.returnList().at(i).Bookname);
        if(temp_name == currentText){
            QString temp = QString::fromStdString(this->book_list.returnList().at(i).Bookname);
            ui->Namebook_edit->setText(temp);
            temp = QString::fromStdString(this->book_list.returnList().at(i).Publisher);
            ui->Author_edit->setText(temp);
            temp = QString::fromStdString(this->book_list.returnList().at(i).Type);
            ui->genre_edit->setText(temp);
            ui->Number_edit->setValue(this->book_list.returnList().at(i).Total);
            ui->number_left_edit->setText(
                        QString::fromStdString(
                            std::to_string(this->book_list.returnList().at(i).Remain)));
            break;
        }
    }
}

void edit_book::on_pushButton_clicked()
{
    Book_search *book_search = new Book_search;
    book_search->receive(this->log_acc);
    book_search->show();
    this->close();
}

void edit_book::on_re_name_currentRowChanged(int currentRow)
{
    ui->re_acc->setCurrentRow(currentRow);
    ui->re_name->setCurrentRow(currentRow);
    ui->re_status->setCurrentRow(currentRow);
}

void edit_book::on_re_acc_currentRowChanged(int currentRow)
{
    on_re_name_currentRowChanged(currentRow);
}

void edit_book::on_re_status_currentRowChanged(int currentRow)
{
    on_re_name_currentRowChanged(currentRow);
}

void edit_book::on_accept_clicked()
{
    unsigned int acce = this->request.returnList().at(this->Ticketsid.at(ui->re_name->currentRow())-1).accepted;
    unsigned int pend = this->request.returnList().at(this->Ticketsid.at(ui->re_name->currentRow())-1).pending;
     if(acce == 1 && pend == 0){

        QMessageBox::information(this,"Remind","This book is already accepted");
    }else if(acce == 0 && pend ==1) {
        this->request.AcceptTicket(this->Ticketsid.at(ui->re_name->currentRow()));
        ui->re_acc->clear();
        ui->re_name->clear();
        ui->re_status->clear();
        update_list_request();
    }else  QMessageBox::information(this,"Remind","This book is denied");

}


void edit_book::on_deny_clicked()
{
    unsigned int acce = this->request.returnList().at(this->Ticketsid.at(ui->re_name->currentRow())-1).accepted;
    unsigned int pend = this->request.returnList().at(this->Ticketsid.at(ui->re_name->currentRow())-1).pending;
    if(acce == 0 && pend ==1){
        this->request.DenyTicket(this->Ticketsid.at(ui->re_name->currentRow()));
        ui->re_acc->clear();
        ui->re_name->clear();
        ui->re_status->clear();
        update_list_request();
    }
}
