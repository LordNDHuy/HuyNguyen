#ifndef ACCOUNT_MANAGEMENT_H
#define ACCOUNT_MANAGEMENT_H

#include <QMainWindow>

#include "Account.h"
#include "UsrInfo.h"
#include <QString>


#include "login.h"

typedef struct{
    QStringList User_name;
    std::vector<unsigned int> Uid;
}QS_user;
typedef struct{
    std::string accname;
    unsigned int Aid;
}QS_acc;
namespace Ui {
class Account_management;
}

class Account_management : public QMainWindow
{
    Q_OBJECT

public:
    explicit Account_management(QWidget *parent = 0);
    ~Account_management();
    void get_username();
    void update_remove();
    void receive(UsersMgr,AccountsMgr,Account);
private slots:
    void on_option_currentIndexChanged(int index);
    void on_Register_clicked();

    void on_occu_returnPressed();

    void on_Username_list_currentTextChanged(const QString &currentText);

    void on_Search_Box_textChanged(const QString &arg1);

    void on_add_clicked();

    void on_remove_clicked();

    void get_UID(unsigned int&);
    void on_Remove_u_clicked();

    void on_pushButton_clicked();

    void on_change_pas_clicked();

    void on_edit_user_pass_clicked();

    void on_acc_list_currentTextChanged(const QString &currentText);

    void on_back_clicked();

    void on_reset_pwd_clicked();

private:
    Ui::Account_management *ui;
    UsersMgr user;
    AccountsMgr account;
    Account login_acc;
    QS_user *search_list = new QS_user();
    std::vector<QS_acc> remove_list;
    //
    QString current_acc_list_item;
};

#endif // ACCOUNT_MANAGEMENT_H
