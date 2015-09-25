#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QToolButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //绘制事件
    void paintEvent(QPaintEvent *event);
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
private slots:
    void closeApp();
private:
    //辅助函数
    int calcPosition(const QPoint& point);
    void setCursorType(int value);
private:
    Ui::MainWindow *ui;
    bool m_bLeftMouseButtonPressed;
    int m_lastPosition;
    QPoint m_ptLast;
    Qt::CursorShape m_currentCursor;
    QToolButton *m_closeButton;

};

#endif // MAINWINDOW_H
