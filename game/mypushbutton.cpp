#include <QtMultimedia/QMediaPlayer>
#include <QPushButton>
#include "mypushbutton.h"

myPushButton::myPushButton(const QString &text,QWidget *parent) :
    QPushButton(text,parent)
{
    player=new QMediaPlayer(this);
    cursor=new QCursor(QPixmap(":/new/prefix1/test.png"));
    setCursor(*cursor);
}

myPushButton::myPushButton(QWidget *parent) :
    QPushButton(parent)
{
    player=new QMediaPlayer(this);
    cursor=new QCursor(QPixmap(":/new/prefix1/test.png"));
    setCursor(*cursor);
}

myPushButton::myPushButton(const QString &text) :
    QPushButton(text,0)
{
    player=new QMediaPlayer(this);
    cursor=new QCursor(QPixmap(":/new/prefix1/test.png"));
    setCursor(*cursor);
}

void myPushButton::enterEvent(QEvent *)
{
    //鼠标进入按钮播放音效->(开始)
    player->setMedia(QUrl("qrc:/new/prefix1/PICKUP.WAV"));
    player->setVolume(200);
    player->play();
    //鼠标进入按钮播放音效<-(结束)
}

void myPushButton::leaveEvent(QEvent *)
{
    player->stop();
}
