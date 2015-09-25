#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDataStream>
#include <QByteArray>
#include <QIODevice>
#include <QMimeData>
#include <QDrag>
#include <QPixmap>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    QLabel *label=new QLabel(this);
    QPixmap pix("../yafeilinux.jpg");
    label->setPixmap(pix);
    label->resize(pix,size());
    label->move(100,100);
    label->setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //get the mouse sit,and make it into QLabel
    QLabel *child=static_cast<QLabel*>(childAt(event->pos()));
    if(!child->inherits("QLabel")) return;//if not the QLable,return
    QPixmap pixmap=*child->pixmap();//get the QLable pixture
    //second:make yourself MiME
    QByteArray itemData;//creat ByteArray
    QDataStream dataStream(&itemData,QIODevice::WriteOnly);//creat darastream
    //put the pixture information,site information input the byteArray
    dataStream<<pixmap<<QPoint(event->pos()-child->pos());
    //third,put the data into the QMimeData
    QMimeData *mimeData=new QMimeData;//creat QMimeData ,input the information
    mimeData->setData("myimage/png",itemData);

    //forth,put the QMime data input the QDrag
    QDrag *drag=new QDrag(this);//creat QDrag,use it move data
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);//when move the pixtrue,it usually show a squre
    drag->setHotSpot(event->pos()-child->pos());//move the mouse,the point will not change
    //fifth,put some things into the picture
    QPixmap tempPixmap=pixmap;//put shadow into pixtrue
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.end();
    child->setPixmap(tempPixmap);//add some effct
    //sixth,move
    if(drag->exec(Qt::CopyAction|Qt::MoveAction,Qt::CopyAction)==Qt::MoveAction)
        child->close(); //move and copy,usually it will coy
    else{
        child->show();//if copy the pixture,close the old
        child->setPixmap(pixmap);//set the pixture
    }
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    //if there is the mime data,then move
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else
    {
        event->ignore();
    }
}
void MainWindow::dragMoveEvent(QDropEvent *event)
{
    //move the event
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else
    {
        event->ignore();
    }
}
void MainWindow::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        QByteArray itemData=event->mimeData()->data("myimage/png");
        QDataStream dataStream(&itemData,QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint offset;
        //use the byteArray, put the data into the Qpixmap.Qpoint
        dataStream>>pixmap>>offset;
        QLabel *newLabel=new QLabel(this);
        //use the datastream,put the data into the QPixmap,QPoint
        newLabel->setPixmap(pximap);
        newLabel->resize(pixmap.size());
        newLabel->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();

    }
}
