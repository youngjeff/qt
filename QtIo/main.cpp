#include "iowidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IoWidget w;
    w.show();

    return a.exec();
}
