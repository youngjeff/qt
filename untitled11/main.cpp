#include "widget.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
