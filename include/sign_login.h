#ifndef SIGN_LOGIN_H
#define SIGN_LOGIN_H

#include <QMainWindow>
#include "sqlite3.h"

namespace Ui {
class Sign_Login;
}

class Sign_Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sign_Login(QWidget *parent = 0);
    ~Sign_Login();

private:
    bool user_exist(const std::string &name, const std::string &password);

private slots:
    void on_sign_clicked();

    void on_login_clicked();

private:
    Ui::Sign_Login *ui;

    sqlite3 *db_handle = nullptr;
    sqlite3_stmt *db_sql = nullptr;
};


#endif // SIGN_LOGIN_H
