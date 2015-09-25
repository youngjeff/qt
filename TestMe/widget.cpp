#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setMaximumSize(800, 600);
    this->setMinimumSize(800, 600);

    mainLayout = new QVBoxLayout(this);
    openLayout = new QHBoxLayout;
    buttonLayout = new QHBoxLayout;

    openUrlLabel = new QLabel;
    openUrlLabel->setText(tr("URL:"));
    openLineEdit = new QLineEdit;
    openLineEdit->setPlaceholderText(tr("Please input text !"));

    pushButton1 = new QPushButton;
    pushButton1->setText(tr("Test Button 1"));
    pushButton2 = new QPushButton;
    pushButton2->setText(tr("Test Button 2"));

    openLayout->addWidget(openUrlLabel);
    openLayout->addWidget(openLineEdit);

    buttonLayout->addStretch();
    buttonLayout->addWidget(pushButton1);
    buttonLayout->addWidget(pushButton2);

    mainLayout->addLayout(openLayout);
    mainLayout->addLayout(buttonLayout);

    //pushButton->setGeometry(200, 200, 100, 50);
}

Widget::~Widget()
{
    delete pushButton1 ;
    delete pushButton2 ;
}
