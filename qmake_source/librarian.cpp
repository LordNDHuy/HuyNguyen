#include "librarian.h"
#include "ui_librarian.h"

librarian::librarian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::librarian)
{
    ui->setupUi(this);
}

librarian::~librarian()
{
    delete ui;
}


void librarian::on_Book_section_clicked()
{

}
