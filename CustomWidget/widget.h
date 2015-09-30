#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QEvent>

class Widget : public QTextEdit
{
    Q_OBJECT

public:
    explicit Widget(QTextEdit *parent = 0);//如果不设置父类为空,则子类控件为父类的一个部分,可以了解它就是父类了
    ~Widget();
    bool event(QEvent *e);
   // QTextEdit *textEdit;
private:

};

#endif // WIDGET_H
