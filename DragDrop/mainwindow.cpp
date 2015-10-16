#include "mainwindow.h"
#include <QMimeData>
#include <QtCore>
#include <QList>
#include <QString>
#include <QUrl>
#include <qurl.h>
#include <iostream>
#include <iterator>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,400);
    textEdit = new QTextEdit;
    setCentralWidget(textEdit);

    textEdit->setAcceptDrops(false);//?
    setAcceptDrops(true);

}

MainWindow::~MainWindow()
{

}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)//鼠标拖动事件
{
    if(event->mimeData()->hasFormat("text/uri-list")){//Returns true if the object can return data
        event->acceptProposedAction();//获取对象的mime信息
    }//合理就接受文件
}
void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();//Returns a list of URLs contained within the MIME data object.
    if(urls.isEmpty()){
        return ;
    }
    QString fileName = urls.first().toLocalFile();//转换路径格式
    if(fileName.isEmpty()){
        return ;
    }
    if(readFile(fileName)){
        setWindowTitle(tr("%1,%2").arg(fileName,tr("Drag File")));
    }
    QList<QUrl>::iterator it;
    QList<QUrl> urlss= urls;


}
bool MainWindow::readFile(const QString &fileName)
{
    bool r= false;
    QFile file(fileName);
    QString content;
    if(file.open(QIODevice::ReadOnly))
    {
        content = file.readAll();
        r = true;
    }
    textEdit->setText(content);
    return r;
}
