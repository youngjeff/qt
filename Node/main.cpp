#include "widget.h"
#include <QApplication>
#include "booleanwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BooleanWindow w;
    w.show();

    return a.exec();
}
