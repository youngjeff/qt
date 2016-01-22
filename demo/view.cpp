#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    ranks <<"体育"<<"教育"<<"财经"<<"社会"<<"娱乐"<<"军事"<<"国内"<<"科技"<<"互联网"<<"房产"<<"国际"<<"女人"<<"汽车"<<"游戏";
    ui->rankComboBox->addItems(ranks);

}

View::~View()
{
    delete ui;
}



void View::on_informComBoBox_currentTextChanged(const QString &arg1)
{

    QSqlQuery query,querys;
    QString  queryString;
    //QString  queryadd;
    queryString = QString("select word1,word2,word3,allsenten from inform where mainsenten = '%1'").arg(arg1);
    query.exec(queryString);

    while(query.next())
    {
        ui->onelineEdit->setText(query.value(0).toString());
        ui->twolineEdit->setText(query.value(1).toString());
        ui->threelineEdit->setText(query.value(2).toString());
        ui->textEdit->setPlainText(query.value(3).toString());
    }
}

void View::on_rankComboBox_currentIndexChanged(int index)
{
    ui->informComBoBox->clear();
    ui->onelineEdit->clear();
    ui->twolineEdit->clear();
    ui->threelineEdit->clear();
    ui->textEdit->clear();
    ranknumber = index;
    QSqlQuery query,querys;
    QString  queryString;
    //QString  queryadd;
    queryString = QString("select mainsenten from inform where rank = %1").arg(ranknumber);
    query.exec(queryString);

    while(query.next())
    {
        ui->informComBoBox->addItem(query.value(0).toString());
    }
}
