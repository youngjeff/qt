#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *openLayout, *buttonLayout;
    QLineEdit *openLineEdit;
    QLabel *openUrlLabel;
    QPushButton *pushButton1, *pushButton2;
};

#endif // WIDGET_H
