#include "widget.h"
#include <QApplication>
#include <QTableView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMap <QString,double> data;
    data["NOK"] = 5.0000;
    data["NZD"] = 0.2254;
    data["SEK"] = 1.1991;
    data["SGD"] = 0.2592;
    data["USD"] = 0.0004;
    QTableView view;

    Widget *model = new Widget;
    model->setCurrencyMap(data);
    view.setModel(model);
    view.resize(600,400);
    view.show();

    return a.exec();
}
