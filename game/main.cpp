#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QThread>
#include "mywidget.h"

int main(int argc,char* argv[])
{
    QApplication a(argc,argv);
    //QApplication::addLibraryPath("./plugins");
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/new/prefix1/splash.jpg"));
    splash->setStyleSheet("font-size:16px;font-weight:480");
    splash->showMessage(QObject::tr("   独立云山，长风满袖。\n\n"
                                    "   南国春秋，记逢前缘。\n\n"
                                    "   江湖俪影，青山踏遍，不负风流。\n\n"
                                    "   截波百回，绝域万里，一剑光寒动神州。\n\n"
                                    "   算而今，是陈缘未了，情怀依旧。\n\n"
                                    "   重寻碧落茫茫，笑江湖浪迹十年游。\n\n"
                                    "   只浮萍随水，逝水随风。\n\n"
                                    "   哀弦英续，好梦难留。\n\n"
                                    "   惊鸿掠水，波荡无痕，却道爱恨总难休。\n\n"
                                    "   凝伫久，向回首，思渺难收。\n\n\n"
                                    "   程序正在启动中，请耐心等待..........\n"
                                    "   <小贴士：能量超过50才可以使用技能哦^_^>"),Qt::AlignLeft|Qt::AlignVCenter,QColor(184,7,235,150));
    splash->show();
    QThread::sleep(5);
    splash->showMessage(QObject::tr("   独立云山，长风满袖。\n\n"
                                    "   南国春秋，记逢前缘。\n\n"
                                    "   江湖俪影，青山踏遍，不负风流。\n\n"
                                    "   截波百回，绝域万里，一剑光寒动神州。\n\n"
                                    "   算而今，是陈缘未了，情怀依旧。\n\n"
                                    "   重寻碧落茫茫，笑江湖浪迹十年游。\n\n"
                                    "   只浮萍随水，逝水随风。\n\n"
                                    "   哀弦英续，好梦难留。\n\n"
                                    "   惊鸿掠水，波荡无痕，却道爱恨总难休。\n\n"
                                    "   凝伫久，向回首，思渺难收。\n\n\n"
                                    "   启动完成正在配置中，请等待...........\n"
                                    "   <小贴士：能量超过50才可以使用技能哦^_^>"),Qt::AlignLeft|Qt::AlignVCenter,QColor(184,7,235,150));
    QThread::sleep(5);
    myWidget w;
    w.show();
    splash->finish(&w);
    delete splash;
    return a.exec();
}
