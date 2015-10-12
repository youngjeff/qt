#include "spinboxdelegate.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QMessageBox>
#include "boxdelegate.h"
SpinBoxDelegate::SpinBoxDelegate(QWidget *parent)
    : QWidget(parent)
{
    QStringList data;
    data << "0" << "1" << "2";
    model = new QStringListModel(this);
    model->setStringList(data);

    listView = new QListView(this);
    listView->setModel(model);
    listView->setItemDelegate(new BoxDelegate(listView));//new 操作符并不会真的创建编辑器实例。相反，只有在真正需要时，Qt 才会生成一个编辑器实例。这保证了程序运行时的性能。


    QPushButton *btnShow = new QPushButton(tr("Show Model "),this);
    connect(btnShow,&QPushButton::clicked,this,&SpinBoxDelegate::showModel);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(btnShow);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(listView);
    layout->addLayout(buttonLayout);
    setLayout(layout);
}

SpinBoxDelegate::~SpinBoxDelegate()
{

}
void SpinBoxDelegate::showModel()
{
    QStringList list;
    list = model->stringList();//获取字符串信息
    QString information;
    foreach (QString data, list) {
        information += data + "\n";
    }
    QMessageBox::information(this,"show me",information,QMessageBox::Ok);
}
