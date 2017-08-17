#include "account_management.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Account_management w;
    w.show();

    return a.exec();
}
