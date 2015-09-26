#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *btn1 = new QPushButton("one");
    QPushButton *btn2 = new QPushButton("two");
    QPushButton *btn3 = new QPushButton("three");
    QPushButton *btn4 = new QPushButton("four");

    QSpinBox *sinbox = new QSpinBox;
    QSlider *slider = new QSlider();
    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    layout->addWidget(btn4);
    layout->addWidget(sinbox);
    layout->addWidget(slider);
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
