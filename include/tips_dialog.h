#ifndef TIPS_DIALOG_H
#define TIPS_DIALOG_H

#include <QDialog>

namespace Ui {
class Tips_Dialog;
}

class Tips_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Tips_Dialog(QWidget *parent = 0);
    ~Tips_Dialog();

    void set_output_info(const std::string &s);

private slots:
    void on_ok_button_clicked();

private:
    Ui::Tips_Dialog *ui;
};

#endif // TIPS_DIALOG_H
