#include <QTime>
#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QApplication>
#include <QStyleFactory>
#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>
#include <QLineEdit>
#include <QPalette>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "centersqlmodel.h"
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QHeaderView>
#include <QTimer>
#include <QtMultimedia/QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>
#include <QBitmap>
#include <QMovie>
#include "mywidget.h"
#include "myview.h"
#include "mylabel.h"
#include "tipwidget.h"
#include "mypushbutton.h"

myWidget::myWidget(QWidget *parent) :
    QWidget(parent)
{
    //初始化数据库->(开始)
    QSqlDatabase base=QSqlDatabase::addDatabase("QSQLITE","C1");
    base.setDatabaseName("UserScore.db");
    base.setUserName("adminUser");
    base.setPassword("gm336699");
    if(!base.open())
    {
        QMessageBox::information(this,tr("error"),tr("数据库打开失败！"));
    }


    QSqlQuery query(base);
    query.exec("create table usertable(username varchar(20) primary key,password varchar(20),level long,maxscore long,allscore long)");
    query.exec("insert into usertable values('user1','303030',1,0,0)");
    query.exec("insert into usertable values('user2','303030',1,0,0)");
    query.exec("insert into usertable values('user3','303030',1,0,0)");
    query.exec("insert into usertable values('user4','303030',1,0,0)");
    query.exec("insert into usertable values('user5','303030',1,0,0)");
    //初始化数据库<-(结束)


    cursor=new QCursor(QPixmap(":/new/prefix1/test.png"));
    setCursor(*cursor);
    player=new QMediaPlayer(this);
    player2=new QMediaPlayer(this);
    mousePress=false;
    isActive=true;
    isGame=true;
    isLogin=true;
    isRestartGame=false;
    qApp->setStyle(QStyleFactory::create("fusion"));
    this->setStyleSheet("background-color:rgb(184,7,235);color:white;");
    setWindowFlags(Qt::FramelessWindowHint);
    installEventFilter(this);
   // resize(850,550);
    playGame();
    setLook();
    gifWidget();
    view->setFocus();                                                                 //让view获得焦点、不使用或许会出BUG
}

void myWidget::playGame()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    view=new myView;
    view->setMaximumSize(811,519);
    view->setMinimumSize(811,519);
    view->scene()->setBackgroundBrush(QPixmap(":/new/prefix1/images/loginBnd.png"));
    view->setParentWidget(this);

    connect(this,SIGNAL(pause()),view,SLOT(pauseGame()));
    connect(this,SIGNAL(repause()),view,SLOT(rePauseGame()));
    connect(view,SIGNAL(resendPressZ()),this,SLOT(receiveResendPressZ()));
    connect(view,SIGNAL(gameIsOver()),this,SLOT(setIsGame()));
    connect(view,SIGNAL(closeAliWidget()),this,SLOT(close()));                        //响应view的messBox传来的关闭窗口信息
    connect(view,SIGNAL(gameIsRestart()),this,SLOT(setGameMusic()));
}

