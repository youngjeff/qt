/*----------------------------------------------------------------------------------------------------------------------
 * 方块组类，用于容纳当前方块和下一个方块
 * 俄罗斯方块形状颜色的生成
 * 接收键盘消息，以完成俄罗斯方块对键盘的各种操作进行响应
 * 使用计时器开始和暂停游戏，计时器操作needOneStep
 * 碰撞检测，如果结束游戏则发送gameFinish信号，如何没有结束则发送
 * 使用QTransform完成对场景坐标的变换，实现俄罗斯方块的翻转
 * ----------------------------------------------------------------------------------------------------------------------*/


#ifndef BOXGROUP_H
#define BOXGROUP_H

#include <QGraphicsItemGroup>

class boxGroup :public QObject,public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit boxGroup(QObject *parent = 0);
    enum boxType{IBox,JBox,LBox,OBox,SBox,TBox,ZBox,Anyone};
    bool isColliding();                                                                //利用自带的方法判断是否发生碰撞
    void createBoxGroup(const QPointF &point=QPointF(0,0),boxType myBox=Anyone);       //初始化方块的形状颜色等
    void clearBoxGroup(bool needDestory=false);                                        //清除方块组中的方块、如果是重新开始、则删除之
    QRectF boundingRect() const;                                                       //方块组碰撞检测方位
    boxType getCurrentBox(){return currentBox;}
    bool waring;

protected:
    void keyPressEvent(QKeyEvent *event);

signals:
    void needNextGroup();                                                               //发送消息通知myview生成一个新的方块
    void gameFinish();                                                                  //发送消息通知myview游戏结束
    void pressZ();                                                                      //通知myview按下了暂停键

public slots:
    void needOneStep();                                                                 //响应计时器消息、实现自动下移
    void startTimer(int interval);
    void stopTimer();

private:
    boxType currentBox;                                                                 //当前方块
    QTransform oldTransform;                                                            //初始坐标系统
    QTransform newTransform;                                                            //新的坐标系统
    QTimer *timer;
    int rotate;                                                                         //已经启用的变量、忽略
    QCursor *cursor;
};

#endif // BOXGROUP_H
