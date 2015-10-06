#include "widget.h"
#include <QApplication>
#include "mainwindow.h"
#include "review.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow login;
    login.show();


//    Review r;
//    r.show();
    return a.exec();
}
