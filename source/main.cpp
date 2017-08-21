#include "account_management.h"
#include <QApplication>
#include "book_search.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Book_search w;
    w.show();

    return a.exec();
}
