#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->dial,SIGNAL(valueChanged(int)),this,SLOT(valueChanging()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::valueChanging()
{
    int value;
    value=ui->dial->value();
    QString valueString=QString::number(value);
    ui->lineEdit->setText(valueString);
}
