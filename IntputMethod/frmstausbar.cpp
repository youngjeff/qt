#include "frmstausbar.h"
#include "ui_frmstausbar.h"
#include <QHBoxLayout>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QMenu>

frmStausbar::frmStausbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmStausbar)
{
    ui->setupUi(this);
    setWindowFlags( Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    /*QHBoxLayout *layout=new QHBoxLayout;  //新建水平布局管理器
    layout->addWidget(ui->btnUser);       //向布局管理器中添加部件
    layout->addWidget(ui->btnType);
    layout->addWidget(ui->btnPunctuation);
    layout->addWidget(ui->btnKeyboard);
    layout->addWidget(ui->btnSetup);
    layout->setSpacing(10);               //设置部件间的间隔
    layout->setContentsMargins(0,0,50,50);//设置布局管理器到边界的距离
                                          //4个参数顺序是左，上，右，下
    setLayout(layout);
    */

    //QPixmap background;
    //加载图片
    //background.load(":/image/background.png");
    //设置窗口大小为图片大小
    //resize(background.size());
    //为窗口设置遮罩
    //setMask(background.mask());
    ui->btnUser->setIcon(QIcon(":/image/user.png"));
    ui->btnType->setIcon(QIcon(":/image/type.png"));
    ui->btnPunctuation->setIcon(QIcon(":/image/punctuation.png"));
    ui->btnKeyboard->setIcon(QIcon(":/image/keyboard.png"));
    ui->btnSetup->setIcon(QIcon(":/image/setup.png"));


}

/*void frmStausbar::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/image/background.png"));
}*/


frmStausbar::~frmStausbar()
{
    delete ui;
}
