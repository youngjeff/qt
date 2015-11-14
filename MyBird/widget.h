#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "bird.h"
#include "edge.h"
#include "barrier.h"
#include <QDebug>
#include <QSettings>
namespace Ui {
class Widget;
}

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void showButton();
    void hideButton();

private:
    Ui::Widget *ui;
    QGraphicsScene *m_scene;
    bird *m_bird;
    edge *m_edge_1;
    edge *m_edge_2;
    barrier *m_barr[BARRIER_NUM];
    QTimer *m_timer;
    int num;
    int score;
    QTimer *ScoringTimer;
    QSettings *settings;
protected:
    void mousePressEvent(QMouseEvent * event);

    void keyPressEvent(QKeyEvent *event);
private slots:
    void initBarrier();
    void beginBarrier();
    void onBirdDied();
    void Scoring();
    void delayBeigin();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // WIDGET_H


















