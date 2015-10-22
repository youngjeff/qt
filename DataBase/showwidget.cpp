#include "showwidget.h"
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlRelationalDelegate>
ShowWidget::ShowWidget(QWidget *parent)
    :QWidget(parent)
{
    resize(600,500);
    this->setWindowTitle("Database");
    this->setStyleSheet("background-color: rgb(0, 205, 255)");
    view = new QTableView(this);
    view->setGeometry(0,0,500,500);
    view->setStyleSheet("background-color: white;color:black");
    QVBoxLayout *vbox = new QVBoxLayout;
    QHBoxLayout *hbox = new QHBoxLayout;

    addButton = new QPushButton(this);
    addButton->setText("添加");
    addButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    removeButton = new QPushButton(this);
    removeButton->setText("删除");
    removeButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    changeButton = new QPushButton(this);
    changeButton->setText("修改");
    changeButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    findButton = new QPushButton(this);
    findButton->setText("查找");
    findButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    flushButton = new QPushButton(this);
    flushButton->setText("刷新");
    flushButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    vbox->addWidget(addButton);
    vbox->addWidget(changeButton);
    vbox->addWidget(removeButton);
    vbox->addWidget(findButton);
    vbox->addWidget(flushButton);
    hbox->addWidget(view);
    hbox->addLayout(vbox);
    this->setLayout(hbox);

        model = new QSqlRelationalTableModel;
        model->setTable("student");
        model->setSort(0,Qt::AscendingOrder);
        model->setRelation(4,QSqlRelation("city","id","name"));
        model->setHeaderData(0,Qt::Horizontal,"ID号");
        model->setHeaderData(1, Qt::Horizontal, "姓名");
        model->setHeaderData(2, Qt::Horizontal, "年龄");
        model->setHeaderData(3, Qt::Horizontal, "专业");
        model->setHeaderData(4, Qt::Horizontal, "城市");


        model->select();
//        model->removeColumn(0);
        view->setModel(model);
//        view->setSelectionMode(QAbstractItemView::NoEditTriggers);
        view->setSelectionBehavior(QAbstractItemView::SelectRows);
        QSqlQuery query;
       /*  query.exec("select name from student");
        int num = 0;

       while(query.next())
        {
            num++;
        }
        for(int i =0;i<=3;i++)
        {
            view->setColumnWidth(i,110);
        }
        for(int j = 0;j<num;j++)
        {
            view->setRowHeight(j,60);
        }*/

//        view->setItemDelegate(new QSqlRelationalDelegate(view));
    connect(addButton,&QPushButton::clicked,this,&ShowWidget::addEvent);
    connect(removeButton,&QPushButton::clicked,this,&ShowWidget::removeEvent);
    connect(findButton,&QPushButton::clicked,this,&ShowWidget::findEvent);
    connect(changeButton,&QPushButton::clicked,this,&ShowWidget::changeEvent);
    connect(flushButton,&QPushButton::clicked,this,&ShowWidget::flushEvent);
}
ShowWidget::~ShowWidget()
{

}
bool ShowWidget::connects()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./tables");
    db.open();
    return true;
}
void ShowWidget::addEvent()
{
    AddWigdet *addwidget = new AddWigdet;
    addwidget->show();
}
void ShowWidget::changeEvent()
{
    ChangeWidget *changewidget = new ChangeWidget;
    changewidget->show();
}
void ShowWidget::findEvent()
{
    FindWidget * findwidget = new FindWidget;
    findwidget->show();
}
void ShowWidget::removeEvent()
{
    RemoveWidget *removewidget = new RemoveWidget;
    removewidget->show();
}
void ShowWidget::flushEvent()
{
    connects();
    model->select();
}
