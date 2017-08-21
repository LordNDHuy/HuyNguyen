#ifndef BOOK_SEARCH_H
#define BOOK_SEARCH_H

#include <QWidget>
#include "Book.h"
#include "Account.h"
#include "UsrInfo.h"
#include "edit_book.h"
#include "account_management.h"
#include "login.h"
#include "Request.h"
enum user {user_name = 0 , user_page ,logout };
namespace Ui {
class Book_search;
}

class Book_search : public QWidget
{
    Q_OBJECT

public:
    explicit Book_search(QWidget *parent = 0);
    ~Book_search();
    void update_list();
    void receive(Account);
private slots:
    void on_edit_clicked();

    void on_user_page_currentIndexChanged(int index);

    void on_searchbox_textChanged(const QString &arg1);

    void on_bookname_currentRowChanged(int currentRow);

    void on_author_currentRowChanged(int currentRow);

    void on_type_currentRowChanged(int currentRow);

    void on_Login_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_searchmethod_currentIndexChanged(int index);

    void on_borrow_clicked();

    void on_bookname_currentTextChanged(const QString &currentText);

private:
    Ui::Book_search *ui;
    BooksCase book_list;
    Account login_acc;
    UsersMgr user;
    AccountsMgr account;
    Request request;

    int count_the_no_book;
    QString search_book;
};

#endif // BOOK_SEARCH_H
