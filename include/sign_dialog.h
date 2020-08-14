#ifndef SIGN_DIALOG_H
#define SIGN_DIALOG_H

#include <QDialog>

namespace Ui {
class Sign_Dialog;
}

class Sign_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Sign_Dialog(QWidget *parent = 0);
    ~Sign_Dialog();

    void get_sign_info(std::string &name,
                       std::string &password,
                       int &age);

private slots:
    void on_ok_clicked();

private:
    Ui::Sign_Dialog *ui;
};

#endif // SIGN_DIALOG_H
