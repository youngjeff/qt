#include "search.h"
#include "ui_search.h"

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_clicked()
{
    ui->ComBoBox->clear();
    wordKey = ui->wordLineEdit->text();
    QSqlQuery query1,query2,query3;

    QString  queryString1,queryString2,queryString3;
    //QString  queryadd;
    queryString1 = QString("select mainsenten from inform where word1 = '%1'").arg(wordKey);
    query1.exec(queryString1);

    while(query1.next())
    {
        ui->ComBoBox->addItem(query1.value(0).toString());
    }
    queryString2 = QString("select mainsenten from inform where word2 = '%1'").arg(wordKey);
    query2.exec(queryString2);

    while(query2.next())
    {
        ui->ComBoBox->addItem(query2.value(0).toString());
    }
    queryString3 = QString("select mainsenten from inform where word3 = '%1'").arg(wordKey);
    query3.exec(queryString3);

    while(query3.next())
    {
        ui->ComBoBox->addItem(query3.value(0).toString());
    }
}

void Search::on_ComBoBox_currentIndexChanged(const QString &arg1)
{
    ui->TextEdit->clear();
    QSqlQuery query,querys;
    QString  queryString;
    //QString  queryadd;
    queryString = QString("select allsenten from inform where mainsenten = '%1'").arg(arg1);
    query.exec(queryString);

    while(query.next())
    {
        ui->TextEdit->setPlainText(query.value(0).toString());

    }
}
