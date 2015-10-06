#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QEvent>
#include <QGraphicsScene>
#include "food.h"
#include "snake.h"
class QGraphicsScene;
class QKeyEvent;
class Snake;
class Food;

class GameController :public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene &scene,QObject *parent = 0);
    ~GameController();

    void snakeAteFood(Snake *snake, Food *food);
//    void snakeAteFood(Snake *snake);
    void snakeAteItself(Snake *snake);

public slots:
    void gameOver();
    void pause();
    void resume();
protected:
    bool eventFilter(QObject *object, QEvent *event);
private:
    void handlekeyPressed(QKeyEvent *event);
    void addNewFood();

    Snake *snake;
    QGraphicsScene &scene;
    QTimer timer;

};

#endif // GAMECONTROLLER_H
