#include<QApplication>
#include"paint.h"
int main(int argc,char**argv)
{
    QApplication app(argc,argv);
    paint *sb=new paint;
    sb->show();
    return app.exec();
}
