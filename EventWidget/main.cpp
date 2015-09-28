#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//qt的事件循环
    Widget w;
    w.show();

    return a.exec();
}
