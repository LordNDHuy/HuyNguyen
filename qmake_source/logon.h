#ifndef LOGON_H
#define LOGON_H

#include <QWidget>
#include <fstream>
#include "login.h"
namespace Ui {
class logon;
}

class logon : public QWidget
{
    Q_OBJECT

public:
    explicit logon(QWidget *parent = 0);
    ~logon();

private slots:
    void on_pushButton_clicked();

    void on_password_returnPressed();

private:
    Ui::logon *ui;
};

#endif // LOGON_H
