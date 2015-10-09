#ifndef WIDGET_H
#define WIDGET_H
#include <QPushButton>
#include <QWidget>
#include <QTextEdit>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *button;
     QTextEdit * textedit;
private slots:
    void onSet();
};

#endif // WIDGET_H
