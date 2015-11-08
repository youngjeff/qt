#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableView>
#include <QTableWidget>
#include <QPushButton>
#include <iostream>
#include <cstdio>
using namespace std;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QTableWidget *tablewidget;
    QPushButton *button;
    QPushButton *rebutton;
    void start();
    void Refresh();
    void print( int (*a)[9] );
    void ConfirmCandidate( int (*a)[9], int i, int j );
    void TotalNumbers( int (*a)[9], int i, int j );
    bool JudgeValue( int (*a)[9],int i, int j );
    bool success( int(*a)[9], int i, int j );

};

#endif // WIDGET_H
