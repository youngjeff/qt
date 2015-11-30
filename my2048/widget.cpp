#include "widget.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    setMinimumSize(120,120);
    setGeometry(0,0,400,300);
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() -this->height())/2);
    bk.setRgb(0xbb, 0xad, 0xa0);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background,bk);
    this->setPalette(palette);
    // color table
    bkColor[0].setRgb(0xcd,0xc1,0xb5);
    bkColor[1].setRgb(0xee, 0xe4, 0xda);
    bkColor[2].setRgb(0xec, 0xe0, 0xc8);
    bkColor[3].setRgb(0xf2, 0xb1, 0x7b);
    bkColor[4].setRgb(0xf1, 0x93, 0x64);
    bkColor[5].setRgb(0xf5, 0x7c, 0x5f);
    bkColor[6].setRgb(0xf6, 0x5d, 0x3b);
    bkColor[7].setRgb(0xed, 0xcd, 0x72);
    bkColor[8].setRgb(0xec, 0xcc, 0x60);
    bkColor[9].setRgb(0xec, 0xc8, 0x50);
    bkColor[10].setRgb(0xed, 0xc5, 0x3f);
    bkColor[11].setRgb(0xee, 0xc2, 0x2e);
    bkColor[12].setRgb(0x8f, 0xed, 0x52);
    bkColor[13].setRgb(0x8f, 0xed, 0x52);
    bkColor[14].setRgb(0x8f, 0xed, 0x52);
    bkColor[15].setRgb(0x8f, 0xed, 0x52);

    ftColor[0].setRgb(0x00, 0x00, 0x00);
    ftColor[1].setRgb(0x7d, 0x74, 0x6b);
    ftColor[2].setRgb(0x75, 0x6c, 0x67);
    ftColor[3].setRgb(0xf8, 0xf5, 0xf0);
    ftColor[4].setRgb(0xfb, 0xf3, 0xf2);
    ftColor[5].setRgb(0xf9, 0xf7, 0xf2);
    ftColor[6].setRgb(0xfd, 0xf3, 0xf0);
    ftColor[7].setRgb(0xfc, 0xf0, 0xf0);
    ftColor[8].setRgb(0xf7, 0xf3, 0xf0);
    ftColor[9].setRgb(0xf3, 0xfd, 0xdc);
    ftColor[10].setRgb(0xff, 0xf4, 0xd7);
    ftColor[11].setRgb(0xfe, 0xf7, 0xe5);
    ftColor[12].setRgb(0xff, 0xff, 0xff);
    ftColor[13].setRgb(0xff, 0xff, 0xff);
    ftColor[14].setRgb(0xff, 0xff, 0xff);
    ftColor[15].setRgb(0xff, 0xff, 0xff);

    // Initialize the table number
    int i,j;
    memset(&array[0][0],0,sizeof(array));
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    i = qrand() % 4;
    j = qrand() % 4;
    array[i][j] = (qrand() % 2 + 1) * 2;
    do {
        i = qrand() % 4;
        j = qrand() % 4;
    }while (array[i][j] != 0);
    array[i][j] = (qrand() % 2 + 1) * 2;
    score=0;
    //button =new QPushButton(this);
    //connect(button,&QPushButton::clicked,this,&Widget::rebegin);
    isok = false;
}
Widget::~Widget()
{

}
void Widget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    rectSize = (width() < height() ? width() : height()) / 4;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);


    QPainter painter(this);
    QRectF rect;
    QFont font("Arial");
    QRectF rects;
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(ftColor[0]);
    painter.setFont(font);
    rects.setRect(300,0,100,50);
    painter.setBrush(QBrush(bkColor[0],Qt::SolidPattern));
    painter.drawText(rects, Qt::AlignCenter, "点击‘a’是菜单");
    int i,j,key;
    for( i = 0; i < 4; i++)
    {
        for(j = 0;j < 4;j++)
        {
            key = array[i][j];
            if(key != 0 )
                key = qLn(key) / qLn(2);
            // draw backgroud
            painter.setBrush(QBrush(bkColor[key],Qt::SolidPattern));
            painter.setPen(QPen(bk,rectSize * 0.1));
            rect.setRect(j * rectSize, i * rectSize, rectSize, rectSize);
            painter.drawRoundedRect(rect,30,30);
            // draw number
            if( array[i][j] <= 0)
                continue;
            // choose a suitable font size
            int digit = 0;
            int a = array[i][j];
            while(a)
            {
                a /= 10;
                digit ++;
            }
            switch (digit) {
            case 1:
            case 2:
                font.setPointSize(rectSize * 0.35);
                break;
            case 3:
                font.setPointSize(rectSize * 0.3);
                break;
            case 4:
                font.setPointSize(rectSize * 0.22);
                break;
            default:
                font.setPointSize(rectSize * 0.18);
                break;
            }
            painter.setPen(ftColor[key]);
            painter.setFont(font);
            painter.drawText(rect,Qt::AlignCenter,QString::number(array[i][j]));

        }
    }
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    // check whether game over
    if (isGameOver()){
        return ;                    }
    // check is it can be done
    memcpy(&arrayprey[0][0],&array[0][0],sizeof(array));
    //
    switch (event->key()) {

    case Qt::Key_A:
    {
       QMessageBox msgbox;
       msgbox.setWindowTitle("~~菜单~~");
       msgbox.setText("~~菜单~~  \nyes 重新开始 \n no是回到游戏");
       msgbox.setStandardButtons(QMessageBox::Yes);
       msgbox.addButton(QMessageBox::No);
       if(msgbox.exec() == QMessageBox::Yes)
       {
           rebegin();
           isok = true;
           break;
       }
       else{
            isok = true;
       }

         break;
    }

    case Qt::Key_Left:
        qDebug("Key_Left");
        for (int i = 0; i < 4; i++)
        {
            int j, k, key = 0;
            // move
            for (j = 0; j < 4; j++)
            {
                if (array[i][j] == 0)
                    continue;
                array[i][key++] = array[i][j];
            }
            // add
            for (j = 0, k = 0; j < key-1; j++, k++)
            {
                if (array[i][j] == array[i][j+1])
                {
                    array[i][k] = array[i][j] * 2;
                    score += array[i][k];
                    j++;
                }
                else
                    array[i][k] = array[i][j];
            }
            if (j == key - 1)
                array[i][k++] = array[i][j];
            // clear others
            for (j = k; j < 4; j++)
                array[i][j] = 0;
        }
        break;
    case Qt::Key_Right:
        qDebug("Key_Right");
        for (int i = 0; i < 4; i++)
        {
            int j, k, key = 0;
            // move
            for (j = 4-1; j >= 0; j--)
            {
                if (array[i][j] == 0)
                    continue;
                array[i][4-1-key++] = array[i][j];
            }
            // add
            for (j = 4-1, k = 4-1; j > 4-key; j--, k--)
            {
                if (array[i][j] == array[i][j-1])
                {
                    array[i][k] = array[i][j] * 2;
                    score += array[i][k];
                    j--;
                }
                else
                    array[i][k] = array[i][j];
            }
            if (j == 4-key)
                array[i][k--] = array[i][j];
            // clear others
            for (j = k; j >= 0; j--)
                array[i][j] = 0;
        }
        break;
    case Qt::Key_Up:
        qDebug("Key_Up");
        for (int j = 0; j < 4; j++)
        {
            int i, k, key = 0;
            // move
            for (i = 0; i < 4; i++)
            {
                if (array[i][j] == 0)
                    continue;
                array[key++][j] = array[i][j];
            }
            // add
            for (i = 0, k = 0; i < key-1; i++, k++)
            {
                if (array[i][j] == array[i+1][j])
                {
                    array[k][j] = array[i][j] * 2;
                    score += array[k][j];
                    i++;
                }
                else
                    array[k][j] = array[i][j];
            }
            if (i == key - 1)
                array[k++][j] = array[i][j];
            // clear others
            for (i = k; i < 4; i++)
                array[i][j] = 0;
        }
        break;
    case Qt::Key_Down:
        qDebug("Key_Down");
        for (int j = 0; j < 4; j++)
        {
            int i, k, key = 0;
            // move
            for (i = 4-1; i >= 0; i--)
            {
                if (array[i][j] == 0)
                    continue;
                array[4-1-key++][j] = array[i][j];
            }
            // add
            for (i = 4-1, k = 4-1; i > 4-key; i--, k--)
            {
                if (array[i][j] == array[i-1][j])
                {
                    array[k][j] = array[i][j] * 2;
                    score += array[k][j];
                    i--;
                }
                else
                    array[k][j] = array[i][j];
            }
            if (i == 4-key)
                array[k--][j] = array[i][j];
            // clear others
            for (i = k; i >= 0; i--)
                array[i][j] = 0;
        }
        break;
    default:
        break;
    }
    // if the array is game as prev,the down is not ok
    if(memcmp(&arrayprey[0][0],&array[0][0],sizeof(array)) == 0)
    {
        return ;
    }
    else{
        qDebug("score:%d",score);
    }
    // give a new rand number




    if(!isok){
    qsrand (QTime(0,0,0).secsTo(QTime::currentTime()));
    int i,j;
    do{
        i = qrand() % 4 ;
        j =qrand() % 4;
    }while(array[i][j] != 0 );
    array[i][j] = (qrand() % 2 +1 ) * 2;
    update(); // repaint the widget
    }
    isok = false;
}

bool Widget::isGameOver()
{
    for (int i=0;i < 4;i++)
    {
        for (int j = 0;j <3;j++)
        {
            if (array[i][j] == array[i][j+1] || array[i][j] == 0)
            {
                return false;
            }
        }
        if (array [i][3] == 0)
            return false;
    }
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 4;j++)
        {
            if (array[i][j] == array[i+1][j])
            {
                return false;
            }
        }
    }
    QMessageBox::information(this,"game over","游戏结束!!");
    rebegin();
    return true;
}

void Widget::rebegin()
{
    int i,j;
    memset(&array[0][0],0,sizeof(array));
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    i = qrand() % 4;
    j = qrand() % 4;
    array[i][j] = (qrand() % 2 + 1) * 2;
    do {
        i = qrand() % 4;
        j = qrand() % 4;
    }while (array[i][j] != 0);
    array[i][j] = (qrand() % 2 + 1) * 2;
    score=0;
    update();
}










