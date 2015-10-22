#include "addwigdet.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QMessageBox>
AddWigdet::AddWigdet(QWidget *parent)
    :QWidget(parent)
{
    resize(500,200);
    this->setWindowTitle("添加");
    this->setStyleSheet("background-color: rgb(0, 205, 255);color:black");
    QHBoxLayout *hbox = new QHBoxLayout;
    QVBoxLayout *vbox = new QVBoxLayout;
    nameEdit = new QLineEdit;
    nameEdit->setPlaceholderText("输入姓名");
    ageEdit = new QLineEdit;
    ageEdit->setPlaceholderText("输入年龄");
    magerEdit = new QLineEdit;
    magerEdit->setPlaceholderText("输入专业");
    addressBox = new QComboBox;
    QStringList list;
    list <<"Beijing"<<"shanghai"<<"Nanjing"<<"Tianjin"<<"Wuhan"<<"Hangzhou"<<"Suzhou";
    list.append("Guangzhou");
    addressBox->addItems(list);
    addButton = new QPushButton;
    addButton->setText("添加");
    addButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    hbox->addWidget(nameEdit);
    hbox->addWidget(ageEdit);
    hbox->addWidget(magerEdit);
    hbox->addWidget(addressBox);
    vbox->addLayout(hbox);
    vbox->addWidget(addButton);
    this->setLayout(vbox);
    connect(addButton,&QPushButton::clicked,this,&AddWigdet::addEvent);
}
AddWigdet::~AddWigdet()
{

}
int AddWigdet::addEvent()
{
    QString nameString = nameEdit->text();
    int ageInt  = ageEdit->text().toInt();
    QString magerString = magerEdit->text();
    int num = addressBox->currentIndex() + 1;
    if(nameString == NULL  || magerString == NULL )
        return 0;
    QString queryString = QString("insert into student (name,age,mager,address) values ('%1','%2','%3','%4')").arg(nameString)
            .arg(ageInt).arg(magerString).arg(num);
    QSqlQuery query;
    query.exec(queryString);
    nameEdit->clear();
    ageEdit->clear();
    magerEdit->clear();
    addressBox->clear();
    QMessageBox::information(this,"yes","添加数据成功");
    return 0;
}
