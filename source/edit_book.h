#ifndef EDIT_BOOK_H
#define EDIT_BOOK_H
#include "Book.h"
#include "book_search.h"
#include <QWidget>
#include <regex>
#include "Request.h"
#include "Account.h"
enum mode {add = 0, edit ,remove_book};

namespace Ui {
class edit_book;
}

class edit_book : public QWidget
{
    Q_OBJECT

public:
    explicit edit_book(QWidget *parent = 0);
    ~edit_book();
    void receiver(BooksCase,Account,Request,AccountsMgr);
    void update_list();
    void update_list_edit();
    void update_list_request();

private slots:
    void on_addnew_clicked();


    void on_Update_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_remove_clicked();

    void on_search_edit_textChanged(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void on_Book_list_edit_currentTextChanged(const QString &currentText);

    void on_pushButton_clicked();

    void on_re_name_currentRowChanged(int currentRow);

    void on_re_acc_currentRowChanged(int currentRow);

    void on_re_status_currentRowChanged(int currentRow);

    void on_accept_clicked();

    void on_deny_clicked();

private:
    Ui::edit_book *ui;
    BooksCase book_list;

    std::vector<Book> Search_list;
    Account log_acc;
    Request request;
    AccountsMgr account;

    std::vector<unsigned int> Ticketsid;
    QString current_book_re;

};

#endif // EDIT_BOOK_H
