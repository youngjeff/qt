/*-----------------------------------------------------------------------------------------------------
 * 本类继承于QGraphicsView、实现场景视图上的一切操作、并且响应boxGroup的消息、以及向主窗体传递消息
 * 满行小方块行的删除、清除方块后方块行的下移、技能的响应、分数的显示与更新、游戏结束的操作
 * --------------------------------------------------------------------------------------------------*/

#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
class boxGroup;
class QLabel;
class myPushButton;
class QMediaPlayer;
class centerSqlModel;
class QTableView;

class myView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit myView(QWidget *parent = 0);
    void JScore();                                              //使用技能的分数与能量清算
    void clearAll();                                            //技能消除所有行的实现
    bool isAllowJ();                                            //判断是否满足技能使用条件
    long getGameScore();                                        //返回游戏分数
    void newScore();                                            //用于游戏重新开始的分数能量初始化
    void clearNextBox();                                        //清除提示方块
    void installDialog();                                       //游戏结束提示窗口的实现
    void setParentWidget(QWidget* widget);                      //得到主窗体的指针
    void endWidget();                                           //同样是结束窗口的实现、因为作者问题才写成2个函数的

signals:
    void resendPressZ();                                        //讲暂停Z的按键消息发送给主窗体、暂停是在主窗体中实现的
    void gameIsOver();                                          //发送游戏结束消息给主窗体
    void closeAliWidget();                                      //发送关闭主窗体的消息给主窗体
    void gameIsRestart();                                       //游戏已经重新开始的消息

public slots:
    void recvievePressZ();                                      //接收来自boxGroup的Z按键信号、并且发送resendPressZ消息
    void closeWidget();

public slots:
    void startGame();
    void clearFullLines();                                      //清除满行方块
    void moveLines();                                           //清除满行方块后下移上面的方块
    void gameOver();                                            //游戏结束
    void pauseGame();                                           //暂停游戏
    void rePauseGame();                                         //回到游戏
    void reStartGame();                                         //输了后重新开始
    void newSlots();                                            //能量改变动画
    void abc();                                                 //single计时器的响应函数、设置allowJ为真

private:
    boxGroup *group;                                            //玩家当年操作的方块
    boxGroup *nextGroup;                                        //右上角提示方块、当需要下一个方块的时候赋值给group
    QGraphicsLineItem *lineItem1;                               //游戏4个边界判断碰撞、是透明的
    QGraphicsLineItem *lineItem2;
    QGraphicsLineItem *lineItem3;
    QGraphicsLineItem *lineItem4;
    qreal gameSpeed;                                            //控制自动下移事件间隔、即游戏速度
    QList<int> rows;                                            //满行的行数
    void initGame();                                            //游戏开始的一些布置
    void initView();                                            //场景的初始化
    void updateScore(const int fullRowNum=0);                   //根据满行消除更新分数
    int gameScore;                                              //游戏分数
    int gameEnergy;                                             //游戏能量
    int clearedNumber;                                          //总共消除的行数
    QWidget *showWidget,*parentWidget;                          //parentWidget接收父指针、showWidget可能已弃用
    QGraphicsTextItem *gameScoreText;                           //右下角的分数能量展示
    QGraphicsTextItem *gameEnergyText;
    QGraphicsTextItem *label1Text;
    QGraphicsTextItem *label2Text;
    bool JPress;                                                //判断是否是J按下造成的方块消除、是则不用updateScore更新分数、使用JScore方法更新分数
    bool allowJ;                                                //如果为假则不影响技能J按键、避免过快使用技能造成的BUG问题
    QDialog *box;                                               //以下为游戏开始时的排名显示窗口
    QLabel *label,*messageTitle;
    myPushButton *btn1,*btn2;
    QMediaPlayer *player;
    QCursor *cursor;
    centerSqlModel *maxModel,*allModel;
    QTableView *maxView,*allView;
    QLabel *maxLabel,*allLabel;
};

#endif // MYVIEW_H
