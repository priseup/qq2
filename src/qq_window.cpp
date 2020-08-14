#include "qq_window.h"
#include "ui_qq_window.h"

qq_window::qq_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qq_window)
{
    ui->setupUi(this);

    // ui->chats_list->addAction();
    // ui->conntacts_list->
}

qq_window::~qq_window()
{
    delete ui;
}
