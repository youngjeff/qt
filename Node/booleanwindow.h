#ifndef BOOLEANWINDOW_H
#define BOOLEANWINDOW_H

#include <booleanmodel.h>
#include <booleanparser.h>
#include <widget.h>
#include <QLabel>
#include <QTreeView>
#include <QLineEdit>
#include <QWidget>
class BooleanWindow :public QWidget
{
    Q_OBJECT
public:
    BooleanWindow();
    ~BooleanWindow();
    QLabel *label;
    QLineEdit *lineEdit;
    BooleanModel *booleanModel;
    QTreeView *treeView;
    void booleanExpressionChanged(const QString &expr);
};

#endif // BOOLEANWINDOW_H
