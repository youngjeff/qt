#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAction>
#include <QIcon>
#include <QToolBar>
#include <QDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *openAction = new QAction(tr("&open..."),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip("open file");
    connect(openAction,&QAction::triggered,this,&MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&file"));
    file->addAction(openAction);

    QToolBar *toolbar = addToolBar(tr("&file"));
    toolbar->addAction(openAction);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::open()
{
//    QDialog dialog;
//    QDialog dialog(this);
//    dialog.setWindowTitle(tr("hello, new dialog"));

//    dialog.open();
//    dialog.show();
    //上述操作是将操作放在栈上
    QDialog *dialog = new QDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);//当对话框关闭时关闭对话框
    dialog->setWindowTitle(tr("hello you"));
    dialog->show();  //非模态对话框
//    dialog->open();//模态对话框
}
//指针创建是建立在堆上,对象是创建在栈上,堆和栈都要分配内存
