#include "testdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestDialog w;
    w.show();

    return a.exec();
}
