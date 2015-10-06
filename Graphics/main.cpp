#include "widget.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0,0,300,300);
    scene.addLine(0,0,150,150);
    scene.addEllipse(50,50,200,100);

    QGraphicsView view(&scene);
    view.setWindowTitle("Graphics view");
//    view.resize(500,500);
    view.show();

//    Widget w;
//    w.show();

    return a.exec();
}
//mvc框架 scene是场景,line是元素item,view是视图
