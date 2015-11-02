#include "mainwindow.h"
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    widget->setLayout(layout);
    lcdNumber = new QLCDNumber(this);
    layout->addWidget(lcdNumber);
    QPushButton *button = new QPushButton("start",this);
    layout->addWidget(button);
    setCentralWidget(widget);
    QTimer *timer = new QTimer(this);
    timer->start();
    timer->setInterval(1000);
    connect(timer,&QTimer::timeout,this,&MainWindow::display);

    WorkerThread * thread = new WorkerThread(this);
    connect(button,&QPushButton::clicked,this,&MainWindow::showTime);
    connect(thread,&WorkerThread::done,timer,&QTimer::stop);
    connect(thread,&WorkerThread::finished,thread,&WorkerThread::deleteLater);
}

MainWindow::~MainWindow()
{

}
void MainWindow::display()
{

    static int sec = 1;
    sec++;
    lcdNumber->display(QString::number(sec));
}
void MainWindow::showTime()
{
    timer->start(1);
    for(int i = 0; i < 2000000;i++)
    {
        timer->stop();
    }
}
