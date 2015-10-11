#include "widget.h"

#include <QIcon>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(400,300);
    label = new QLabel(this);
    label->setFixedWidth(200);

    listWidget = new QListWidget(this);

    new QListWidgetItem(QIcon("./1.jpg"),tr("1"),listWidget);
    new QListWidgetItem(QIcon("./2.jpg"),tr("2"),listWidget);

            listWidget->addItem(new QListWidgetItem(QIcon("./3.jpg"),"3"));
            listWidget->addItem(new QListWidgetItem(QIcon("./4.jpg"),"4"));
            listWidget->addItem(new QListWidgetItem(QIcon("./5.jpg"),"5"));
            listWidget->addItem(new QListWidgetItem(QIcon("./6.jpg"),"6"));
            listWidget->addItem(new QListWidgetItem(QIcon("./7.jpg"),"7"));
            listWidget->addItem(new QListWidgetItem(QIcon("./8.jpg"),"8"));

            QListWidgetItem * newItem = new QListWidgetItem;
    newItem->setIcon(QIcon("./9.jpg"));
    newItem->setText("9");
    listWidget->insertItem(3,newItem);
    listWidget->setViewMode(QListView::IconMode);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(listWidget);

    setLayout(layout);
//    this->setLayout();
    connect(listWidget,SIGNAL(currentTextChanged(QString)),label,SLOT(setText(QString)));


}

Widget::~Widget()
{

}
