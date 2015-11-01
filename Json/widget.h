#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QTextEdit *edit;
    QPushButton *Button;
private:
    void json();
    void tojson();
};

#endif // WIDGET_H
