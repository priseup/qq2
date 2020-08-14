#include <string>
#include "tips_dialog.h"
#include "ui_tips_dialog.h"

Tips_Dialog::Tips_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tips_Dialog)
{
    ui->setupUi(this);
}

Tips_Dialog::~Tips_Dialog()
{
    delete ui;
}

void Tips_Dialog::on_ok_button_clicked()
{
    this->close();
}

void Tips_Dialog::set_output_info(const std::string &s)
{
    ui->output_info->setPlainText(s.c_str());
}
