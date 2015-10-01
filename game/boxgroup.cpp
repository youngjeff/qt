#include <QTimer>
#include <QKeyEvent>
#include <QTransform>
#include <QCursor>
#include "boxgroup.h"
#include "onebox.h"

boxGroup::boxGroup(QObject *parent)
{
    waring=false;                                                    //waring用来阻止boxGroup类响应键盘事件、以此避免键盘事件未完成而焦点转移到view造成的BUG
    setFlag(QGraphicsItem::ItemIsFocusable);
    oldTransform=transform();                                        //保存初始坐标位置、用来出现新方块的时候进行位置初始化
    rotate=0;
    timer=new QTimer(this);                                          //计时器、实现方块自动下移的功能
    connect(timer,SIGNAL(timeout()),this,SLOT(needOneStep()));
    currentBox=Anyone;                                               //设置当前方块为Anyone、既随机方块形状
    cursor=new QCursor(QPixmap(":/new/prefix1/test.png"));
    setCursor(*cursor);
}


bool boxGroup::isColliding()
{
    QList<QGraphicsItem*> itemList=childItems();
    QGraphicsItem* item;
    foreach (item, itemList)
    {
        if(item->collidingItems().count()>1)
        {
            return true;
        }
    }
    return false;
}



void boxGroup::createBoxGroup(const QPointF &point,boxType myBox)
{
    //初始化不同形状不同颜色的方块->（开始）
    static const QColor colorTable[7]={QColor(200,0,0,100),
                                 QColor(255,200,0,100),QColor(0,0,200,100),QColor(0,200,0,100),
                                 QColor(0,200,255,100),QColor(200,0,255,100),QColor(150,100,100,100)};
    int boxID=myBox;
    if(boxID==Anyone)
    {
        boxID=qrand()%7;
    }

    QList<oneBox*> boxList;
    setTransform(oldTransform);

    for(int i=0;i<4;i++)
    {
        oneBox* temp=new oneBox(colorTable[boxID]);
        boxList<<temp;
        addToGroup(temp);
    }

    switch(boxID)
    {
    case IBox:
        currentBox=IBox;
        boxList[0]->setPos(-30,-10);
        boxList[1]->setPos(-10,-10);
        boxList[2]->setPos(10,-10);
        boxList[3]->setPos(30,-10);
        break;
    case JBox:
        currentBox=JBox;
        boxList[0]->setPos(10,-10);
        boxList[1]->setPos(10,10);
        boxList[2]->setPos(-10,30);
        boxList[3]->setPos(10,30);
        break;
    case LBox:
        currentBox=LBox;
        boxList[0]->setPos(-10,-10);
        boxList[1]->setPos(-10,10);
        boxList[2]->setPos(-10,30);
        boxList[3]->setPos(10,30);
        break;
    case OBox:
        currentBox=OBox;
        boxList[0]->setPos(-10,-10);
        boxList[1]->setPos(10,-10);
        boxList[2]->setPos(-10,10);
        boxList[3]->setPos(10,10);
        break;
    case SBox:
        currentBox=SBox;
        boxList[0]->setPos(10,-10);
        boxList[1]->setPos(30,-10);
        boxList[2]->setPos(-10,10);
        boxList[3]->setPos(10,10);
        break;
    case TBox:
        currentBox=TBox;
        boxList[0]->setPos(-10,-10);
        boxList[1]->setPos(10,-10);
        boxList[2]->setPos(30,-10);
        boxList[3]->setPos(10,10);
        break;
    case ZBox:
        currentBox=ZBox;
        boxList[0]->setPos(-10,-10);
        boxList[1]->setPos(10,-10);
        boxList[2]->setPos(10,10);
        boxList[3]->setPos(30,10);
        break;
    default:break;
    }

    //初始化不同形状不同颜色的方块<-（结束）
    setPos(point);
    if(isColliding())
    {
        stopTimer();
        emit gameFinish();
    }
}



void boxGroup::clearBoxGroup(bool needDestory)
{
    QList<QGraphicsItem*> itemList=childItems();
    QGraphicsItem *item;
    foreach(item,itemList)
    {
        removeFromGroup(item);
        if(needDestory)
        {
            oneBox *box=(oneBox*)item;
            box->deleteLater();
        }
    }
}



QRectF boxGroup::boundingRect() const
{
    qreal penWidth=1;
    return QRectF(-40-penWidth/2,-40-penWidth/2,80+penWidth,80+penWidth);
}


//响应键盘事件、操作方块的动作
void boxGroup::keyPressEvent(QKeyEvent *event)
{
    if(waring) return;
    switch(event->key())
    {
    case Qt::Key_A:

        moveBy(-20,0);
        if(isColliding())
        {
            moveBy(20,0);
        }
        break;
    case Qt::Key_D:
        moveBy(20,0);
        if(isColliding())
        {
            moveBy(-20,0);
        }
        break;
    case Qt::Key_W:
        newTransform.rotate(90);
        setTransform(newTransform);
        if(isColliding())
        {
            newTransform.rotate(-90);
            setTransform(newTransform);
        }
        break;
    case Qt::Key_S:
        moveBy(0,20);
        if(isColliding())
        {
            moveBy(0,-20);
            clearBoxGroup();
            emit needNextGroup();
        }
        break;
    case Qt::Key_Return:
        moveBy(0,20);
        while(!isColliding())
        {
            moveBy(0,20);
        }
        moveBy(0,-20);
        clearBoxGroup();
        emit needNextGroup();
        break;
    case Qt::Key_Left:

        moveBy(-20,0);
        if(isColliding())
        {
            moveBy(20,0);
        }
        break;
    case Qt::Key_Right:
        moveBy(20,0);
        if(isColliding())
        {
            moveBy(-20,0);
        }
        break;
    case Qt::Key_Up:
        newTransform.rotate(90);
        setTransform(newTransform);
        if(isColliding())
        {
            newTransform.rotate(-90);
            setTransform(newTransform);
        }
        break;
    case Qt::Key_Down:
        moveBy(0,20);
        if(isColliding())
        {
            moveBy(0,-20);
            clearBoxGroup();
            emit needNextGroup();
        }
        break;
    case Qt::Key_Space:
        moveBy(0,20);
        while(!isColliding())
        {
            moveBy(0,20);
        }
        moveBy(0,-20);
        clearBoxGroup();
        emit needNextGroup();
        break;
    case Qt::Key_Z:
        emit pressZ();
    default:break;
    }


}


void boxGroup::needOneStep()
{
    moveBy(0,20);
    if(isColliding())
    {
        moveBy(0,-20);
        clearBoxGroup();
        emit needNextGroup();
    }
}

void boxGroup::startTimer(int interval)
{
    timer->start(interval);
}

void boxGroup::stopTimer()
{
    timer->stop();
}
