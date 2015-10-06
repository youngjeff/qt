#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "gamecontroller.h"
#include "food.h"
#include "snake.h"

GameController::GameController(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene),
    snake(new Snake(*this))
{
    timer.start( 1000/33 );
//    scene.clear();
    addNewFood();//food应该在这里建立才不会出错
    //Food *food = new Food(0,0);

   // scene.addItem(food);

    scene.addItem(snake);
    scene.installEventFilter(this);
    resume();

}

GameController::~GameController()
{
}

void GameController::snakeAteFood(Snake *snake, Food *food)
{
    scene.removeItem(food);//在画布上删除food
    delete food;    //在堆里删除food

    addNewFood();
}

void GameController::snakeHitWall(Snake *snake, Wall *wall)
{
}

void GameController::snakeAteItself(Snake *snake)
{
    QTimer::singleShot(0, this, SLOT(gameOver()));
}

void GameController::handleKeyPressed(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left:
            snake->setMoveDirection(Snake::MoveLeft);//改变参数来改变方向
            break;
        case Qt::Key_Right:
            snake->setMoveDirection(Snake::MoveRight);
            break;
        case Qt::Key_Up:
            snake->setMoveDirection(Snake::MoveUp);
            break;
        case Qt::Key_Down:
            snake->setMoveDirection(Snake::MoveDown);
            break;
        case Qt::Key_A:
            pause();
                break;
        case Qt::Key_S:
            resume();
        break;
    }
}

void GameController::addNewFood()
{
    int x, y;

    do {
        x = (int) (qrand() % 100) / 10;
        y = (int) (qrand() % 100) / 10;

        x *= 10;
        y *= 10;
    } while (snake->shape().contains(snake->mapFromScene(QPointF(x + 5, y + 5))));

    Food *food = new Food(x , y);//堆里创建food
    scene.addItem(food);    //场景里添加食物
}

void GameController::gameOver()
{
    scene.clear();

    snake = new Snake(*this);
    scene.addItem(snake);
    addNewFood();
}

void GameController::pause()
{
    disconnect(&timer, SIGNAL(timeout()),
               &scene, SLOT(advance()));
}

void GameController::resume()//更新蛇的状态
{
    connect(&timer, SIGNAL(timeout()),
            &scene, SLOT(advance()));//这个connect控制函数的调动advance(0,1)
}

bool GameController::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}
