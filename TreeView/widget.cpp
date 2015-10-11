#include "widget.h"
#include <QPushButton>
#include <QFileSystemModel>
#include <QTreeView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QModelIndex>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileSystemWatcher>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    model = new QFileSystemModel;//文件系统model
    model->setRootPath(QDir::currentPath());//设置filesystempath 为当前的路径,当前文件系统

    treeView = new QTreeView(this);
    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::currentPath()));//当前文件夹


    QPushButton *mkdirButton = new QPushButton(tr("Make Directory..."),this);
    QPushButton *rmButton = new QPushButton(tr("Remove"),this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(mkdirButton);
    buttonLayout->addWidget(rmButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(treeView);
    layout->addLayout(buttonLayout);

    setLayout(layout);
    setWindowTitle("File system Model");

    connect(mkdirButton,&QPushButton::clicked,this,&Widget::mkdir);
    connect(rmButton,&QPushButton::clicked,this,&Widget::rm);
}

Widget::~Widget()
{

}
void Widget::mkdir()
{
    QModelIndex Index = treeView->currentIndex();//获取当前选择的文件
    if(!Index.isValid()){
        return ;
    }
    QString dirName = QInputDialog::getText(this,"create Directory","Directory name");//创建一个新的文件夹
    if(!dirName.isEmpty())
    {
        if(!model->mkdir(Index,dirName).isValid()){

                QMessageBox::information(this,"Create Directory","Failed to create the directory");
        }

    }
}
void Widget::rm()
{
    QModelIndex index = treeView->currentIndex();
    if(!index.isValid()){
        return ;
    }
    bool ok;
    if(model->fileInfo(index).isDir()){
        ok = model->rmdir(index);
    }else{
        ok = model->remove(index);
    }
    if(!ok)
    {
         QMessageBox::information(this,tr("Remove"),tr("Failed to remove %1 %2").arg(model->fileName(index),"asda"));

    }
}
