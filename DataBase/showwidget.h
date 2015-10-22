#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QObject>
#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
#include <QPushButton>
#include <QSqlRelationalTableModel>
#include "addwigdet.h"
#include "removewidget.h"
#include "findwidget.h"
#include "changewidget.h"

class ShowWidget :public QWidget
{
    Q_OBJECT
public:
    ShowWidget(QWidget *parent = 0);
    ~ShowWidget();
    QTableView * view;
    QSqlRelationalTableModel *model;
    QPushButton * addButton;
    QPushButton *removeButton;
    QPushButton * changeButton;
    QPushButton *findButton;
    QPushButton *flushButton;
private:
    void addEvent();
    void removeEvent();
    void changeEvent();
    void findEvent();
    bool connects();
    void flushEvent();
};

#endif // SHOWWIDGET_H
