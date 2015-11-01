#include "mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("XMl Reader");

    treeWidget = new QTreeWidget(this);
    QStringList headers;
    headers << "Items" << "pages";
    treeWidget->setHeaderLabels(headers);
    setCentralWidget(treeWidget);
    readFile("./XML");
}

MainWindow::~MainWindow()
{

}
void MainWindow::readFile(const QString &fileName)
{
    currentItem = 0;

      QFile file(fileName);
      QXmlInputSource inputSource(&file);
      QXmlSimpleReader reader;
      reader.setContentHandler(this);
      reader.setErrorHandler(this);
}
bool MainWindow::startElement(const QString &, const QString &, const QString &qName, const QXmlAttributes &attributes)
{
    if(qName == "entry")
    {
        currentItem = new QTreeWidgetItem(currentItem ?
                      currentItem : treeWidget->invisibleRootItem());

    }else if(qName == "page"){
        currentText.clear();
    }
    return true;
}
bool MainWindow::characters(const QString &str)
{
    currentText += str;
    return true;
}
bool MainWindow::endElement(const QString &, const QString &, const QString &qName)
{
    if(qName == "entry"){
        currentItem =currentItem->parent();

    }else if(qName == "page")
    {
        if(currentItem){
            QString allpages = currentItem->text(1);
            if(!allpages.isEmpty())
                allpages += ",";
                        allpages +=currentText;
            currentItem->setText(1,allpages);
        }
    }
    return true;
}
bool MainWindow::fatalError(const QXmlParseException &exception)
{
    QMessageBox::critical(this,
                             tr("SAX Error"),
                             tr("Parse error at line %1, column %2:\n %3")
                             .arg(exception.lineNumber())
                             .arg(exception.columnNumber())
                             .arg(exception.message()));
    return false;
}

















