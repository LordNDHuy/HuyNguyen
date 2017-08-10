#include "book_edit.h"
#include "ui_book_edit.h"
#include <iostream>
#include "searchbook.h"
#include "readfile.h"
book_edit::book_edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::book_edit)
{
    ui->setupUi(this);
    ui->addnew->hide();
    ui->Update->show();
    QStringList edit_mode;
    edit_mode <<"Update"<<"Add New";
    ui->mode->addItems(edit_mode);
}

book_edit::~book_edit()
{
    delete ui;
}

void book_edit::edit( QStringList *book,QStringList *author,QStringList *year){
    this->show();
    book_edit::book     =   *book;
    book_edit::author   =   *author;
    book_edit::year     =   *year;
    ui->Book_list->addItems(book_edit::book);
    //palette
    QPalette palette;
    palette.setColor(QPalette::Highlight,QColor(222,174,59));
    ui->Book_list->setPalette(palette);
    ui->Book_list->setMouseTracking(true);
    ui->Book_list->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");

}


void book_edit::on_Book_list_currentRowChanged(int currentRow)
{
    ui->Namebook->setText(book.at(currentRow));
    ui->Author->setText(author.at(currentRow));
    ui->Published_year->setText(year.at(currentRow));
}


void book_edit::on_Update_clicked()
{
    QString temp = ui->Namebook->text();
    int index = ui->Book_list->currentRow();
    if(temp!=NULL){
        book.replace(index,temp);
        temp = ui->Author->text();
        author.replace(index,temp);
        temp = ui->Published_year->text();
        year.replace(index,temp);
    }
    //Qlistwidgetitem must be enabled or editable throughh flag so that it will not crash the program
    QListWidgetItem *a=ui->Book_list->currentItem();
    a->setFlags(a->flags() | Qt::ItemIsEnabled);
    a->setText(book.at(index));
    ui->Book_list->editItem(a);

}



void book_edit::on_pushButton_clicked()
{
    readfile write;
    write.write_book_database(&book,&author,&year);
    searchbook *search_book= new searchbook;
    search_book->show_window("admin");
    this->close();

}

void book_edit::on_mode_currentIndexChanged(int index)
{
    if(index==0){
        ui->addnew->hide();
        ui->Update->show();
    }else{
        ui->addnew->show();
        ui->Update->hide();
        ui->Namebook->clear();
        ui->Author->clear();
        ui->Published_year->clear();
    }
}

void book_edit::on_addnew_clicked()
{
    QString temp = ui->Namebook->text();
    QListWidgetItem *a = new QListWidgetItem();
    a->setText(temp);
    ui->Book_list->insertItem(0,a);
    ui->Book_list->setCurrentRow(0);

    book.push_back(temp);

    temp = ui->Author->text();
    author.push_back(temp);
    temp = ui->Published_year->text();
    year.push_back(temp);

}
