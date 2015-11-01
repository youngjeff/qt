#include "widget.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <iostream>
#include <QVariantMap>
#include <QDebug>
#include <QMessageBox>
#include <QVBoxLayout>
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button = new QPushButton(this);
    QPushButton *tobutton = new QPushButton(this);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(button);
    vbox->addWidget(tobutton);
    this->setLayout(vbox);
    button->setText("clicked");
    tobutton->setText("clicked");
    connect(button,&QPushButton::clicked,this,&Widget::json);
    connect(tobutton,&QPushButton::clicked,this,&Widget::tojson);
}

Widget::~Widget()
{

}
void Widget::json()
{
    QString json("{"
            "\"encoding\" : \"UTF-8\","
            "\"plug-ins\" : ["
            "\"python\","
            "\"c++\","
            "\"ruby\""
            "],"
            "\"indent\" : { \"length\" : 3, \"use_space\" : true }"
            "}");
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8(), &error);//important
    if (error.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {//return true if return object
            QVariantMap result = jsonDocument.toVariant().toMap();//must be map
            cout << "encoding:" << result["encoding"].toString().toStdString();
            cout << "plugins:";

            foreach (QVariant plugin, result["plug-ins"].toList()) {
                cout << "\t-" << plugin.toString().toStdString();
            }//list

            QVariantMap nestedMap = result["indent"].toMap();
            cout<< "length:" << nestedMap["length"].toInt();
            cout << "use_space:" << nestedMap["use_space"].toBool();
        }
    } else {
        qFatal(error.errorString().toUtf8().constData());
        exit(1);
    }
}
void Widget::tojson()
{
    QVariantList people;

    QVariantMap bob;
    bob.insert("Name","Bob");
    bob.insert("Phonenumber",123);

    QVariantMap alice;
    alice.insert("Name","Alice");
    alice.insert("Phonenumber",321);

    people <<bob<<alice;
    QJsonDocument jsonDocument = QJsonDocument::fromVariant(people);
    if(!jsonDocument.isNull()){
        cout <<jsonDocument.toJson().toStdString();
    }
}












