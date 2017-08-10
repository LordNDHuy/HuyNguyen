#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H
#include <QStringList>
#include <string>
#include <QWidget>
#include <iostream>
#include "login.h"
#include "userpage.h"
#include <QScrollBar>
namespace Ui {
class searchbook;
}

class searchbook : public QWidget
{
    Q_OBJECT

public:
     explicit searchbook(QWidget *parent = 0);
    ~searchbook();
    ///
     void set_username(std::string newname){
        username = newname;
        std::cout <<"huynguyen        "<<username<<std::endl;
     }
     void show_window(std::string);
     void filter_book(QStringList *filtered, QStringList *list_1, QStringList *list_2,unsigned int pass);
private slots:
    void on_bookname_clicked(const QModelIndex &index);

    void on_author_clicked(const QModelIndex &index);

    void on_searchbutton_clicked();

    void on_searchbox_returnPressed();

    void on_Login_clicked();

    void on_Logon_clicked();

    void on_borrow_clicked();

    void on_user_page_currentIndexChanged(int index);

    void on_year_clicked(const QModelIndex &index);

    void on_spinBox_valueChanged(int arg1);

    void initialize();
    void on_edit_clicked();

private:
    QScrollBar *name_scrollbar;
    Ui::searchbook *ui;
    QStringList book, author,year;
    std::string username;
    login account;

};

#endif // SEARCHBOOK_H
