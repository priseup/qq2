#include <string>
#include <unistd.h>
#include "sign_login.h"
#include "ui_sign_login.h"
#include "sign_dialog.h"
#include "tips_dialog.h"
#include "qq_window.h"

Sign_Login::Sign_Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sign_Login)
{
    ui->setupUi(this);

    sqlite3_open("qq.db", &db_handle);

    const char *my_info = "user_info";
    const char *my_friend = "friend";

    std::string sql = "SELECT count(*) FROM sqlite_master WHERE type='table' AND name=?";
    if (SQLITE_OK != sqlite3_prepare_v2(db_handle, sql.c_str(), -1, &db_sql, nullptr))
    {
        exit(0);
    }
    if (SQLITE_OK != sqlite3_bind_text(db_sql, 1, my_info, -1, NULL))
    {
        exit(0);
    }
    if (SQLITE_ROW != sqlite3_step(db_sql))
    {
        exit(0);
    }
    if (sqlite3_column_int(db_sql, 0) == 0)
    {
        sqlite3_exec(db_handle,
                     "create table user_info \
                        (id INTEGER PRIMARY KEY AUTOINCREMENT,   \
                        password text not null, \
                        name text not null,\
                        age int not null)",
                     NULL, NULL, NULL);
    }

    sqlite3_reset(db_sql);

    sqlite3_bind_text(db_sql, 1, my_friend, -1, NULL);
    if (SQLITE_ROW != sqlite3_step(db_sql))
    {
        exit(0);
    }
    if (sqlite3_column_int(db_sql, 0) == 0)
    {
        sqlite3_exec(db_handle,
                     "create table friend \
                        (id int primary key not null, \
                         f_id int)",
                     NULL, NULL, NULL);
    }
    sqlite3_finalize(db_sql);
    db_sql = nullptr;
}

Sign_Login::~Sign_Login()
{
    delete ui;

    if (db_sql)
        sqlite3_finalize(db_sql);

    sqlite3_close(db_handle);
}

bool Sign_Login::user_exist(const std::string &name, const std::string &password)
{
    std::string query("select count(*) from user_info where name = ? and password = ?");
    sqlite3_prepare_v2(db_handle, query.c_str(), query.size(), &db_sql, nullptr);
    sqlite3_bind_text(db_sql, 1, name.c_str(), -1, NULL);
    sqlite3_bind_text(db_sql, 2, password.c_str(), -1, NULL);

    std::string ex_sql = sqlite3_expanded_sql(db_sql);
    sqlite3_step(db_sql);

    int row_count = sqlite3_column_int(db_sql, 0);
    bool r = row_count == 1;

    sqlite3_finalize(db_sql);
    db_sql = nullptr;

    return r;
}

void Sign_Login::on_sign_clicked()
{
    Sign_Dialog sign;

    std::string name;
    std::string password;
    int age;

    if (sign.exec() == 0)
        sign.get_sign_info(name, password, age);

    if (user_exist(name, password))
        return ;

    std::string insert("insert into user_info \
                    (password, name, age) values (?, ?, ?)");

    sqlite3_prepare_v2(db_handle, insert.c_str(), insert.size(), &db_sql, nullptr);
    sqlite3_bind_text(db_sql, 1, password.c_str(), password.length(), NULL);
    sqlite3_bind_text(db_sql, 2, name.c_str(), name.length(), NULL);
    sqlite3_bind_int(db_sql, 3, age);

    sqlite3_step(db_sql);
    sqlite3_finalize(db_sql);

    db_sql = nullptr;
}

void Sign_Login::on_login_clicked()
{
    std::string name = ui->name_content->toPlainText().toStdString();
    std::string password = ui->password_content->toPlainText().toStdString();

    if (!user_exist(name, password))
    {
        Tips_Dialog info;
        info.set_output_info("no user id");
        info.exec();
    }
    else
    {
        this->close();
        qq_window qq_win;
        qq_win.exec();
        // info.set_output_info("login success");
        // info.exec();
    }
}
