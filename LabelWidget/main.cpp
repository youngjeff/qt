#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    a.installEventFilter(new EventFilter(&w,&w));//安装installeventfilter过滤器
    w.show();

    return a.exec();
}
//QApplication::eventFilter
//eventFilter
//event
//mousePressEvent
//首先是application的eventfilter函数,之后是控件的eventFilter事件过滤函数,然后是event事件对象
//所有对象的事件入口，QObject 和 QWidget 中的实现，默认是把事件传递给特定的事件处理函数。
//事件处理函数。这是最普通、最简单的形式，同时功能也最简单最低的层次
