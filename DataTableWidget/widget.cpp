#include "widget.h"
#include <QApplication>
#include <QMimeData>
#include <QDrag>
#include <QByteArray>
#include <QString>
#include <QtCore>
#include <QStringList>
DataTableWidegt::DataTableWidegt(QWidget *parent)
    : QTableWidget(parent)
{
    setAcceptDrops(true);
    setSelectionMode(ContiguousSelection);

    setColumnCount(3);//设置行数3
    setRowCount(5);//设置列数5

}

DataTableWidegt::~DataTableWidegt()
{

}
void DataTableWidegt::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        startPos = event->pos();
    }
    QTableWidget::mousePressEvent(event);
}
void DataTableWidegt::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button() && Qt::LeftButton)
    {
        int distance = (event->pos() - startPos).manhattanLength();
        if(distance >= QApplication::startDragDistance())
        {
            perfromDrag();
        }
    }
}

void DataTableWidegt::dragEnterEvent(QDragMoveEvent *event)
{
    DataTableWidegt *source = qobject_cast<DataTableWidegt*>(event->source());
    if(source && source != this )
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}
void DataTableWidegt::dragMoveEvent(QDragMoveEvent *event)
{
    DataTableWidegt *source = qobject_cast<DataTableWidegt *> (event->source());
    if(source && source != this)
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}
void DataTableWidegt::perfromDrag()
{
    QString selectedString = selectionText();
    if(selectedString.isEmpty() )
    {
        return ;
    }

    QMimeData *mimeData = new QMimeData;
    mimeData->setHtml(toHtml(selectedString));
    mimeData->setData(toCsv(selectedString).toUtf8());

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    if(drag ->exec(Qt::CopyAction | Qt::MoveAction) == Qt::MoveAction){
        selectionMode().clearSelection();
    }
}
void DataTableWidegt::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat())//event事件获取mimedata数据 hasFormat 获取文件格式
    {
        QByteArray csvData = event->mimeData()->data();//返回存储在指定的文件类型格式的MIME类型描述对象的数据。
        QString csvText = QString::fromUtf8(csvData); //将btye转为字符串
        fromCsv(csvText);
        event->acceptProposedAction();
    }
}
QString DataTableWidegt::selectionText() const
{
    QString seletionString;
    QString headerString ;
    QAbstractItemModel *itemModel = model();
    QTableWidgetSelectionRange selection = selectedRanges().at(0);
    for(int row = selection.topRow() , firstRow = row;
        row <= selection.bottomRow();row++)
    {
        for(int col = selection.leftColumn(); col <= selection.rightColumn();col++)
        {
            if(row == firstRow){
                headerString.append(horizontalHeaderItem(col)->text().append("\t"));
            }
            QModelIndex index = itemModel->index(row,col);
            seletionString.append(index.data().toString().append("\t"));
        }
        seletionString = seletionString.trimmed();
        seletionString.append("\n");
    }
    return headerString.trimmed() + "\n" +seletionString.trimmed();
}
QString DataTableWidegt::toHtml(const QString &plainText) const
{
#if QT_VERSION >= 0x050000
    QString result = plainText.toHtmlEscaped();
#else
    QString result = Qt::escape(plainText);
#endif
    result.replace("\t","<td>");
    result.replace("\n","\n<tr><td>");
    result.prepend("<table>\n</tr><td>");
    result.append("\n</table>");
    return result;
}

QString DataTableWidegt::toCsv(const QString &plainText) const
{
    QString result = plainText;
    result.replace("\\","\\\\");
    result.replace("\"", "\\\"");
    result.replace("\t", "\", \"");
    result.replace("\n", "\"\n\"");
    result.prepend("\"");
    result.append("\"");
    return result;
}
void DataTableWidegt::fromCsv(const QString &csvText)
{
    QStringList rows = csvText.split("\n");
    QStringList headers = rows.at(0).split(", ");
    for(int h = 0;h < headers.size();++h){
        QString header = headers.at(0);
        headers.replace(h,header.replace('"',""));
    }
    setHorizontalHeaderLabels(headers);
    for(int r = 1; r<rows.size();++r)
    {
        QStringList row = rows.at(r).split(", ");
        setItem(r -1,0,new QTableWidgetItem(row.at(0).trimmed().replace('"',"")));
        setItem(r -1,1,new QTableWidgetItem(row.at(1).trimmed().replace('"',"")));
    }
}
