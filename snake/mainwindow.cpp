#include <QGraphicsView>
#include <QTimer>

#include "constants.h"
#include "gamecontroller.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      game(new GameController(*scene, this))
{
    setCentralWidget(view);
    resize(600, 600);

    initScene();
    initSceneBackground();

    QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::adjustViewSize()
{
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);//确保场景在视图内
}

void MainWindow::initScene()
{
    scene->setSceneRect(-100, -100, 200, 200);//设置场景大小
}

void MainWindow::initSceneBackground()
{
    QPixmap bg(TILE_SIZE, TILE_SIZE);//基本图形
//    QPainter p(&bg);//p 这个画刷来畫bg这个设备
//    p.setPen(QPen(Qt::gray));//设置背景
//    p.setBrush(QBrush(Qt::gray));//
//    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

    view->setBackgroundBrush(QBrush(bg));//将背景设为方格状,铺满整个设备
}