void myWidget::setLook()
{
    QHBoxLayout *hlayout=new QHBoxLayout;
    smallBtn=new myPushButton(tr("_"));
    closeBtn=new myPushButton(tr("X"));
    connect(smallBtn,SIGNAL(clicked()),this,SLOT(showMinimized()));
    connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));

    smallBtn->setMaximumSize(30,30);
    smallBtn->setMinimumSize(30,30);
    closeBtn->setMaximumSize(30,30);
    closeBtn->setMinimumSize(30,30);


    pixmapLabel=new QLabel("*");
    titleLabel=new QLabel(tr("伦家才不系什么\n俄罗斯方块呢!!"));
    scoreShow=new QLabel(tr(""));
    scoreShow->setMaximumWidth(600);
    scoreShow->setMaximumHeight(38);

    pixmapLabel->setPixmap(QPixmap(":/new/prefix1/images/myIcon.png"));
    pixmapLabel->setMaximumSize(30,30);
    pixmapLabel->setMinimumSize(30,30);


    hlayout->setSpacing(2);
    hlayout->addWidget(pixmapLabel);
    hlayout->addWidget(titleLabel);
    hlayout->addWidget(scoreShow,Qt::AlignLeft);
    hlayout->addSpacing(20);
    hlayout->addWidget(smallBtn);
    hlayout->addWidget(closeBtn);
    hlayout->setContentsMargins(1,4,4,4);

    QVBoxLayout *layout=new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addLayout(hlayout);
    layout->addWidget(view);
    layout->setSpacing(0);
    setLayout(layout);

    w=new tipWidget(this,view);
    connect(w,SIGNAL(jPressEvent()),this,SLOT(receiveJEvent()));

    test=new QLabel(this);
    //test->resize(view->size());
    test->setGeometry(view->x(),view->y()+37,830,519);
    test->setPixmap(QPixmap(":/new/prefix1/images/pause.png"));
    test->setStyleSheet("background-color:rgba(255,255,255,200)");
    test->hide();
    //test->setWindowFlags(Qt::FramelessWindowHint);
    //test->setAttribute(Qt::WA_TranslucentBackground);
    w->hide();

    setLoginWidget();                                                              //配置并显示登陆界面
}

