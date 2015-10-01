/*------------------------------------------------------------------
 * 继承自QSqlQueryModel
 * 子类化理由1：文字居中、子类化理由：重写头格式解决使用透明样式造成header黑化问题
 * ----------------------------------------------------------------*/


#ifndef CENTERSQLMODEL_H
#define CENTERSQLMODEL_H

#include <QSqlQueryModel>

class centerSqlModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit centerSqlModel(QObject *parent = 0);
    QVariant  data(const QModelIndex & item, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

signals:

public slots:

private:

};

#endif // CENTERSQLMODEL_H
