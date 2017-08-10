#ifndef LOGIN_NOTIFICATION_H
#define LOGIN_NOTIFICATION_H

#include <QDialog>

namespace Ui {
class login_notification;
}

class login_notification : public QDialog
{
    Q_OBJECT

public:
    explicit login_notification(QWidget *parent = 0);
    ~login_notification();

private:
    Ui::login_notification *ui;
};

#endif // LOGIN_NOTIFICATION_H
