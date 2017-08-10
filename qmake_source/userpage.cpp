#include "userpage.h"
#include "ui_userpage.h"
#include "readfile.h"
#include <QTreeWidget>

userpage::userpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userpage)
{
    ui->setupUi(this);
    ui->username->setReadOnly(true);
    ui->username->setText(tr("I'm the best"));
    //ui->book_status->setItemText(0,"Borrowed book List");
    //ui->book_status->setItemText(1,"Requested book List");
    std::vector<QStringbook> book;

    readfile bookget;
    book = bookget.getbook();
    ui->treeWidget->setColumnCount(3);
    QStringList headerlabel;
    headerlabel.push_back(tr("Book name"));
    headerlabel.push_back(tr("Borrow day"));
    headerlabel.push_back(tr("Due Day"));
    ui->treeWidget->setColumnWidth(0,200);
    ui->treeWidget->setColumnCount(headerlabel.count());
    ui->treeWidget->setHeaderLabels(headerlabel);
    for(int i = 0 ;i<book.size();i++){
        QTreeWidgetItem* temp = new QTreeWidgetItem();
        temp->setText(0,(book[i].name));
        temp->setText(1,(book[i].b_day));
        temp->setText(2,(book[i].r_day));
        ui->treeWidget->addTopLevelItem(temp);
    }
}

userpage::~userpage()
{
    delete ui;
}
