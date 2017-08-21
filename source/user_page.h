#ifndef USER_PAGE_H
#define USER_PAGE_H

#include <QWidget>

namespace Ui {
class user_page;
}

class user_page : public QWidget
{
    Q_OBJECT

public:
    explicit user_page(QWidget *parent = 0);
    ~user_page();

private:
    Ui::user_page *ui;
};

#endif // USER_PAGE_H
