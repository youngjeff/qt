#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("hellow me"));

    //QPushButton *pushButton = new QPushButton(this);
    QAction *openAction = new QAction(tr("&open..."),this);//菜单下拉框
    QAction *fileAction = new QAction(tr("file..."),this);
    QAction *thisAction = new QAction(tr("this..."),this);
    QAction *twoAction = new QAction(tr("this..."),this);
//    openAction->setIcon("./ball.png");
//    openAction->setText(tr("showMe"));
//    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an exisiting file"));//设置提示词
    openAction->setShortcuts(QKeySequence::Open);//设置快捷键
    //fileAction->setFont(QFont::bold());
    fileAction->setStatusTip(tr("file"));
    thisAction->setIconText(tr("this"));
    thisAction->setStatusTip(tr("this"));
    connect(openAction,&QAction::triggered,this,&MainWindow::open);
    QMenu *file = menuBar()->addMenu(tr("&File"));//菜单选项
    file->addMenu(tr("showMe"));//添加菜单
    QMenu *file2 = file->addMenu(tr("file2"));

    file->addAction(openAction);//添加action
    file->addAction(fileAction);
    file->addAction(thisAction);
    file2->addAction(twoAction);

    QToolBar *toolbar =new QToolBar();

    toolbar =addToolBar("&file");
    toolbar->addAction(openAction);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::open()
{
    QMessageBox::information(this,tr("information"),tr("open"));
}
