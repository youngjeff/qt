#include <QTimer>
#include <QMessageBox>
#include <QLayout>
#include <QLabel>
#include <QPropertyAnimation>
#include <QGraphicsBlurEffect>
#include <QtMultimedia/QMediaPlayer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QHeaderView>
#include "centersqlmodel.h"
#include "mypushbutton.h"
#include "myview.h"
#include "onebox.h"
#include "boxgroup.h"


static const qreal INITSPEED=800;

myView::myView(QWidget *parent) :
    QGraphicsView(parent)
{
    cursor=new QCursor(QPixmap(":/new/prefix1/test.png"));
    setCursor(*cursor);
    JPress=false;
    initView();
    gameScore=0;
    gameEnergy=0;
    clearedNumber=0;
    allowJ=false;
    installDialog();
    player=new QMediaPlayer(this);
    QTimer::singleShot(2000,this,SLOT(abc()));
    connect(group,SIGNAL(pressZ()),this,SLOT(recvievePressZ()));
}

void myView::JScore()
{
    if(gameEnergy>=100)
    {
        gameEnergy-=100;
    }
    gameScore+=100;

    gameScoreText->setHtml(tr("<font color=\"#f480e0\">%1</font>").arg(gameScore));
    gameEnergyText->setHtml(tr("<font color=\"#f480e0\">%1</font>").arg(gameEnergy));


    //播放分数改变动画->(开始)
    QPropertyAnimation *scoreAnimation=new QPropertyAnimation(gameScoreText,"scale");
    scoreAnimation->setEasingCurve(QEasingCurve::OutBounce);
    scoreAnimation->setDuration(250);
    scoreAnimation->setStartValue(4);
    scoreAnimation->setEndValue(1);
    scoreAnimation->start();
    //播放分数改变动画<-(结束)

    QTimer::singleShot(10,this,SLOT(newSlots()));
}

void myView::clearAll()
{
    //播放方块消除音效->(开始)
    player->setMedia(QUrl("qrc:/new/prefix1/flystar.wav"));
    player->setVolume(50);
    player->play(); 
    //播放方块消除音效<-(结束)

    JPress=true;

    //一行行地消除方块并播放动画->(开始)
    for(int y=429;y>30;y=y-20)
    {
        QList<QGraphicsItem*> list=scene()->items(QRectF(299,y,202,22),Qt::ContainsItemShape,Qt::DescendingOrder);
        if(list.count()>=0)
        {
            foreach (QGraphicsItem* item,list)
            {
                oneBox *box=(oneBox*)item;
                QGraphicsBlurEffect *effect=new QGraphicsBlurEffect;
                box->setGraphicsEffect(effect);
                QPropertyAnimation *animation=new QPropertyAnimation(box,"scale");
                animation->setEasingCurve(QEasingCurve::OutBounce);
                animation->setDuration(250);
                animation->setStartValue(0.25);
                animation->setEndValue(1);
                animation->start(QAbstractAnimation::DeleteWhenStopped);
                connect(animation,SIGNAL(finished()),box,SLOT(deleteLater()));
            }
            rows<<y;
        }

    }
    //一行行地消除方块并播放动画->(结束)


    //下移并申请新的方块
    if(rows.count()>0)
    {
        QTimer::singleShot(400,this,SLOT(moveLines()));
    }
    else
    {
        group->createBoxGroup(QPointF(400,70),nextGroup->getCurrentBox());
        nextGroup->clearBoxGroup(true);
        nextGroup->createBoxGroup(QPointF(600,110));
    }
    JScore();
    allowJ=false;
    QTimer::singleShot(2000,this,SLOT(abc()));
}

bool myView::isAllowJ()
{
    if(gameEnergy>=50&&allowJ)
        return true;
    else
        return false;
}

long myView::getGameScore()
{
    return gameScore;
}

void myView::newScore()
{
    gameScore=0;
    gameEnergy=0;
    gameScoreText->setHtml(tr("<font color=\"#f480e0\">%1</font>").arg(gameScore));
    gameEnergyText->setHtml(tr("<font color=\"#f480e0\">%1</font>").arg(gameEnergy));
}

void myView::clearNextBox()
{
    nextGroup->clearBoxGroup(true);
}

