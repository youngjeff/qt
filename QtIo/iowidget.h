#ifndef IOWIDGET_H
#define IOWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QPainter>
#include <QBrush>
#include <QMessageBox>
class IoWidget : public QWidget
{
    Q_OBJECT

public:
    IoWidget(QWidget *parent = 0);
    ~IoWidget();
    QPushButton *openButton;
    QTextEdit   *fileEdit;
     QString openString;
    QPushButton *readButton;
    void openfile();
    void readFile();
};

#endif // IOWIDGET_H