void myWidget::setLoginWidget()
{
    userLine=new QLineEdit;
    passwordLine=new QLineEdit;
    setUserLine=new QLineEdit;
    setPasswordLine=new QLineEdit;
    userLineText=new QLabel(tr("账号"));
    passwordLineText=new QLabel(tr("密码"));
    setUserLineText=new QLabel(tr("账号"));
    setPasswordLineText=new QLabel(tr("密码"));;
    setTitleLabel=new QLabel(tr("   |登陆游戏|"));
    setTitleLabe2=new QLabel(tr("   |注册账号|"));
    loginBtn=new myPushButton(tr("登陆游戏"));
    goRegisterBtn=new myPushButton(tr("申请注册"));
    registerBtn=new myPushButton(tr("确认注册"));
    goLoginBtn=new myPushButton(tr("前往登陆"));
    userLineText->setStyleSheet("font-size:23px;color:white;background-color:rgba(255,255,255,0);font-weight:bold");
    passwordLineText->setStyleSheet("font-size:23px;color:white;background-color:rgba(255,255,255,0);font-weight:bold");
    setUserLineText->setStyleSheet("font-size:23px;color:white;background-color:rgba(255,255,255,0);font-weight:bold");
    setPasswordLineText->setStyleSheet("font-size:23px;color:white;background-color:rgba(255,255,255,0);font-weight:bold");
    setTitleLabel->setStyleSheet("font-size:25px;color:white;background-color:rgba(255,255,255,0);font-weight:bold");
    setTitleLabe2->setStyleSheet("font-size:25px;color:white;background-color:rgba(255,255,255,0);font-weight:bold");
    loginBtn->setStyleSheet("font-size:18px;color:white;background-color:rgba(234,28,96,100);font-weight:bold");
    goRegisterBtn->setStyleSheet("font-size:18px;color:white;background-color:rgba(234,28,96,100);font-weight:bold");
    registerBtn->setStyleSheet("font-size:18px;color:white;background-color:rgba(234,28,96,100);font-weight:bold");
    goLoginBtn->setStyleSheet("font-size:18px;color:white;background-color:rgba(234,28,96,100);font-weight:bold");

    userLine->setCursor(*cursor);
    passwordLine->setCursor(*cursor);
    setUserLine->setCursor(*cursor);
    setPasswordLine->setCursor(*cursor);
    loginBtn->setCursor(*cursor);
    goRegisterBtn->setCursor(*cursor);
    registerBtn->setCursor(*cursor);
    goLoginBtn->setCursor(*cursor);

    userLine->setMinimumHeight(30);
    passwordLine->setMinimumHeight(30);
    setUserLine->setMinimumHeight(30);
    setPasswordLine->setMinimumHeight(30);

    userLine->setStyleSheet("color:rgba(184,7,235,150);font-size:16px;font-weight:470;");
    passwordLine->setStyleSheet("color:rgba(184,7,235,150);font-size:16px;font-weight:470;");
    setUserLine->setStyleSheet("color:rgba(184,7,235,150);font-size:16px;font-weight:470;");
    setPasswordLine->setStyleSheet("color:rgba(184,7,235,150);font-size:16px;font-weight:470;");

    userLine->setContextMenuPolicy(Qt::NoContextMenu);
    passwordLine->setContextMenuPolicy(Qt::NoContextMenu);
    setUserLine->setContextMenuPolicy(Qt::NoContextMenu);
    setPasswordLine->setContextMenuPolicy(Qt::NoContextMenu);


    connect(goRegisterBtn,SIGNAL(clicked()),this,SLOT(setLoginRotate()));
    connect(goLoginBtn,SIGNAL(clicked()),this,SLOT(setRegisterRotate()));
    connect(loginBtn,SIGNAL(clicked()),this,SLOT(loginGame()));
    connect(registerBtn,SIGNAL(clicked()),this,SLOT(registerUser()));

    //<-LoginWidget
    titleLabel11=view->scene()->addWidget(setTitleLabel);
    titleLabel11->setMaximumWidth(200);

    label1=view->scene()->addWidget(userLineText);
    line1=view->scene()->addWidget(userLine);
    QGraphicsLinearLayout *loginSubLayout1 = new QGraphicsLinearLayout(Qt::Horizontal);
    loginSubLayout1->addItem(label1);
    loginSubLayout1->addItem(line1);
    loginSubLayout1->setAlignment(line1,Qt::AlignVCenter);
    loginSubLayout1->setContentsMargins(10,10,10,10);

    label2=view->scene()->addWidget(passwordLineText);
    line2=view->scene()->addWidget(passwordLine);
    passwordLine->setEchoMode(QLineEdit::Password);
    QGraphicsLinearLayout *loginSubLayout2 = new QGraphicsLinearLayout(Qt::Horizontal);
    loginSubLayout2->addItem(label2);
    loginSubLayout2->addItem(line2);
    loginSubLayout2->setAlignment(line2,Qt::AlignVCenter);
    loginSubLayout2->setContentsMargins(10,10,10,10);

    button1=view->scene()->addWidget(loginBtn);
    button2=view->scene()->addWidget(goRegisterBtn);
    QGraphicsLinearLayout *loginSubLayout3 = new QGraphicsLinearLayout(Qt::Horizontal);
    loginSubLayout3->addItem(button1);
    loginSubLayout3->addItem(button2);
    loginSubLayout3->setContentsMargins(10,10,10,10);

    QGraphicsLinearLayout *loginLayout = new QGraphicsLinearLayout(Qt::Vertical);
    loginLayout->addItem(titleLabel11);
    loginLayout->addItem(loginSubLayout1);
    loginLayout->addItem(loginSubLayout2);
    loginLayout->addItem(loginSubLayout3);
    loginLayout->setAlignment(titleLabel11,Qt::AlignHCenter);
    loginLayout->setContentsMargins(10,10,10,10);

    grapLoginWidget=new QGraphicsWidget;
    grapLoginWidget->setCursor(*cursor);
    QPalette palette=grapLoginWidget->palette();
    palette.setBrush(QPalette::Background,QBrush(QColor(234,84,176)));
    grapLoginWidget->setPalette(palette);
    grapLoginWidget->setAutoFillBackground(true);

    view->scene()->addItem(grapLoginWidget);
    grapLoginWidget->setGeometry(260,130,300,200);
    grapLoginWidget->setLayout(loginLayout);
    //->loginWidget end





    //<-RegisterWidget
    titleLabel22=view->scene()->addWidget(setTitleLabe2);
    titleLabel22->setMaximumWidth(200);

    label3=view->scene()->addWidget(setUserLineText);
    line3=view->scene()->addWidget(setUserLine);
    QGraphicsLinearLayout *registerSubLayout1 = new QGraphicsLinearLayout(Qt::Horizontal);
    registerSubLayout1->addItem(label3);
    registerSubLayout1->addItem(line3);
    registerSubLayout1->setAlignment(line3,Qt::AlignVCenter);
    registerSubLayout1->setContentsMargins(10,10,10,10);

    label4=view->scene()->addWidget(setPasswordLineText);
    line4=view->scene()->addWidget(setPasswordLine);
    QGraphicsLinearLayout *registerSubLayout2 = new QGraphicsLinearLayout(Qt::Horizontal);
    registerSubLayout2->addItem(label4);
    registerSubLayout2->addItem(line4);
    registerSubLayout2->setAlignment(line4,Qt::AlignVCenter);
    registerSubLayout2->setContentsMargins(10,10,10,10);

    button3=view->scene()->addWidget(registerBtn);
    button4=view->scene()->addWidget(goLoginBtn);
    QGraphicsLinearLayout *registerSubLayout3 = new QGraphicsLinearLayout(Qt::Horizontal);
    registerSubLayout3->addItem(button3);
    registerSubLayout3->addItem(button4);
    registerSubLayout3->setContentsMargins(10,10,10,10);

    QGraphicsLinearLayout *registerLayout = new QGraphicsLinearLayout(Qt::Vertical);
    registerLayout->addItem(titleLabel22);
    registerLayout->addItem(registerSubLayout1);
    registerLayout->addItem(registerSubLayout2);
    registerLayout->addItem(registerSubLayout3);
    registerLayout->setAlignment(titleLabel22,Qt::AlignCenter);
    registerLayout->setContentsMargins(10,10,10,10);

    grapRegisterWidget=new QGraphicsWidget;
    grapRegisterWidget->setCursor(*cursor);
    QPalette palette2=grapRegisterWidget->palette();
    palette2.setBrush(QPalette::Background,QBrush(QColor(184,7,235)));
    grapRegisterWidget->setPalette(palette);
    grapRegisterWidget->setAutoFillBackground(true);

    view->scene()->addItem(grapRegisterWidget);
    grapRegisterWidget->setGeometry(260,130,300,200);
    grapRegisterWidget->setLayout(registerLayout);
    //->RegisterWidget end




    //播放开头音乐->（开始）
    grapRegisterWidget->hide();
    playList=new QMediaPlaylist(this);
    player->setPlaylist(playList);
    playList->addMedia(QUrl("qrc:/new/prefix1/first.mp3"));
    playList->setCurrentIndex(0);
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    player->setVolume(80);
    player->play();
    //播放开头音乐<-（结束）

}

