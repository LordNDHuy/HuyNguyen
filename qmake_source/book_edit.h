#ifndef BOOK_EDIT_H
#define BOOK_EDIT_H

#include <QWidget>

namespace Ui {
class book_edit;
}

class book_edit : public QWidget
{
    Q_OBJECT

public:
    explicit book_edit(QWidget *parent = 0);
    ~book_edit();
    void edit(QStringList *book,QStringList *author,QStringList *year);
private slots:


    void on_Book_list_currentRowChanged(int currentRow);

    void on_Update_clicked();


    void on_pushButton_clicked();


    void on_mode_currentIndexChanged(int index);

    void on_addnew_clicked();

private:
    Ui::book_edit *ui;
    QStringList book, author,year;

};

#endif // BOOK_EDIT_H
