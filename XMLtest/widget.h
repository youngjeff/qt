#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidget>
#include <QTreeView>
#include <QTreeWidgetItem>
#include <QXmlStreamReader>
#include <QMainWindow>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool readFile(const QString &fileName);
private:
    void readBookindexElement();
    void readEntryElement(QTreeWidgetItem *parent);
    void readPageElement(QTreeWidgetItem *parent);
    void skipUnkownElement();

    QTreeWidget *treeWidget;
    QXmlStreamReader reader;
};

#endif // WIDGET_H
