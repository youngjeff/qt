#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QString>
class DataTableWidegt : public QTableWidget
{
    Q_OBJECT

public:
    DataTableWidegt(QWidget *parent = 0);
    ~Widget();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragMoveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
private:
    void perfromDrag();
    QString selectionText() const;
    QString toHtml(const QString &plainText) const;
    QString toCsv (const QString &plainText) const;
    void fromCsv(const QString &csvText);

    QPoint startPos;

#endif // WIDGET_H
