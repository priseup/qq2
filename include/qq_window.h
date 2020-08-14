#ifndef QQ_WINDOW_H
#define QQ_WINDOW_H

#include <QDialog>
#include "sqlite3.h"

namespace Ui {
class qq_window;
}

class qq_window : public QDialog
{
    Q_OBJECT

public:
    explicit qq_window(QWidget *parent = 0);
    ~qq_window();

private:
    Ui::qq_window *ui;

    sqlite3 *db_handle = nullptr;
    sqlite3_stmt *db_sql = nullptr;
};

#endif // QQ_WINDOW_H
