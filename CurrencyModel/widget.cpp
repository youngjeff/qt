#include "widget.h"

Widget::Widget(QObject *parent)
    : QAbstractTableModel(parent)
{

}

Widget::~Widget()
{

}
int Widget::rowCount(const QModelIndex &parent) const
{
    return currencyMap.count();//行和列都一样

}
int Widget::columnCount(const QModelIndex &parent) const
{
    return currencyMap.count();//行和列都一样
}
QVariant Widget::headerData(int section, Qt::Orientation , int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();//variant将数据封装,用的时候to()
    }
    return currencyAt(section);
}//处理数据 列的名字
void Widget::setCurrencyMap(const QMap<QString, double> &map)
{
//    beginResetModel();
    currencyMap = map;//设置底层数据
//    endResetModel();
}
//setCurrencyMap() 函数则是用于设置底层的实际数据。由于我们不可能将这种数据硬编码，所以我们必须为模型提供一个用于设置的函数
QVariant Widget::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())//如果这个模型索引是有效的，则返回真；否则返回假。
    {
        return QVariant();
    }
    if(role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight |Qt::AlignVCenter);//这个枚举类型是用来描述对齐。它包含可以结合的水平和垂直的标志，以产生所需的效果。

    }else if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        QString rowCurrency = currencyAt(index.row());
        QString columCurrency = currencyAt(index.column());

    if(currencyMap.value(rowCurrency) == 0.0)
    {
        return "####";
    }
    double amount = currencyMap.value(rowCurrency) / currencyMap.value(rowCurrency);
    return QString("%1").arg(amount,0,'f',4);
    }
    return QVariant();
}
QString Widget::currencyAt(int offset) const
{
    return (currencyMap.begin() + offset).key();
}
//key()转换格式QVariant.
Qt::ItemFlags Widget::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if(index.row() != index.column() ){
        flags =Qt::ItemIsEditable;
    }
    return flags;
}
bool Widget::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && index.row() != index.column() && role == Qt::EditRole)
    {
        QString columnCurrency = headerData(index.column(), Qt::Horizontal, Qt::DisplayRole).toString();
        QString rowCurrency = headerData(index.row(),Qt::Vertical,Qt::DisplayRole).toString();

        currencyMap.insert(columnCurrency , value.toDouble() * currencyMap.value(rowCurrency));

        emit dataChanged(index,index);
        return true;
    }
        return false;
}