void myWidget::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void myWidget::helloWidget()
{

    //以下为数据库操作、选取数据库的一部分载入模型，然后加载到view上显示
    QSqlDatabase base=QSqlDatabase::addDatabase("QSQLITE");
    base.setDatabaseName("UserScore.db");
    base.setUserName("adminUser");
    base.setPassword("gm336699");
    if(!base.open())
    {
        QMessageBox::information(this,tr("error"),tr("数据库打开失败！"));
    }

    widget=new QWidget(view);
    widget->setObjectName("SCOREWIDGET");
    widget->setStyleSheet("QWidget#SCOREWIDGET{background-color:rgba(184,7,235,100)}");
    widget->resize(330,442);
    widget->move(225,20);

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

    start=new myPushButton(tr("开始游戏"));
    start->setMinimumHeight(30);
    start->setObjectName("STARTBUTTON");
    start->setStyleSheet("myPushButton#STARTBUTTON{background-color:rgba(184,7,235,50)}");
    connect(start,SIGNAL(clicked()),this,SLOT(readyText()));                  //响应开始按键、调用readyText
    QVBoxLayout *scoreLayout=new QVBoxLayout;
    scoreLayout->addWidget(maxLabel);
    scoreLayout->addWidget(maxView);
    scoreLayout->addWidget(allLabel);
    scoreLayout->addWidget(allView);
    scoreLayout->addWidget(start);
    scoreLayout->setAlignment(maxLabel,Qt::AlignCenter);
    scoreLayout->setAlignment(allLabel,Qt::AlignCenter);
    widget->setLayout(scoreLayout);
    widget->show();
}

