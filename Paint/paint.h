
#ifndef PAINT_H
#define PAINT_H
#include<QWidget>
#include<QPaintEvent>
#include<QKeyEvent>
#include<QTimer>
#include<QProgressBar>

enum Direct
{
    Up,
    Down,
    Left,
    Right
};
enum Result
{
    Win,
    Lose,
    Normal,
    Ready
};
class paint:public QWidget
{
    Q_OBJECT
    public:
        paint(QWidget*parent=0);
        ~paint();
        void init();
        int getrandnum();
    protected:
        void paintEvent(QPaintEvent* );
        void keyPressEvent(QKeyEvent *keyevent);
    public slots://protected better??
        void autorun();
    private:
        int snake[100][2];
        int food[2];
        int length;
        Result res;
        Direct dir;
        QTimer *timer;
        int count;
        int level;
        int speed;
        int randsuanzi;
        int jiou;
        QProgressBar *progress;
};
#endif
