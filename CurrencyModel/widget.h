#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QObject>
#include <QMap>
#include <QAbstractTableModel>
#include <QString>
class Widget : public QAbstractTableModel
{

public:
    Widget(QObject *parent = 0);
    ~Widget();
    void setCurrencyMap(const QMap<QString,double> &map);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
private:
    QString currencyAt(int offset) const;
    QMap<QString,double>currencyMap;
};

#endif // WIDGET_H
