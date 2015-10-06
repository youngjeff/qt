#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGraphicsScene;
class QGraphicsView;

class GameController;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void adjustViewSize();//?

private:
    void initScene();//初始化场景
    void initSceneBackground();//初始化背景

    QGraphicsScene *scene;
    QGraphicsView *view;

    GameController *game;
};

#endif // MAINWINDOW_H
