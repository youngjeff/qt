#include <QEvent>
#include <QKeyEvent>
#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include "tipwidget.h"
#include "myview.h"

tipWidget::tipWidget(QWidget *parent,myView *view) :
    QWidget(parent)
{
    cursor=new QCursor(QPixmap(":/new/prefix1/test.png"));
    setCursor(*cursor);
    this->view=view;
    installWindow();

    isGame=false;
    setLayout(vboxLayout1);
    //setWindowFlags(Qt::FramelessWindowHint);
   // setAttribute(Qt::WA_TranslucentBackground);
    setContentsMargins(0,0,0,0);
    setGeometry(78,284,112,200);
    show();
    view->installEventFilter(this);
}

void tipWidget::installWindow()
{
    //设置按键提示按钮、安装在view上、并且在widget上显示
    buttonLayout=new QGridLayout;
    upBtn=new QPushButton(tr("↑"));
    downBtn=new QPushButton(tr("↓"));
    leftBtn=new QPushButton(tr("←"));
    rightBtn=new QPushButton(tr("→"));

    upBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    downBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    leftBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    rightBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");

    buttonLayout->addWidget(upBtn,0,1,1,1);
    buttonLayout->addWidget(leftBtn,1,0,1,1);
    buttonLayout->addWidget(downBtn,1,1,1,1);
    buttonLayout->addWidget(rightBtn,1,2,1,1);
    buttonLayout->setSpacing(2);
    buttonLayout->setMargin(0);
    buttonLayout->setContentsMargins(0,0,0,0);

    upBtn->setMaximumSize(30,15);
    upBtn->setMinimumSize(30,15);
    leftBtn->setMaximumSize(30,15);
    leftBtn->setMinimumSize(30,15);
    downBtn->setMaximumSize(30,15);
    downBtn->setMinimumSize(30,15);
    rightBtn->setMaximumSize(30,15);
    rightBtn->setMinimumSize(30,15);

    moveLabel1=new QLabel(tr("移\n动"));
    moveLabel1->setStyleSheet("background-color:rgba(255,255,255,0);color:rgba(184,7,235,150);font-weight:bold;font-size:13px");

    QHBoxLayout *layout1=new QHBoxLayout;
    layout1->addWidget(moveLabel1);
    layout1->addLayout(buttonLayout);
    layout1->setSpacing(8);
    layout1->setMargin(0);
    layout1->setContentsMargins(0,0,0,0);

    buttonLayout2=new QGridLayout;
    wBtn=new QPushButton(tr("W"));
    sBtn=new QPushButton(tr("S"));
    aBtn=new QPushButton(tr("A"));
    dBtn=new QPushButton(tr("D"));

    wBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    sBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    aBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    dBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");

    buttonLayout2->addWidget(wBtn,0,1,1,1);
    buttonLayout2->addWidget(aBtn,1,0,1,1);
    buttonLayout2->addWidget(sBtn,1,1,1,1);
    buttonLayout2->addWidget(dBtn,1,2,1,1);
    buttonLayout2->setSpacing(2);
    buttonLayout2->setMargin(0);
    buttonLayout2->setContentsMargins(0,0,0,0);

    wBtn->setMaximumSize(30,15);
    wBtn->setMinimumSize(30,15);
    aBtn->setMaximumSize(30,15);
    aBtn->setMinimumSize(30,15);
    sBtn->setMaximumSize(30,15);
    sBtn->setMinimumSize(30,15);
    dBtn->setMaximumSize(30,15);
    dBtn->setMinimumSize(30,15);

    moveLabel2=new QLabel(tr("移\n动"));
    moveLabel2->setStyleSheet("background-color:rgba(255,255,255,0);color:rgba(184,7,235,150);font-weight:bold;font-size:13px");

    QHBoxLayout *layout2=new QHBoxLayout;
    layout2->addWidget(moveLabel2);
    layout2->addLayout(buttonLayout2);
    layout2->setSpacing(8);
    layout2->setMargin(0);
    layout2->setContentsMargins(0,0,0,0);

    speedButton1=new QPushButton(tr("     Enter"));
    speedButton2=new QPushButton(tr(""));
    speedButton1->setMaximumSize(90,15);
    speedButton1->setMinimumSize(90,15);
    speedButton2->setMaximumSize(90,15);
    speedButton2->setMinimumSize(90,15);

    spaceLabel=new QLabel(tr("俯\n冲"));
    spaceLabel->setStyleSheet("background-color:rgba(255,255,255,0);color:rgba(184,7,235,150);font-weight:bold;font-size:13px");
    speedButton1->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    speedButton2->setStyleSheet("background-color:rgba(228,89,249,255);border:0");

    vboxLayout=new QVBoxLayout;
    vboxLayout->addWidget(speedButton1);
    vboxLayout->addWidget(speedButton2);
    vboxLayout->setSpacing(2);
    vboxLayout->setMargin(0);
    vboxLayout->setContentsMargins(0,0,0,0);

    QHBoxLayout *layout3=new QHBoxLayout;
    layout3->addWidget(spaceLabel);
    layout3->addLayout(vboxLayout);
    layout3->setSpacing(2);
    layout3->setMargin(0);
    layout3->setContentsMargins(0,0,0,0);

    pauseButton=new QPushButton(tr("Z"));
    pauseLabel=new QLabel(tr("暂\n停"));
    pauseLabel->setStyleSheet("background-color:rgba(255,255,255,0);color:rgba(184,7,235,150);font-weight:bold;font-size:13px");
    pauseButton->setStyleSheet("border:0");

    pauseButton->setMaximumSize(90,27);
    pauseButton->setMinimumSize(90,27);
    pauseButton->setMaximumSize(90,27);
    pauseButton->setMinimumSize(90,27);

    QHBoxLayout *layout4=new QHBoxLayout;
    layout4->addWidget(pauseLabel);
    layout4->addWidget(pauseButton);
    layout4->setSpacing(2);
    layout4->setMargin(0);
    layout4->setContentsMargins(0,0,0,0);

    useButton=new QPushButton(tr("J"));
    useLabel=new QLabel(tr("技\n能"));
    useLabel->setStyleSheet("background-color:rgba(255,255,255,0);color:rgba(184,7,235,150);font-weight:bold;font-size:13px");

    useButton->setMaximumSize(90,27);
    useButton->setMinimumSize(90,27);
    useButton->setMaximumSize(90,27);
    useButton->setMinimumSize(90,27);

    pauseButton->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    useButton->setStyleSheet("background-color:rgba(228,89,249,255);border:0");

    QHBoxLayout *layout5=new QHBoxLayout;
    layout5->addWidget(useLabel);
    layout5->addWidget(useButton);
    layout5->setSpacing(2);
    layout5->setMargin(0);
    layout5->setContentsMargins(0,0,0,0);


    vboxLayout1=new QVBoxLayout(this);
    vboxLayout1->addLayout(layout1);
    vboxLayout1->addLayout(layout2);
    vboxLayout1->addLayout(layout3);
    vboxLayout1->addLayout(layout4);
    vboxLayout1->addLayout(layout5);
    vboxLayout1->setSpacing(2);
    vboxLayout1->setMargin(0);
    vboxLayout1->setContentsMargins(0,0,0,0);
}