void myWidget::gifWidget()
{
    gifLabel=new myLabel(this);
    QMovie *gif=new QMovie(":/new/prefix1/newFlf.gif");
    gifLabel->setMovie(gif);
    gif->start();
    gifLabel->setStyleSheet("background-color:rgba(255,255,255,0);");
    gifLabel->setGeometry(-130,20,460,270);
    gifLabel->show();
}

void myWidget::receiveResendPressZ()
{
    //暂停Z键的实现、如果是活动的、则暂停、否则重新开始游戏
    if(isActive)
    {

        test->show();
        isActive=false;
        w->isGame=false;
       // QApplication::sendEvent(view,keyEvent);
        player->pause();
        emit pause();
        return;
    }
    else
    {

        test->hide();
        isActive=true;
        view->setFocus();
        w->isGame=true;
        player->play();
        //QApplication::sendEvent(view,keyEvent);
        emit repause();
        return;
    }
}



void myWidget::setIsGame()
{
    isGame=false;                                                      //如果游戏结束、不再响应任何键盘事件

    //播放结束音乐->（开始）
    player->setPlaylist(playList);
    playList->clear();
    playList->addMedia(QUrl("qrc:/new/prefix1/end.mp3"));
    playList->setCurrentIndex(0);
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    player->setVolume(80);
    player->play();
    //播放结束音乐<-（结束）


    //打开数据库结算分数、显示新的排行榜->（开始）
    long gameScore=view->getGameScore();
    if(gameScore>maxScore)
    {
        maxScore=gameScore;
    }
    allScore+=gameScore;
    level=allScore/100+1;


    QSqlDatabase base=QSqlDatabase::addDatabase("QSQLITE","C1");
    base.setDatabaseName("UserScore.db");
    base.setUserName("adminUser");
    base.setPassword("gm336699");
    if(!base.open())
    {
        QMessageBox::information(this,tr("error"),tr("数据库打开失败！"));
    }

    QVariantList setNumber;
    setNumber<<level<<maxScore<<allScore;
    QSqlQuery query(base);
    query.prepare("update usertable set level=? where username=?");
    query.addBindValue(level);
    query.addBindValue(userName);
    query.exec();

    query.prepare("update usertable set maxscore=? where username=?");
    query.addBindValue(maxScore);
    query.addBindValue(userName);
    query.exec();

    query.prepare("update usertable set allscore=? where username=?");
    query.addBindValue(allScore);
    query.addBindValue(userName);
    query.exec();

    query.exec("select * from usertable");


    view->endWidget();
    //打开数据库结算分数、显示新的排行榜<-（结束）
}

void myWidget::receiveJEvent()
{
    if(view->isAllowJ())
    {
        view->clearAll();
    }
}

void myWidget::setLoginRotate()
{
    //旋转登陆窗口并播放音效、随后立即调用注册窗口进行旋转

    gifLabel->hide();                                                      //旋转的时候隐藏gif动画、不隐藏会出现重复绘制bug
    player2->setMedia(QUrl("qrc:/new/prefix1/folder.wav"));
    player2->setVolume(200);
    player2->play();
    loginBtn->setEnabled(false);
    goRegisterBtn->setEnabled(false);
    registerBtn->setEnabled(false);
    goLoginBtn->setEnabled(false);

    QRectF r = grapLoginWidget->boundingRect();

    for(int i=1;i<=89;i++)
    {
        grapLoginWidget->setTransform(QTransform()
                           .translate(r.width() / 2, r.height() / 2)
                           .rotate(i, Qt::YAxis)
                           .translate(-r.width() / 2, -r.height() / 2));
        sleep(1);
        view->update();
    }

    grapLoginWidget->hide();
    grapRegisterWidget->show();

    for(int i=1;i<=91;i++)
    {
        grapRegisterWidget->setTransform(QTransform()
                           .translate(r.width() / 2, r.height() / 2)
                           .rotate(i+270, Qt::YAxis)
                           .translate(-r.width() / 2, -r.height() / 2));
        sleep(1);
        view->update();
    }

    userLine->clear();
    passwordLine->clear();

    registerBtn->setEnabled(true);
    goLoginBtn->setEnabled(true);


    gifLabel->show();                                                    //旋转完成显示gif动画
}

