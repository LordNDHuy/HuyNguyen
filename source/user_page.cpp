#include "user_page.h"
#include "ui_user_page.h"

user_page::user_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_page)
{
    ui->setupUi(this);
}

user_page::~user_page()
{
    delete ui;
}
