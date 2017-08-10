#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
private slots:

    void on_loginbutton_clicked() ;

    void on_logonbutton_clicked();

    void on_pwd_returnPressed();

private:
    Ui::login *ui;
    QString username,password;
};

#endif // LOGIN_H