void tipWidget::resetQss()
{
    aBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    dBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    wBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    sBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    speedButton1->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    leftBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    rightBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    upBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    downBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    speedButton2->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    pauseButton->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
    useButton->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
}

bool tipWidget::eventFilter(QObject *oj, QEvent *event)
{
    if(oj==view&&isGame)
    {
        if(event->type()==QEvent::KeyPress)
        {
            QKeyEvent *keyEvent=(QKeyEvent*)event;
            switch(keyEvent->key())
            {
            case Qt::Key_A:
                aBtn->setStyleSheet("background-color:red;border:0");
                break;
            case Qt::Key_D:
                dBtn->setStyleSheet("background-color:red;border:0");
                break;
            case Qt::Key_W:
                wBtn->setStyleSheet("background-color:red;border:0");
                break;
            case Qt::Key_S:
                sBtn->setStyleSheet("background-color:red;border:0");
                break;
            case Qt::Key_Return:
                speedButton1->setStyleSheet("background-color:red;border:0");
                break;
            case Qt::Key_Left:
                leftBtn->setStyleSheet("background-color:red;border:0");
                break;
            case Qt::Key_Right:
                rightBtn->setStyleSheet("background-color:red;border:0");
                break;
            case Qt::Key_Up:
                upBtn->setStyleSheet("border:0;background-color:red;border:0");
                break;
            case Qt::Key_Down:
                downBtn->setStyleSheet("background-color:red;border:0");
                break;
            case Qt::Key_Space:
                speedButton2->setStyleSheet("background-color:red;border:0");
                break;
            case Qt::Key_Z:
                pauseButton->setStyleSheet("background-color:red;border:0");
                break;
            case Qt::Key_J:
                useButton->setStyleSheet("background-color:red;border:0");
                emit jPressEvent();
                break;
            default:break;
            }
            return false;
        }

        if(event->type()==QEvent::KeyRelease)
        {
            QKeyEvent *keyEvent=(QKeyEvent*)event;
            switch(keyEvent->key())
            {
            case Qt::Key_A:
                aBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_D:
                dBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_W:
                wBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_S:
                sBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_Return:
                speedButton1->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_Left:
                leftBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_Right:
                rightBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_Up:
                upBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_Down:
                downBtn->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_Space:
                speedButton2->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_Z:
                pauseButton->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            case Qt::Key_J:
                useButton->setStyleSheet("background-color:rgba(228,89,249,255);border:0");
                break;
            default:break;
            }
            return false;
        }
    }
    return false;
}
