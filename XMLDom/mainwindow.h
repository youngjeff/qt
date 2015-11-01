#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QDomElement>
#include <QTreeWidget>
#include <QTreeWidgetItem>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void readFile(const QString &filelName);
private:
    void parseBookindexElement(const QDomElement &element);
    //void parseEntryElement(const QDomElement &element,QTreeWidgetItem *parent);
    void parsePageElement(const QDomElement &element, QTreeWidgetItem *parent);
    void parseEntryElement(const QDomElement &element, QTreeWidgetItem *parent);
    QTreeWidget *treeWidget;
};

#endif // MAINWINDOW_H
