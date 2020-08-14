#include <string>
#include "sign_dialog.h"
#include "ui_sign_dialog.h"

Sign_Dialog::Sign_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_Dialog)
{
    ui->setupUi(this);
}

Sign_Dialog::~Sign_Dialog()
{
    delete ui;
}

void Sign_Dialog::on_ok_clicked()
{
    this->close();
}

void Sign_Dialog::get_sign_info(std::string &name,
                              std::string &password,
                              int &age)
{
   name = ui->name_content->toPlainText().toStdString();
   password = ui->password_content->toPlainText().toStdString();
   age = ui->age_content->toPlainText().toInt();
}
