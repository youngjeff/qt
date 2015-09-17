#include "widget.h"
#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow login;
    login.show();

    //Widget w;
    //w.show();

    return a.exec();
}
