/*-----------------------------------------------------------------------------------------------------
 * 本类继承于QWidget、为程序的主窗体、显示一些窗口版块、以及对于来自view消息的响应
 * 登陆注册界面、gif动画窗口、欢迎界面、游戏准备动画
 * --------------------------------------------------------------------------------------------------*/

#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
class QGraphicsWidget;
class myPushButton;
class myView;
class QLabel;
class QLineEdit;
class tipWidget;
class centerSqlModel;
class QTableView;
class QMediaPlayer;
class QMediaPlaylist;
class myLabel;

class myWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = 0);
    void setLook();                                                        //初始化并设置主窗口、并安装按键提示窗口
    void setLoginWidget();                                                 //初始化并设置登陆与注册窗口
    void sleep(unsigned int msec);                                         //旋转窗口秒数控制
    void helloWidget();                                                    //欢迎窗口的初始化
    void gifWidget();                                                      //蝴蝶飞行gif的窗口

signals:
    void pause();                                                          //游戏暂停消息
    void repause();                                                        //回到游戏消息

public slots:
    void receiveResendPressZ();                                            //接收Z键暂停消息、并显示暂停界面
    void setIsGame();                                                      //游戏结束后的一些收尾操作
    void receiveJEvent();                                                  //影响技能J按键
    void setLoginRotate();                                                 //登陆窗口的旋转
    void setRegisterRotate();                                              //注册窗口的旋转
    void loginGame();                                                      //登陆按钮响应与用户验证
    void registerUser();                                                   //注册账号的操作响应
    void readyText();                                                      //2个函数通过计时器的方式播放2张图片实现准备动画
    void goText();
    void goGame();                                                         //欢迎界面的登陆游戏按钮响应
    void setGameMusic();                                                   //准备音乐的播放、图片的显示、分数的更新

protected:
    void mousePressEvent(QMouseEvent *);                                   //3个函数实现窗口的拖动
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    bool eventFilter(QObject *, QEvent *);

private:
    void playGame();                                                       //初始化view并且接收来自view的消息或者向view发送消息
    //void titleLabel();
    myView *view;
    tipWidget *w;                                                          //坐标的操作提示界面
    QLabel *test;                                                          //暂停界面
    myPushButton *smallBtn;                                                //右上角关闭与最小化按钮
    myPushButton *closeBtn;
    QLabel *pixmapLabel;                                                   //左上角图标
    QLabel *titleLabel,*scoreShow;                                         //左上角游戏名和用户信息
    bool mousePress;                                                       //判断鼠标是否按下、用于窗口拖动实现
    bool isActive;
    bool isGame;                                                           //判断是否游戏中、不在游戏中则不响应暂停事件
    bool isLogin;                                                          //判断是否在登陆界面、不在则不影响暂停事件
    QPoint offset;                                                         //坐标、用于实现窗口拖动
    QGraphicsWidget *label1,*label2,*label3,*label4;                       //以下9行用于登陆注册窗口的实现
    QGraphicsWidget *line1,*line2,*line3,*line4;
    QGraphicsWidget *button1,*button2,*button3,*button4;
    QGraphicsWidget *titleLabel11,*titleLabel22;
    QGraphicsWidget *grapLoginWidget,*grapRegisterWidget;
    QLineEdit *userLine,*passwordLine,*setUserLine,*setPasswordLine;
    QLabel *userLineText,*passwordLineText,*setUserLineText,*setPasswordLineText;
    QLabel *setTitleLabel,*setTitleLabe2;
    myPushButton *loginBtn,*goRegisterBtn,*registerBtn,*goLoginBtn;
    QString userName;                                                      //以下2行用于登陆后保存用户信息
    int level,maxScore,allScore;
    QWidget *widget;
    centerSqlModel *maxModel,*allModel;                                    //以下4行用于实现欢迎界面的初始化
    QTableView *maxView,*allView;
    QLabel *maxLabel,*allLabel;
    myPushButton *start;
    QLabel *readyLabel;                                                    //游戏准备图片
    QMediaPlayer *player,*player2;                                         //以下2行用于音频实现
    QMediaPlaylist *playList;
    bool isRestartGame;                                                    //已经弃用参数、忽略
    QCursor *cursor;
    myLabel *gifLabel;                                                     //gif动画界面
};

#endif // MYWIDGET_H
