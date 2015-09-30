#include "mainwindow.h"
#include <QKeyEvent>
#include <iostream>
//#include <QDebug>
#include <QtDebug>
#include <QMessageBox>
#include <QtCore>
//#include <qdebug>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    this->setMaximumSize(400,400);
    this->setMinimumSize(400,400);

    textEdit = new QTextEdit(this);
    //setCentralWidget(textEdit);
    textEdit->setMaximumSize(400,400);
    textEdit->setMinimumSize(400,400);
    textEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{

}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == textEdit)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
//            qDebug()<<"ate key press"<<keyEvent->key();
//            qDebug("%d",keyEvent->key());
            cout<<"ate key press"<<keyEvent->key();

//            QMessageBox::information(this,tr("show me"),tr("text"));
//            textEdit->setText(QString::number(keyEvent->key()));
            return true;
        }else{
            return false;
        }
    }else{
        return QMainWindow::eventFilter(obj,event);
    }
}
