/*------------------------------------------------------------------------------------------------------------------
 * 本类继承于QWidget、用于左边操作提示窗口的绘制与功能实现
 * ----------------------------------------------------------------------------------------------------------------*/
#ifndef TIPWIDGET_H
#define TIPWIDGET_H

#include <QWidget>
class myView;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QPushButton;
class QLabel;

class tipWidget : public QWidget
{
    Q_OBJECT
public:
    explicit tipWidget(QWidget *parent = 0,myView *view=0);
    void installWindow();                                            //窗体的初始化绘制
    void resetQss();                                                 //初始化窗体的QSS、共主窗口调用、以此解决游戏结束一瞬间造成的此窗体样式异常
    bool isGame;                                                     //判断是否在游戏中、不在游戏中本窗体不响应键盘事件

signals:
    void jPressEvent();                                              //因为J按键在此类中被截获、因此发送消息通知主窗体实现技能功能、理论上return false也可行

public slots:

protected:
    bool eventFilter(QObject *, QEvent *);                           //事件过滤器、根据按键操作提示窗口上的按钮会显示不同颜色

protected:
    myView *view;                                                    //接收场景视图的指针、以此在场景视图安装过滤器
    QGridLayout *buttonLayout;
    QPushButton *upBtn;
    QPushButton *downBtn;
    QPushButton *leftBtn;
    QPushButton *rightBtn;
    QLabel *moveLabel1;
    QVBoxLayout *vboxLayout1;
    QGridLayout *buttonLayout2;
    QPushButton *wBtn;
    QPushButton *sBtn;
    QPushButton *aBtn;
    QPushButton *dBtn;
    QLabel *moveLabel2;
    QPushButton *speedButton1;
    QPushButton *speedButton2;
    QLabel *spaceLabel;
    QVBoxLayout *vboxLayout;
    QPushButton *pauseButton;
    QLabel *pauseLabel;
    QPushButton *useButton;
    QLabel *useLabel;
    QCursor *cursor;
};

#endif // TIPWIDGET_H
