#include "widget.h"
#include <QStringList>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTreeWidgetItemIterator>
#include <QTreeWidgetItem>
#include <QStringRef>
#include <QtDebug>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(" XML Reader");

    treeWidget = new QTreeWidget(this);//treewidget only in mainwindow
    QStringList headers;
    headers << "Items" << "Pages ";//set header
    treeWidget->setHeaderLabels(headers);
    this->setCentralWidget(treeWidget);
    if(readFile("./XML")){
        cout<<"ok";
    }

}

MainWindow::~MainWindow()
{

}
bool MainWindow::readFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadWrite))
    {
        QMessageBox::critical(this,"no","no");

        return false;
    }
    else{

        cout<< "yes";
    }
    reader.setDevice(&file);//xmlreader
    while(!reader.atEnd())//every row judge
    {
        if(reader.isStartElement())//start
        {
            if(reader.name() == "bookindex")
            {
                readBookindexElement();
            }else{
                reader.raiseError(tr("not a valid bookindex"));

            }
        }else
        {
            reader.readNext();
        }
    }
    file.close();
    if(reader.hasError()){
        QMessageBox::critical(this,"Error",tr("Failed to parse file %1").arg(fileName));
        return false;
    }
    return true;

}
void MainWindow::readBookindexElement()
{
    Q_ASSERT(reader.isStartElement() && reader.name() == "bookindex");
    reader.readNext();
    while(!reader.atEnd())
    {
        if(reader.isEndElement()){
            reader.readNext();
            break;
        }

        if(reader.isStartElement()){
            if(reader.name() == "entry"){
                readEntryElement(treeWidget->invisibleRootItem());
            }else{
                skipUnkownElement();
            }
        }else{
            reader.readNext();
        }
    }
}
void MainWindow::readEntryElement(QTreeWidgetItem *parent)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0,reader.attributes().value("term").toString());

    reader.readNext();
    while(!reader.atEnd()){
        if(reader.isEndElement()){
            reader.readNext();
            break;
        }
        if(reader.isStartElement()){
            if(reader.name() == "entry"){
                readEntryElement(item);
            }else if(reader.name() == "page"){
                readPageElement(item);
            }else{
                skipUnkownElement();
            }
        }else{
            reader.readNext();
    }

    }
}

void MainWindow::readPageElement(QTreeWidgetItem *parent)
{
    QString page = reader.readElementText();
    if(reader.isEndElement())
    {
        reader.readNext();
    }
    QString allPages = parent->text(1);//eveny row will be read
    if(!allPages.isEmpty() ){
        allPages += ",";
    }
    allPages += page;
    parent->setText(1,allPages);
}
void MainWindow::skipUnkownElement()
{
    reader.readNext();//skip unkown
    while(!reader.atEnd()){
        if(reader.isEndElement()){
            reader.readNext();
            break;
        }

        if(reader.isStartElement()){
            skipUnkownElement();
        }else{
            reader.readNext();
        }
    }
}














