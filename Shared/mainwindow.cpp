#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QBuffer>
#include <QPixmap>
#include <QDataStream>
#include <QDebug>
const char *KEY_SHARED_MEMORY = "shared";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      shareMemory(new QSharedMemory (KEY_SHARED_MEMORY,this))
{
    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    setCentralWidget(mainWidget);
    QPushButton *saveButton = new QPushButton(tr("save"),this);
    mainLayout->addWidget(saveButton);
    picLabel = new QLabel(this);
    mainLayout->addWidget(picLabel);
    QPushButton *loadButton = new QPushButton(tr("load"),this);
    mainLayout->addWidget(loadButton);
    connect(loadButton,&QPushButton::clicked,this,&MainWindow::share);
    connect(saveButton,&QPushButton::clicked,this,&MainWindow::get);

}

MainWindow::~MainWindow()
{

}
void MainWindow::share()
{
    if(shareMemory->isAttached()){
        shareMemory->detach();
    }
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pixmap(fileName);

    picLabel->setPixmap(pixmap);

    QBuffer buffer;
    QDataStream out(&buffer);
    buffer.open(QBuffer::ReadWrite);
    out << pixmap;
    int size = buffer.size();
    if(!shareMemory->create(size)){
        qDebug() <<tr("create Error:") <<shareMemory->errorString();
    }else{
        shareMemory->lock();
        char *to = static_cast<char*>(shareMemory->data());
        const char *from = buffer.data().constData();
        memcpy(to,from,qMin(size,shareMemory->size()));
        shareMemory->unlock();
    }
}
void MainWindow::get()
{
    if(!shareMemory->attach()){
        qDebug() <<tr("Attach Error:") << shareMemory->errorString();
    }else {
        QBuffer buffer;
        QDataStream in(&buffer);
        QPixmap pixmap;
        shareMemory->lock();
        const char* datas = static_cast<const char *>(shareMemory->constData());
        buffer.setData(datas,shareMemory->size());
        buffer.open(QBuffer::ReadWrite);
        in >> pixmap;
        shareMemory->unlock();
        shareMemory->detach();
        picLabel->setPixmap(pixmap);
    }
}


























