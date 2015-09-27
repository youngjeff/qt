#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox msgBox;
    msgBox.setText("The document has been modified");//dialog的信息
    msgBox.setInformativeText(tr("do you wang to sve your changes?"));//dialog的判断信息
    msgBox.setDetailedText(tr("differcence here ..."));//detail信息
    msgBox.setStandardButtons(QMessageBox::Save|
    QMessageBox::Discard |QMessageBox::Cancel);//添加按钮
    msgBox.setDefaultButton(QMessageBox::Save);//设置默认的按钮
    int ret = msgBox.exec();//添加消息循环
    switch (ret) {
    case QMessageBox::Save:
        qDebug()<<"save document !";
        break;

    case QMessageBox::Discard:
        qDebug() <<"discard changes";
        break;
    case QMessageBox::Cancel:
        qDebug() <<"close document";
        break;}//进行判断
}

MainWindow::~MainWindow()
{
    delete ui;
}
