#ifndef READFILE_H
#define READFILE_H
#include <QStringList>
#include <fstream>
#include <iostream>
#include <QTreeWidget>
typedef struct{
    QString name, b_day, r_day;
}QStringbook;

class readfile
{
public:
    readfile();
    void getbookdatabase(QStringList*,QStringList*);
    void get_book_database(QStringList *book, QStringList *author, QStringList *year);
    void write_book_database(QStringList *book, QStringList *author, QStringList *year);
    std::vector<QStringbook>getbook();
private:
    QStringList book, author;
};

#endif // READFILE_H
