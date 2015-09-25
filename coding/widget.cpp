#include "widget.h"
#include "ui_widget.h"
#include <QProcess>
#include <qprocess.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

            QString program = "sh /home/jeff/Documents/TestMyScript/auto.sh";
            QStringList arguments;

            arguments << "/a.txt";

            QProcess *myProcess = new QProcess();
            myProcess->start(program, arguments); // 或者用startDetached()

}