void myView::installDialog()
{
    box=new QDialog(this);
    box->setWindowOpacity(0.99);
    box->setStyleSheet("background-color:rgba(234,84,176,255);border-color:pink;");
    label=new QLabel;
    btn1=new myPushButton(tr("重新开始"));
    btn2=new myPushButton(tr("关闭游戏"));
    connect(btn1,SIGNAL(clicked()),this,SLOT(reStartGame()));
    connect(btn2,SIGNAL(clicked()),this,SLOT(closeWidget()));
    messageTitle=new QLabel(tr("                     \b\b\b游戏结束"));
    messageTitle->setMinimumWidth(275);
    btn1->setMaximumWidth(140);
    btn1->setMinimumWidth(140);

    btn2->setMaximumWidth(140);
    btn2->setMinimumWidth(140);

    btn1->setMaximumHeight(30);
    btn1->setMinimumHeight(30);

    btn2->setMaximumHeight(30);
    btn2->setMinimumHeight(30);

    btn1->setAutoDefault(false);
    btn2->setAutoDefault(false);



}

void myView::setParentWidget(QWidget *widget)
{
    parentWidget=widget;
}

void myView::endWidget()
{
    //打开数据库并且显示榜单已经后续操作提示->(开始)
    QSqlDatabase base=QSqlDatabase::addDatabase("QSQLITE");
    base.setDatabaseName("UserScore.db");
    base.setUserName("adminUser");
    base.setPassword("gm336699");
    if(!base.open())
    {
        QMessageBox::information(parentWidget,tr("error"),tr("数据库打开失败！"));
    }


    maxLabel=new QLabel(tr("---高分榜---"));
    maxLabel->setMaximumWidth(80);
    maxLabel->setObjectName("MAXLABEL");
    maxLabel->setStyleSheet("QLabel#MAXLABEL{background-color:rgba(184,7,235,0)}");
    maxModel=new centerSqlModel;
    maxModel->setQuery("select username,level,maxscore from usertable order by maxscore desc limit 5");
    maxModel->sort(2,Qt::DescendingOrder);
    maxModel->setHeaderData(0,Qt::Horizontal,tr("玩家"),Qt::DisplayRole);
    maxModel->setHeaderData(1,Qt::Horizontal,tr("等级"),Qt::DisplayRole);
    maxModel->setHeaderData(2,Qt::Horizontal,tr("最高分"),Qt::DisplayRole);
    maxModel->setHeaderData(0,Qt::Horizontal,QColor(184,7,235),Qt::DecorationRole);

    maxView=new QTableView;
    maxView->setModel(maxModel);
    maxView->setObjectName("MAXVIEW");
    maxView->setStyleSheet("QTableView#MAXVIEW{background-color:rgba(184,7,235,100)}");
    maxView->setColumnWidth(0,98);
    maxView->setColumnWidth(1,98);
    maxView->setColumnWidth(2,98);
    maxView->setMaximumWidth(307);
    allLabel=new QLabel(tr("---总分榜---"));
    allLabel->setMaximumWidth(80);
    allLabel->setObjectName("ALLLABEL");
    allLabel->setStyleSheet("QLabel#ALLLABEL{background-color:rgba(184,7,235,0)}");
    allModel=new centerSqlModel;
    allModel->setQuery("select username,level,allscore from usertable order by allscore desc limit 5");
    allModel->sort(2,Qt::DescendingOrder);
    allModel->setHeaderData(0,Qt::Horizontal,tr("玩家"),Qt::DisplayRole);
    allModel->setHeaderData(1,Qt::Horizontal,tr("等级"),Qt::DisplayRole);
    allModel->setHeaderData(2,Qt::Horizontal,tr("总分数"),Qt::DisplayRole);

    allView=new QTableView;
    allView->setModel(allModel);
    allView->setObjectName("ALLVIEW");
    allView->setStyleSheet("QTableView#ALLVIEW{background-color:rgba(184,7,235,100)}");
    allView->setColumnWidth(0,98);
    allView->setColumnWidth(1,98);
    allView->setColumnWidth(2,98);
    allView->setMaximumWidth(307);
    QVBoxLayout *scoreLayout=new QVBoxLayout;
    scoreLayout->addWidget(maxLabel);
    scoreLayout->addWidget(maxView);
    scoreLayout->addWidget(allLabel);
    scoreLayout->addWidget(allView);
    scoreLayout->setAlignment(maxLabel,Qt::AlignCenter);
    scoreLayout->setAlignment(allLabel,Qt::AlignCenter);

    QHBoxLayout *hlayout=new QHBoxLayout;
    hlayout->addWidget(btn1);
    hlayout->addWidget(btn2);
    hlayout->setSpacing(3);
    hlayout->setContentsMargins(5,0,5,0);

    messageTitle->setStyleSheet("background-color:rgba(184,7,235,106)");
    hlayout->setAlignment(btn1,Qt::AlignCenter);
    hlayout->setAlignment(btn2,Qt::AlignCenter);

    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(messageTitle);
    layout->addLayout(scoreLayout);
    layout->addWidget(label);
    layout->addLayout(hlayout);
  //  layout->setAlignment(messageTitle,Qt::AlignTop);
    layout->setAlignment(label,Qt::AlignCenter);

    layout->setContentsMargins(0,0,0,0);
    layout->setStretch(0,0);
    box->setLayout(layout);
    box->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    label->setText(tr(" 很抱歉你已经输了！是否重来一局？"));

    box->setGeometry(parentWidget->pos().x()+235,parentWidget->pos().y()+42,307,461);
    box->exec();

    //打开数据库并且显示榜单已经后续操作提示<-(结束)
}

