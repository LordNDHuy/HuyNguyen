#include "mainwindow.h"
#include <QApplication>
#include "readfile.h"
#include <QStringList>
#include "searchbook.h"
#include "readfile.h"
#include <QTreeWidget>
const std::string pwd = "admin";
const std::string usr = "admin";
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    searchbook search_window;
    search_window.show_window("anno");
    search_window.move(200,100);
    return a.exec();


}
