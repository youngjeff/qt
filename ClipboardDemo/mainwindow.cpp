#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QClipboard>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *northLayout = new QHBoxLayout;
    QHBoxLayout *southLayout = new QHBoxLayout;

    QTextEdit *editor = new QTextEdit;
    QLabel *label = new QLabel;
    label->setText("Text Iuput :");
    label->setBuddy(editor);
    QPushButton *copyButton = new QPushButton;
    copyButton->setText("set clipboard");
    QPushButton *pasteButton = new QPushButton;
    pasteButton->setText("Get Clipboard");

    northLayout->addWidget(label);
    northLayout->addWidget(editor);
    southLayout->addWidget(copyButton);
    southLayout->addWidget(pasteButton);
    mainLayout->addLayout(northLayout);
    mainLayout->addLayout(southLayout);
    setLayout(mainLayout);
    connect(copyButton,&QPushButton::clicked,this,&MainWindow::setClipboardContent);
    connect(pasteButton,&QPushButton::clicked,this,&MainWindow::getClipBoardCentent);
}

MainWindow::~MainWindow()
{

}
void MainWindow::setClipboardContent()//
{
    QClipboard *board = QApplication::clipboard();//返回与剪贴板交互的对象 系统与应用程序交互
    //clipboard获得系统剪贴板对象
    board->setText("Text Qt from Application");//获取剪贴板里面的信息
//    QMessageBox::information(NULL,"From clipboard",str);
}
void MainWindow::getClipBoardCentent()
{
    QClipboard *board = QApplication::clipboard();
    QString str = board->text();
    QMessageBox::information(NULL,"From clipboard",str);
}