void myView::recvievePressZ()
{
    emit resendPressZ();
}

void myView::closeWidget()
{
    emit closeAliWidget();
}

void myView::startGame()
{
    initGame();
}

void myView::clearFullLines()
{
    //以下和clearAll函数相同、所不同的是进行了满行判断、只消除满行的格子、而clearAll消除全部
    player->setMedia(QUrl("qrc:/new/prefix1/useitem.wav"));
    player->setVolume(50);
    player->play();
    for(int y=429;y>50;y=y-20)
    {
        QList<QGraphicsItem*> list=scene()->items(QRectF(299,y,202,22),Qt::ContainsItemShape,Qt::DescendingOrder);
        if(list.count()==10)
        {
            foreach (QGraphicsItem* item,list)
            {
                group->waring=true;
                oneBox *box=(oneBox*)item;
                QGraphicsBlurEffect *effect=new QGraphicsBlurEffect;
                box->setGraphicsEffect(effect);
                QPropertyAnimation *animation=new QPropertyAnimation(box,"scale");
                animation->setEasingCurve(QEasingCurve::OutBounce);
                animation->setDuration(250);
                animation->setStartValue(4);
                animation->setEndValue(0.25);
                animation->start(QAbstractAnimation::DeleteWhenStopped);
                connect(animation,SIGNAL(finished()),box,SLOT(deleteLater()));
            }
            rows<<y;
        }

    }

    if(rows.count()>0)
    {
        player->setMedia(QUrl("qrc:/new/prefix1/flystar.wav"));
        player->setVolume(50);
        player->play();
        QTimer::singleShot(400,this,SLOT(moveLines()));
    }
    else
    {
        group->createBoxGroup(QPointF(400,70),nextGroup->getCurrentBox());
        nextGroup->clearBoxGroup(true);
        nextGroup->createBoxGroup(QPointF(600,110));
    }
}

void myView::moveLines()
{
    //下移操作并申请新的方块
    for(int i=rows.count();i>0;i--)
    {
        int row=rows.at(i-1);
        QGraphicsItem* item;
        QList<QGraphicsItem*> list=scene()->items(QRectF(299,49,202,row-47),Qt::ContainsItemShape);
        setFocus();
        foreach (item,list)
        {
            item->moveBy(0,20);
        }
    }


    if(JPress)
    {
        JPress=false;
    }
    else
    {
        updateScore(rows.count());
    }

    rows.clear();
    group->createBoxGroup(QPointF(400,70),nextGroup->getCurrentBox());
    nextGroup->clearBoxGroup(true);
    nextGroup->createBoxGroup(QPointF(600,110));
    group->waring=false;                                             //view的操作完成、设置waring为假、group可以影响键盘事件
}

void myView::gameOver()
{
    emit gameIsOver();
}

void myView::pauseGame()
{
    group->stopTimer();
}

void myView::rePauseGame()
{
    group->startTimer(gameSpeed);
}

void myView::reStartGame()
{
    box->close();
    setFocus();
    nextGroup->clearBoxGroup(true);
    group->clearBoxGroup();
  //  group->hide();
    QList<QGraphicsItem*> list=scene()->items(QRectF(299,49,202,402),Qt::ContainsItemShape);
    foreach (QGraphicsItem* item,list)
    {
        scene()->removeItem(item);
        oneBox *box=(oneBox*)item;
        box->deleteLater();
    }
    emit gameIsRestart();
}

