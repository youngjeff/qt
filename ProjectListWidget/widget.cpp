#include "widget.h"
#include <QApplication>
#include <QMimeData>
#include <QDrag>
#include <QListWidget>
Widget::Widget(QWidget *parent)
    : QListWidget(parent)
{
    setAcceptDrops(true);
}

Widget::~Widget()
{

}
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        startPos = event->pos();
    }
    QListWidget::mousePressEvent(event);
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        int distance = (event->pos() - startPos).manhattanLength();
        if(distance >= QApplication::startDragDistance())
            performDrag();
    }
    QListWidget::mouseMoveEvent(event);
}
void Widget::performDrag()
{
    QListWidgetItem *item = currentItem();
    if(item){
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(item->text());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setObjectName("use");
        if(drag->exec(Qt::MoveAction) == Qt::MoveAction)
            delete item;
    }
}
void Widget::dragMoveEvent(QDragMoveEvent *event)
{
    Widget *source = qobject_cast<Widget *>(event->source());
    if(source && source != this){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}
void Widget::dropEvent(QDropEvent *event)
{
    Widget *source = qobject_cast<Widget *>(event->source());
    if(source && source != this)
    {
        addItem(event->mimeData()->text());
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }

}
void Widget::dragEnterEvent(QDragEnterEvent *event)
{
    Widget *source =
            qobject_cast<Widget *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}
