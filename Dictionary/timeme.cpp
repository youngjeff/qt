#include "timeme.h"
#include "ui_timeme.h"

#include "widget.h"
TimeMe::TimeMe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeMe)
{
    ui->setupUi(this);

    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    timerMe = new QTimer();
    timerMe->setInterval(1000);
    timerMe->start();
    connect(timerMe,SIGNAL(timeout()),this,SLOT(showme()));
    countNumber = 0;
}

TimeMe::~TimeMe()
{
    delete ui;
}
void TimeMe::showme()
{
    countNumber += 10;
    if(countNumber == 100)
    {
        Widget *widgetMe = new Widget();
        widgetMe->show();
        this->close();
    }
    else
    {
        ui->progressBar->setValue(countNumber);
    }

}