void myWidget::setRegisterRotate()
{

    //旋转注册窗口并播放音效、随后立即调用登陆窗口进行旋转

    gifLabel->hide();
    player2->setMedia(QUrl("qrc:/new/prefix1/folder.wav"));
    player2->setVolume(200);
    player2->play();
    loginBtn->setEnabled(false);
    goRegisterBtn->setEnabled(false);
    registerBtn->setEnabled(false);
    goLoginBtn->setEnabled(false);

    QRectF r = grapRegisterWidget->boundingRect();

    for(int i=1;i<=89;i++)
    {
        grapRegisterWidget->setTransform(QTransform()
                           .translate(r.width() / 2, r.height() / 2)
                           .rotate(i, Qt::YAxis)
                           .translate(-r.width() / 2, -r.height() / 2));
        sleep(1);
        view->update();
    }


    grapRegisterWidget->hide();
    grapLoginWidget->show();


    for(int i=1;i<=91;i++)
    {
        grapLoginWidget->setTransform(QTransform()
                           .translate(r.width() / 2, r.height() / 2)
                           .rotate(i+270, Qt::YAxis)
                           .translate(-r.width() / 2, -r.height() / 2));
        sleep(1);
        view->update();
    }

    setUserLine->clear();
    setPasswordLine->clear();

    loginBtn->setEnabled(true);
    goRegisterBtn->setEnabled(true);

    gifLabel->show();
}

void myWidget::loginGame()
{

    //提示窗口的初始化->（开始）
    QDialog box;
    box.setParent(view);

    box.setWindowOpacity(0.99);
    box.setWindowTitle(tr("提示"));
    QLabel label;
    box.setStyleSheet("background-color:rgba(234,84,176,255);border-color:pink;");
    myPushButton btn;
    btn.setText(tr("好的"));
    connect(&btn,SIGNAL(clicked()),&box,SLOT(close()));
    QLabel messageTitle;
    messageTitle.setText(tr("                   操作提示"));
    messageTitle.setMinimumWidth(275);
    btn.setMaximumWidth(200);
    btn.setMinimumWidth(200);

    messageTitle.setStyleSheet("background-color:rgba(184,7,235,66)");
    QVBoxLayout layout;
    layout.addWidget(&messageTitle);
    layout.addWidget(&label);
    layout.addWidget(&btn);
  //  layout->setAlignment(messageTitle,Qt::AlignTop);
    layout.setAlignment(&label,Qt::AlignCenter);
    layout.setAlignment(&btn,Qt::AlignCenter);
    layout.setContentsMargins(0,0,0,0);
    layout.setStretch(0,0);
    box.setLayout(&layout);
    box.setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    box.setGeometry(this->pos().x()+275,this->pos().y()+215,275,108);
    //提示窗口的初始化<-（结束）

    //响应登陆按键、首先判断输入是否符合规则、不符合提示->（开始）
    if((userLine->text().length()>10)||(passwordLine->text().length()>10))
    {
        label.setText(tr("   用户名和密码的长度最多为10！"));
        box.exec();
        return;
    }

    if((userLine->text().length()<=0)||(passwordLine->text().length()<=0))
    {
        label.setText(tr("   用户名和密码的长度不可以为空！"));
        box.exec();
        return;
    }
    //响应登陆按键、首先判断输入是否符合规则、不符合提示<-（结束）


    //打开数据库判断用户名密码是否正确、错误提示、正确登陆游戏->（开始）
    QSqlDatabase base=QSqlDatabase::addDatabase("QSQLITE","C1");
    base.setDatabaseName("UserScore.db");
    base.setUserName("adminUser");
    base.setPassword("gm336699");
    if(!base.open())
    {
        QMessageBox::information(this,tr("error"),tr("数据库打开失败！"));
    }
    QSqlQuery query(base);

    query.exec("select * from usertable");
    while(query.next())
    {

        if(query.value(0).toString()==userLine->text())
        {

            if(query.value(1).toString()==passwordLine->text())
            {
                query.prepare("select * from usertable where username=?");
                query.addBindValue(userLine->text());
                query.exec();
                while(query.next())
                {
                    userName=query.value(0).toString();
                    level=query.value(2).toInt();
                    maxScore=query.value(3).toInt();
                    allScore=query.value(4).toInt();
                }

                grapLoginWidget->hide();                                                                         //登陆窗口隐藏
                view->scene()->setBackgroundBrush(QPixmap(":/new/prefix1/images/myBackground.png"));             //背景图片更换
                w->show();                                                                                       //按键提示窗口显示
                gifLabel->hide();                                                                                //gif动画隐藏
                scoreShow->setText(tr("|玩家:%1 等级:%2级 最高分:%3 总分数:%4|").arg(userName).arg(level).arg(maxScore).arg(allScore));
                scoreShow->setStyleSheet("font-size:18px");                                                      //左上角玩家信息显示
                helloWidget();                                                                                   //欢迎窗口显示
                return;
            }
            else
            {
                label.setText(tr("  用户名或密码有误，请重新输入！"));
                box.exec();
                return;
            }
        }

    }
    label.setText(tr("  用户名或密码有误，请重新输入！"));
    box.exec();
    //打开数据库判断用户名密码是否正确、错误提示、正确登陆游戏<-（结束）

}

