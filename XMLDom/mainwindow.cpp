#include "mainwindow.h"
#include <QStringList>
#include <QFile>
#include <QMessageBox>
#include <QTreeWidgetItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("XML DOM Reader");

    treeWidget = new QTreeWidget(this);
    QStringList headers;
    headers << "Items" << "pages" ;
    treeWidget->setHeaderLabels(headers);
    setCentralWidget(treeWidget);
    readFile("./XML");
}

MainWindow::~MainWindow()
{

}
void  MainWindow::readFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadWrite)){
        QMessageBox::critical(this,tr("Error"),tr("Cannot read file %1").arg(fileName));

    }
    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;
    if(!doc.setContent(&file,false,&errorStr,&errorLine,&errorColumn)){
        QMessageBox::critical(this,tr("Error"),tr("Parse error at line %1 ,column %2: %3")
                              .arg(errorLine).arg(errorColumn).arg(errorStr));

    }//read xml
    QDomElement root = doc.documentElement();
    if(root.tagName() != "bookindex"){
        QMessageBox::critical(this,tr("Error"),tr("Hot a bookindex file"));

    }
    parseBookindexElement(root);


}
void MainWindow::parseBookindexElement(const QDomElement &element)//start
{
    QDomNode child = element.firstChild();//find the start
    while(!child.isNull()){
        if(child.toElement().tagName() == "entry"){
            parseEntryElement(child.toElement(),treeWidget->invisibleRootItem());
        }
        child = child.nextSibling();
    }
}
void MainWindow::parseEntryElement(const QDomElement &element, QTreeWidgetItem *parent)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);//item
    item->setText(0,element.attribute("term"));//返回属性名。如果属性不存在defvalue返回。


    QDomNode child = element.firstChild();
    while(!child.isNull()){
        if(child.toElement().tagName() == "entry"){
            parseEntryElement(child.toElement(),item);//find child
        }else if(child.toElement().tagName() =="page")
        {
            parsePageElement(child.toElement(),item);
        }
        child = child.nextSibling();
    }//bianli
}//在 parseEntryElement() 函数中，我们创建了一个树组件的节点，其父节点是根节点或另外一个 entry 节点。接着我们又开始遍历这个 entry 标签的子标签。如果是 entry 标签，则递归调用自身，
//并且把当前节点作为父节点；否则则调用 parsePageElement() 函数

void MainWindow::parsePageElement(const QDomElement &element, QTreeWidgetItem *parent)
{
    QString page = element.text();
    QString allpages = parent->text(1);
    if(!allpages.isEmpty()){
        allpages +=",";
    }
    allpages += page;
    parent->setText(1,allpages);
}
//node logical
//element pysical















