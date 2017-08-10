#include "login_notification.h"
#include "ui_login_notification.h"

login_notification::login_notification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_notification)
{
    ui->setupUi(this);
}

login_notification::~login_notification()
{
    delete ui;
}
