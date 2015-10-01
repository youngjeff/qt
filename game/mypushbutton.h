/*------------------------------------------------------------------
 * 继承自QPushButton
 * 子类化理由：重写按钮的鼠标进入和鼠标离开事件、播放音效、也可以使用过滤器
 * ----------------------------------------------------------------*/

#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QWidget>
class QMediaPlayer;

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    myPushButton(const QString &text,QWidget *parent);
    myPushButton(QWidget *parent=0);
    myPushButton(const QString &text);

signals:

public slots:

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private:
    QMediaPlayer *player;
    QCursor *cursor;

};

#endif // MYPUSHBUTTON_H