void myWidget::registerUser()
{
    //提示窗口的初始化->（开始）
    QDialog box;
    box.setParent(view);

    box.setWindowOpacity(0.99);
    box.setWindowTitle(tr("提示"));
    QLabel label;
    box.setStyleSheet("background-color:rgba(234,84,176,255);border-color:pink;");
    myPushButton btn;
    btn.setText(tr("好的"));
    connect(&btn,SIGNAL(clicked()),&box,SLOT(close()));
    QLabel messageTitle;
    messageTitle.setText(tr("                   操作提示"));
    messageTitle.setMinimumWidth(275);
    btn.setMaximumWidth(200);
    btn.setMinimumWidth(200);

    messageTitle.setStyleSheet("background-color:rgba(184,7,235,66)");
    QVBoxLayout layout;
    layout.addWidget(&messageTitle);
    layout.addWidget(&label);
    layout.addWidget(&btn);
    layout.setAlignment(&label,Qt::AlignCenter);
    layout.setAlignment(&btn,Qt::AlignCenter);
    layout.setContentsMargins(0,0,0,0);
    layout.setStretch(0,0);
    box.setLayout(&layout);
    box.setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    box.setGeometry(636,340,275,108);
    //提示窗口的初始化<-（结束）

    //响应注册按键、首先判断输入是否符合规则、不符合提示->（开始）
    if((setUserLine->text().length()>10)||(setPasswordLine->text().length()>10))
    {
        label.setText(tr("   用户名和密码的长度最多为10！"));
        box.exec();
        return;
    }

    if(((setUserLine->text().length()<4)&&(setUserLine->text().length()>0))||((setPasswordLine->text().length()<6)&&(setUserLine->text().length()>0)))
    {
        label.setText(tr("   用户名最短为4位，密码最短为6位！"));
        box.exec();
        return;
    }

    if((setUserLine->text().length()<=0)||(setPasswordLine->text().length()<=0))
    {
        label.setText(tr("   用户名和密码的长度不可以为空！"));
        box.exec();
        return;
    }
    //响应注册按键、首先判断输入是否符合规则、不符合提示<-（结束）


    //判断用户是否存在、不存在提示、存在则写入数据库并提示成功->（开始）
    QSqlDatabase base=QSqlDatabase::addDatabase("QSQLITE","C1");
    base.setDatabaseName("UserScore.db");
    base.setUserName("adminUser");
    base.setPassword("gm336699");
    if(!base.open())
    {
        QMessageBox::information(this,tr("error"),tr("数据库打开失败！"));
    }
    QSqlQuery query(base);
    query.exec("select * from usertable");

    while(query.next())
    {
        if(query.value(0).toString()==setUserLine->text())
        {
            label.setText(tr("   用户名已存在，请重新填写！"));
            box.exec();
            return;
        }
    }

    query.prepare("insert into usertable values(?,?,1,0,0)");
    query.addBindValue(setUserLine->text());
    query.addBindValue(setPasswordLine->text());
    query.exec();

    int i=10000;
    while(i>0)
    {
        i--;
    }

    setUserLine->clear();
    setPasswordLine->clear();
    label.setText(tr("   注册成功，欢迎你的加入！"));
    box.exec();
    //判断用户是否存在、不存在提示、存在则写入数据库并提示成功<-（结束）
    return;
}

