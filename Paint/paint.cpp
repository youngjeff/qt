
#include"paint.h"
#include<QtGui>
#include <QVBoxLayout>
#define COUNTRANGE 20
paint::paint(QWidget*parent):QWidget(parent)
{
    level=1;
    speed=200;
    init();
    setWindowTitle("little snake v0.2");
    timer=new QTimer;
    timer->start(speed);
    connect(timer,SIGNAL(timeout()),this,SLOT(autorun()));
    setFixedSize(360,410);
    progress=new QProgressBar;
    progress->setRange(0,COUNTRANGE);
    progress->setValue(count);
    progress->setOrientation(Qt::Horizontal);
    QVBoxLayout *main=new QVBoxLayout;
    main->addStretch(2);
    main->addWidget(progress);
    setLayout(main);

}

paint::~paint(){}

void paint::init()
{
    count=0;
    length=4;
    randsuanzi=0;
    jiou=0;
    dir=Up;
    res=Ready;
    snake[0][0]=20*1;
    snake[0][1]=20*13;
    snake[1][0]=20*1;
    snake[1][1]=20*14;
    snake[2][0]=20*1;
    snake[2][1]=20*15;
    snake[3][0]=20*1;
    snake[3][1]=20*16;

    food[0]=(getrandnum()+1)*20;
    food[1]=(getrandnum()+1)*20;
        for(int i=0;i<length;++i)
        {
            if(level%2)
            {
                if((food[0]-snake[i][0]==0)
                    &&(food[1]-snake[i][1]==0))
                {
                    food[0]=(getrandnum()+1)*20;
                    food[1]=(getrandnum()+1)*20;
                    i=-1;
                    continue;
                }
            }
            else
            {
                if(((food[0]==snake[i][0])&&(food[1]==snake[i][1]))
                        ||((food[0]==5*20)&&(food[1]>=7*20)&&(food[1]<=10*20))
                        ||((food[0]==12*20)&&(food[1]>=7*20)&&(food[1]<=10*20))
                        ||((food[1]==5*20)&&(food[0]>=7*20)&&(food[0]<=10*20))
                        ||((food[1]==12*20)&&(food[0]>=7*20)&&(food[0]<=10*20)))
                {
                    food[0]=(getrandnum()+1)*20;
                    food[1]=(getrandnum()+1)*20;
                    i=-1;
                    continue;
                }
            }
        }
}
int paint::getrandnum()
{
    randsuanzi++;
    srand(time(0)+randsuanzi);
    if(randsuanzi>9999)
        randsuanzi=0;
    return rand()%16;//0~15
}
void paint::paintEvent(QPaintEvent* )
{
    QPainter p(this);
        QRectF border(20-20,20-20,16*20+40,16*20+40);
        QRectF inter(20,20,16*20,16*20);
        p.setPen(Qt::NoPen);
    if(level%2)
    {
        p.setBrush(QBrush(Qt::darkGreen,Qt::SolidPattern));
    }
    else
    {
        p.setBrush(QBrush(Qt::darkCyan,Qt::SolidPattern));
    }
        p.drawRect(border);
        p.setBrush(QBrush(Qt::lightGray,Qt::SolidPattern));
        p.drawRect(inter);
        p.setPen(QPen(Qt::darkGray,1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
        p.setBrush(QBrush(Qt::green));
        QRectF snakehead(snake[0][0],snake[0][1],20,20);
        p.drawRoundRect(snakehead);

        QRectF snakefood(food[0],food[1],20,20);
        p.setBrush(QBrush(Qt::darkRed));
        p.drawEllipse(snakefood);

        for(int i=1;i<length;++i)
        {
            QRectF snakebody(snake[i][0],snake[i][1],20,20);
            p.setBrush(QBrush(Qt::red));
            p.drawRoundRect(snakebody);
        }
        QRectF levelinfo(12*20,20,80,20);
        if(level%2)
        {
            p.setPen(QPen(Qt::darkGreen));
        }
        else
        {
            p.setPen(QPen(Qt::darkCyan));
        }
        QString levelnum=QString::number(level,10);
        QString levelstr="level ";
        levelstr.append(levelnum);
        p.drawText(levelinfo,Qt::AlignRight,levelstr);

        QRectF xiaolei(9*20,0,8*20,20);
        p.setPen(QPen(Qt::lightGray));
        p.drawText(xiaolei,Qt::AlignRight,"made by kanglei");


    if(!(level%2))
    {
        QRectF block1(5*20,7*20,20,4*20);
        p.setBrush(QBrush(Qt::darkCyan));
        p.drawRect(block1);
        QRectF block2(7*20,5*20,4*20,20);
        p.setBrush(QBrush(Qt::darkCyan));
        p.drawRect(block2);
        QRectF block3(12*20,7*20,20,4*20);
        p.setBrush(QBrush(Qt::darkCyan));
        p.drawRect(block3);
        QRectF block4(7*20,12*20,4*20,20);
        p.setBrush(QBrush(Qt::darkCyan));
        p.drawRect(block4);
        QRectF block_add1(0,8*20,20,40);
        p.setBrush(QBrush(Qt::lightGray));
        p.drawRect(block_add1);
        QRectF block_add2(17*20,8*20,20,40);
        p.setBrush(QBrush(Qt::lightGray));
        p.drawRect(block_add2);
        QRectF block_add3(8*20,0,40,20);
        p.setBrush(QBrush(Qt::lightGray));
        p.drawRect(block_add3);
        QRectF block_add4(8*20,17*20,40,20);
        p.setBrush(QBrush(Qt::lightGray));
        p.drawRect(block_add4);
    }
    if(res==Ready)
    {
        p.setFont(QFont("",16,16));
        p.setPen(QPen(Qt::yellow,60));
        QRectF text(50,50,16*20-50,16*20-50);
        p.drawText(text,Qt::AlignCenter,"Ready?\nPress Space start");
    }
    if(res==Lose)
    {
            p.setFont(QFont("",16,16));
            p.setPen(QPen(Qt::yellow,60));
            QRectF text(50,50,16*20-50,16*20-50);
            p.drawText(text,Qt::AlignCenter,"LOSE!!\nPress Space restart");
    }
    if(res==Win)
    {
        p.setFont(QFont("",16,16));
        p.setPen(QPen(Qt::yellow,60));
        QRectF text(50,50,16*20-50,16*20-50);
        p.drawText(text,Qt::AlignCenter,"WIN!!");
    }
    if((res==Normal)&&(jiou))
    {
        p.setFont(QFont("",16,16));
        p.setPen(QPen(Qt::yellow,60));
        QRectF text(50,50,16*20-50,16*20-50);
        p.drawText(text,Qt::AlignCenter,"Pause");
    }
}

void paint::keyPressEvent(QKeyEvent* keyevent)
{
    switch(keyevent->key())
    {
        case Qt::Key_Up:
            dir=Up;
            break;
        case Qt::Key_Down:
            dir=Down;
            break;
        case Qt::Key_Left:
            dir=Left;
            break;
        case Qt::Key_Right:
            dir=Right;
            break;
        case Qt::Key_Space:
            if(res==Ready)//start
            {
                res=Normal;
                break;
            }
            if(res==Lose)//restart
            {
                init();
                progress->setValue(count);
                update();
                break;
            }
            if(res==Normal)//pause
            {
                if(!jiou)
                {
                    timer->stop();
                    jiou=1;
                }
                else
                {
                    timer->start();
                    jiou=0;
                }
                update();
                break;
            }
    }
}
void paint::autorun()
{
if(res==Normal)
{
    int temp[2];
    temp[0]=snake[length-1][0];
    temp[1]=snake[length-1][1];
    for(int i=length-1;i>0;--i)
    {
        snake[i][0]=snake[i-1][0];
        snake[i][1]=snake[i-1][1];
    }
    if(dir==Up)
    {
        snake[0][1]-=20;
        if(snake[0][1]==snake[2][1])
        {
            snake[0][1]+=40;
        }
        if(snake[0][1]<20||snake[0][1]>16*20)
        {
            if(level%2)//1,3,5...
                res=Lose;
            else
            {
                if(((snake[0][0]==8*20)
                            ||(snake[0][0]==9*20))
                            &&(snake[0][1]==0))
                {
                    snake[0][1]=16*20;
                }
                else if(((snake[0][0]==8*20)
                            ||(snake[0][0]==9*20))
                        &&(snake[0][1]==17*20))
                {
                    snake[0][1]=20;
                }
                else
                    res=Lose;
            }
        }
    }
    if(dir==Down)
    {
        snake[0][1]+=20;
        if(snake[0][1]==snake[2][1])
        {
            snake[0][1]-=40;
        }
        if(snake[0][1]<20||snake[0][1]>16*20)
        {
            if(level%2)
                res=Lose;
            else
            {
                if(((snake[0][0]==8*20)
                            ||(snake[0][0]==9*20))
                            &&(snake[0][1]==0))
                {
                    snake[0][1]=16*20;
                }
                else if(((snake[0][0]==8*20)
                            ||(snake[0][0]==9*20))
                        &&(snake[0][1]==17*20))
                {
                    snake[0][1]=20;
                }
                else
                    res=Lose;
            }
        }
    }
    if(dir==Left)
    {
        snake[0][0]-=20;
        if(snake[0][0]==snake[2][0])
        {
            snake[0][0]+=40;
        }
        if(snake[0][0]<20||snake[0][0]>16*20)
        {
            if(level%2)
                res=Lose;
            else
            {
                if(((snake[0][1]==8*20)
                            ||(snake[0][1]==9*20))
                        &&(snake[0][0]==0))
                {
                    snake[0][0]=16*20;
                }
                else if(((snake[0][1]==8*20)
                            ||(snake[0][1]==9*20))
                        &&(snake[0][0]==17*20))
                {
                    snake[0][0]=20;
                }
                else
                    res=Lose;
            }
        }
    }
    if(dir==Right)
    {
        snake[0][0]+=20;
        if(snake[0][0]==snake[2][0])
        {
            snake[0][0]-=40;
        }
        if(snake[0][0]<20||snake[0][0]>16*20)
        {
            if(level%2)
                res=Lose;
            else
            {
                if(((snake[0][1]==8*20)
                            ||(snake[0][1]==9*20))
                        &&(snake[0][0]==0))
                {
                    snake[0][0]=16*20;
                }
                else if(((snake[0][1]==8*20)
                            ||(snake[0][1]==9*20))
                        &&(snake[0][0]==17*20))
                {
                    snake[0][0]=20;
                }
                else
                    res=Lose;
            }
        }
    }
    for(int i=1;i<length;++i)
    {
        if((snake[0][0]-snake[i][0]==0)\
                &&(snake[0][1]-snake[i][1]==0))
        {
            res=Lose;
        }
    }
    if(!(level%2))//2,4,6....
    {
        if((snake[0][0]==5*20)
            &&(snake[0][1]>=7*20)
                    &&(snake[0][1]<=10*20))
        {
            res=Lose;
        }
        if((snake[0][0]==12*20)
            &&(snake[0][1]>=7*20)
                    &&(snake[0][1]<=10*20))
        {
            res=Lose;
        }
        if((snake[0][1]==5*20)
            &&(snake[0][0]>=7*20)
                    &&(snake[0][0]<=10*20))
        {
            res=Lose;
        }
        if((snake[0][1]==12*20)
            &&(snake[0][0]>=7*20)
                    &&(snake[0][0]<=10*20))
        {
            res=Lose;
        }
    }
    if((snake[0][0]==food[0])&&(snake[0][1]==food[1]))
    {
        count++;
        progress->setValue(count);
        length++;
        snake[length-1][0]=temp[0];
        snake[length-1][1]=temp[1];
        food[0]=(getrandnum()+1)*20;
        food[1]=(getrandnum()+1)*20;
        for(int i=0;i<length;++i)
        {
            if(level%2)
            {
                if((food[0]-snake[i][0]==0)\
                        &&(food[1]-snake[i][1]==0))
                {
                    food[0]=(getrandnum()+1)*20;
                    food[1]=(getrandnum()+1)*20;
                    i=-1;
                    continue;
                }
            }
            else
            {
                if(((food[0]==snake[i][0])&&(food[1]==snake[i][1]))
                        ||((food[0]==5*20)&&(food[1]>=7*20)&&(food[1]<=10*20))
                        ||((food[0]==12*20)&&(food[1]>=7*20)&&(food[1]<=10*20))
                        ||((food[1]==5*20)&&(food[0]>=7*20)&&(food[0]<=10*20))
                        ||((food[1]==12*20)&&(food[0]>=7*20)&&(food[0]<=10*20)))
                {
                    food[0]=(getrandnum()+1)*20;
                    food[1]=(getrandnum()+1)*20;
                    i=-1;
                    continue;
                }
            }
        }
        if(count>=COUNTRANGE)
        {
            level++;
            if(level%2)
                speed=speed-50;
            if(speed<=0)
                speed=20;
            timer->start(speed);
            init();
            progress->setValue(count);
        }
    }
    update();
}
}
