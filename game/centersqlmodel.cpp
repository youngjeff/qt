#include "centersqlmodel.h"
#include <QColor>
#include <QSize>

centerSqlModel::centerSqlModel(QObject *parent) :
    QSqlQueryModel(parent)
{
}

QVariant centerSqlModel::data(const QModelIndex &item, int role) const
{
    QVariant value = QSqlQueryModel::data(item, role);
    if (role == Qt::TextAlignmentRole)
    {
        value = (Qt::AlignCenter);
        return value;
    }

    return value;
}

QVariant centerSqlModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole)
    {
        if(orientation==Qt::Vertical)
        {
            return QString(tr("%1").arg(section+1));
        }

        else
        {
            return QSqlQueryModel::headerData(section,orientation, role);
        }
    }
    else if(role==Qt::DecorationRole)
    {
        if(orientation==Qt::Vertical)
        {
            return QColor(184,7,235,100);
        }

        if(orientation==Qt::Horizontal)
        {
            return QColor(184,7,235,100);
        }
    }
    else return QVariant();
}
