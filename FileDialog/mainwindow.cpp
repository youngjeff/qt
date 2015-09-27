#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *openAction = new QAction(tr("打开文件"),this);
    openAction->setStatusTip(tr("open file"));
    QAction *saveAction = new QAction(tr("保存文件"),this);
    saveAction->setStatusTip(tr("save file"));

    QMenu *file = menuBar()->addMenu(tr("选择"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolbar =addToolBar(tr("工具栏"));
    toolbar->addAction(openAction);
    toolbar->addAction(saveAction);

   textedit = new QTextEdit(this);
    setCentralWidget(textedit);//可以在中间显示textedit
    connect(openAction,&QAction::triggered,this,&MainWindow::openFile);//点击事件是triggered
    connect(saveAction,&QAction::triggered,this,&MainWindow::saveFile);



}

MainWindow::~MainWindow()
{
    delete ui;
//    delete
}
void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,tr("open file"),".",
                                                tr("Text Files(*)"));//打开文件的函数

    if(!path.isEmpty())
    {
        QFile file(path);//创建这个文件
        if(!file.open(QIODevice::ReadWrite |QIODevice::Text))
        {
            QMessageBox::warning(this,tr("write file"),tr("cannot open file:\n%1").arg(path));
            return;
        }

         QTextStream in(&file);
         textedit->setText(in.readAll());
         file.close();
    }//输入文件内容,用的是 textstream的readall函数
    else{
        QMessageBox::warning(this,tr("path"),tr("you did not select any file."));

    }

}
void MainWindow::saveFile()
{

    QString path = QFileDialog::getSaveFileName(this,tr("open file"),".");
    if(!path.isEmpty())
    {

        QFile file(path);
        if(!file.open(QIODevice::ReadWrite|QIODevice::Text)){
            QMessageBox::warning(this,tr("write file"),tr("cannot open file:\n%1").arg(path));
            return ;
        }
        QTextStream out(&file);
        out<<textedit->toPlainText();//输出文件内容,toplaintext获取文件内容

        file.close();

    }else
    {
        QMessageBox::warning(this,tr("path"),tr("you did not select a file"));

    }
}
