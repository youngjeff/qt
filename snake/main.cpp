#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    QMessageBox::information(&w,"tips","欢迎来到贪吃蛇",QMessageBox::Ok);

    
    return a.exec();
}
