#include "sign_login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sign_Login w;
    w.show();

    return a.exec();
}