void myWidget::readyText()
{
    //在欢迎界面点击开始游戏后调用setGameMusic、setGameMusic调用这个函数、显示ready并播放音乐、1秒后调用goText函数
    view->setFocus();
    player->setMedia(QUrl("qrc:/new/prefix1/readygo.mp3"));
    player->setVolume(50);
    player->play();
    widget->hide();
    readyLabel=new QLabel(view);
    readyLabel->setStyleSheet("background-color:rgba(255,255,255,0);");
    readyLabel->move(343,90);
    readyLabel->show();
    readyLabel->resize(200,300);
    readyLabel->setPixmap(QPixmap(":/new/prefix1/images/ready.png"));
    QTimer::singleShot(1000,this,SLOT(goText()));
}

void myWidget::goText()
{
    //显示go、0.45秒后调用goGame开始游戏
    readyLabel->setPixmap(QPixmap(":/new/prefix1/images/go.png"));
    QTimer::singleShot(450,this,SLOT(goGame()));
}

void myWidget::goGame()
{
    readyLabel->hide();
    w->isGame=true;
    isLogin=false;


    //播放游戏中音效并且开始游戏
    player->stop();
    player->setPlaylist(playList);
    playList->clear();
    playList->addMedia(QUrl("qrc:/new/prefix1/play.mp3"));
    playList->setCurrentIndex(0);
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    player->setVolume(90);
    player->play();


    view->clearNextBox();
    view->setFocus();
    view->startGame();
}

void myWidget::setGameMusic()
{
    view->setFocus();
    isRestartGame=true;
    player->setMedia(QUrl("qrc:/new/prefix1/readygo.mp3"));
    player->setVolume(50);
    player->play();
    readyLabel->setPixmap(QPixmap(":/new/prefix1/images/ready.png"));\
    readyLabel->show();
    view->newScore();
    w->resetQss();
    QTimer::singleShot(1000,this,SLOT(goText()));

}



void myWidget::mousePressEvent(QMouseEvent *myEvent)
{
    if(myEvent->button()==Qt::LeftButton)
    {
        mousePress=true;
        offset=myEvent->globalPos()-pos();
    }
}

void myWidget::mouseMoveEvent(QMouseEvent *myEvent)
{
    if((myEvent->buttons()&Qt::LeftButton)&&mousePress)
    {
        QPoint point=myEvent->globalPos()-offset;
        move(point);
    }
}

void myWidget::mouseReleaseEvent(QMouseEvent *myEvent)
{
    mousePress=false;
}


bool myWidget::eventFilter(QObject *object, QEvent *event)
{

    //判断窗口是否是登陆状态、是否正在游戏、如果窗口失去焦点变成非活动、自动暂停游戏
    if(object==this&&isGame&&!isLogin)
    {

        if(event->type()==QEvent::WindowDeactivate)
        {

            isActive=false;
            test->show();
            w->isGame=false;
            player->pause();
            emit pause();
            return true;
        }

    }
    return false;
}