void myView::newSlots()
{
    //播放分数改变动画->(开始)
    QPropertyAnimation *energyAnimation=new QPropertyAnimation(gameEnergyText,"scale");
    energyAnimation->setEasingCurve(QEasingCurve::OutBounce);
    energyAnimation->setDuration(250);
    energyAnimation->setStartValue(4);
    energyAnimation->setEndValue(1);
    energyAnimation->start();
    //播放分数改变动画<-(结束)
}

void myView::abc()
{
    allowJ=true;
}

void myView::initGame()
{
    group->createBoxGroup(QPointF(400,70));
    group->setFocus();
    group->startTimer(INITSPEED);
    gameSpeed=INITSPEED;
    nextGroup->createBoxGroup(QPointF(600,110));

    scene()->addItem(label1Text);
    scene()->addItem(gameScoreText);
    scene()->addItem(label2Text);
    scene()->addItem(gameEnergyText);


    gameScoreText->setHtml(tr("<font color=\"#f480e0\">0</font>"));
    gameEnergyText->setHtml(tr("<font color=\"#f480e0\">0</font>"));
    label1Text->setHtml(tr("<font color=\"#b807eb\">分数:</font>"));
    label2Text->setHtml(tr("<font color=\"#b807eb\">能量:</font>"));

}

void myView::initView()
{
    setRenderHint(QPainter::Antialiasing);
    setCacheMode(CacheBackground);
    setMaximumSize(800,500);
    setMinimumSize(800,500);

    QGraphicsScene *scene=new QGraphicsScene;
    scene->setSceneRect(5,5,800,500);
    scene->setBackgroundBrush(QPixmap(":/new/prefix1/images/myBackground.png"));
    setScene(scene);

    lineItem1=scene->addLine(297,47,503,47);
    lineItem2=scene->addLine(297,453,503,453);
    lineItem3=scene->addLine(297,47,297,453);
    lineItem4=scene->addLine(503,47,503,453);

    lineItem1->setPen(QColor(184,7,235,0));
    lineItem2->setPen(QColor(184,7,235,0));
    lineItem3->setPen(QColor(184,7,235,0));
    lineItem4->setPen(QColor(184,7,235,0));

    group=new boxGroup;
    connect(group,SIGNAL(needNextGroup()),this,SLOT(clearFullLines()));
    connect(group,SIGNAL(gameFinish()),this,SLOT(gameOver()));
    scene->addItem(group);

    nextGroup=new boxGroup;
    scene->addItem(nextGroup);

    gameScoreText=new QGraphicsTextItem;
    gameScoreText->setFont(QFont("Times",20,QFont::Bold));
    gameScoreText->setPos(650,350);

    gameEnergyText=new QGraphicsTextItem;
    gameEnergyText->setFont(QFont("Times",20,QFont::Bold));
    gameEnergyText->setPos(650,400);

    label1Text=new QGraphicsTextItem;
    label1Text->setFont(QFont("Times",20,QFont::Bold));
    label1Text->setPos(570,350);

    label2Text=new QGraphicsTextItem;
    label2Text->setFont(QFont("Times",20,QFont::Bold));
    label2Text->setPos(570,400);

    QWidget *widget=new QWidget;

    //startGame();
}

void myView::updateScore(const int fullRowNum)
{
    clearedNumber+=fullRowNum;
    gameScore+=fullRowNum*10;

    switch(fullRowNum)
    {
    case 0:gameEnergy=0;break;
    case 1:gameEnergy+=2;break;
    case 2:gameEnergy+=6;break;
    case 3:gameEnergy+=15;break;
    case 4:gameEnergy+=35;break;
    }


    gameScoreText->setHtml(tr("<font color=\"#f480e0\">%1</font>").arg(gameScore));
    gameEnergyText->setHtml(tr("<font color=\"#f480e0\">%1</font>").arg(gameEnergy));

    QPropertyAnimation *scoreAnimation=new QPropertyAnimation(gameScoreText,"scale");
    scoreAnimation->setEasingCurve(QEasingCurve::OutBounce);
    scoreAnimation->setDuration(250);
    scoreAnimation->setStartValue(4);
    scoreAnimation->setEndValue(1);
    scoreAnimation->start();

    QTimer::singleShot(10,this,SLOT(newSlots()));


    //以消除的总行数提升游戏速度、最小值为1
    if(clearedNumber>20)
    {
        gameSpeed-=50;
        if(gameSpeed<1)
        {
            gameSpeed=1;
        }
        group->stopTimer();
        group->startTimer(gameSpeed);
        clearedNumber=0;
    }
}
