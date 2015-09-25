// --------------------------------------------------
// Project created by freedomxura 2009-05-27T09:15:17
// The Qt version is Qt 4.5.1
// --------------------------------------------------

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // button->setIcon(QIcon("1.ico"));
    w.show();
    return a.exec();
}
