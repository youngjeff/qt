#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showText();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./myData");
    db.open();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    Add *myadd = new Add();
    myadd->show();
    //this->close();
}
void MainWindow::showText()
{
    ui->textEdit->setPlainText("系统有14个分类，可以索引，查看,和添加新的文档");
}

void MainWindow::on_pushButton_3_clicked()
{
    View *myview = new View();
    myview->show();
}

void MainWindow::on_pushButton_clicked()
{
    Search *mysearch = new Search();
    mysearch->show();
}
