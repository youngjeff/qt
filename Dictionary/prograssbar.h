#ifndef PROGRASSBAR_H
#define PROGRASSBAR_H

#include <QWidget>
#include <QProgressBar>
#include <QString>
class PrograssBar :public QWidget
{
    Q_OBJECT

public:
    PrograssBar(QWidget *parent = 0);
    ~PrograssBar();
public:
    PrograssBar();
    QWidget *widgetMe = new QWidget();

    QProgressBar *prograssBarMe ;
    int value;
public slots:
    void timeMe();
};

#endif // PROGRASSBAR_H
