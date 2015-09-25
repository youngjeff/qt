#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timerout,&QTimer::timeout,this,&MainWindow::showTime);
    timerout.setInterval(1000);
    timerout.start();
    Qhour=QTime::currentTime().hour();
    Qminute=QTime::currentTime().minute();
    Qsecond=QTime::currentTime().second();
    ui->hourLcdNumber->display(Qhour);
    ui->mintLcdNumber->display(Qminute);
    ui->secLcdNumber->display(Qsecond);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showTime()
{
    Qhour=QTime::currentTime().hour();
    Qminute=QTime::currentTime().minute();
    Qsecond=QTime::currentTime().second();
    ui->hourLcdNumber->display(Qhour);
    ui->mintLcdNumber->display(Qminute);
    ui->secLcdNumber->display(Qsecond);
}
