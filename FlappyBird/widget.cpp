#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_scene = new QGraphicsScene;
    setScene(m_scene);
    m_scene->setSceneRect(3-width()/2,3-height()/2,width()-6,height()-6);

    m_bird = new Bird();
    m_scene->addItem(m_bird);
    m_bird->setPos(0,0);

    m_edge_1 = new Edge();
    m_scene->addItem(m_edge_1);
    m_edge_1->setPos(m_edge_1->boundingRect().width()/4,-height()/2+7);

    m_edge_2 = new Edge();
    m_scene->addItem(m_edge_2);
    m_edge_2->setPos(m_edge_2->boundingRect().width()/4,height()/2-7);
//    m_edge_2->rotate(180);
    m_edge_1->BeginMove();
    m_edge_2->BeginMove();


    hideButton();

    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(beginBarrier()));

    connect(m_bird,SIGNAL(died()),this,SLOT(onBirdDied()));

    for(int i=0;i<BARRIER_NUM;i++)
    {
        m_barr[i] = new Barrier();
        m_scene->addItem(m_barr[i]);
    }
    initBarrier();

    num = 0;

    QTimer::singleShot(3000,this,SLOT(delayBegin()));

    score = 0;
    ScoringTimer = new QTimer(this);
    connect(ScoringTimer,SIGNAL(timeout()),this,SLOT(Scoring()));

    settings = new QSettings("score.ini",QSettings::IniFormat);

    setWindowFlags(Qt::FramelessWindowHint);
}

Widget::~Widget()
{
    delete settings;
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    m_bird->ClickToFlay();

}

void Widget::initBarrier()
{
    for(int i=0;i<BARRIER_NUM;i++)
    {
        //上层障碍
        if(i%2==0)
        {
            m_barr[i]->isMain = true;
            m_barr[i]->setPos(EDGE_BOUNDING.width()/4+BARRIER_BOUNDING.width()/2,
                              -BARRIER_BOUNDING.height()/2-OK_WIDTH/2);
            m_barr[i]->lastPos = m_barr[i]->pos();
        }
        //下层障碍
        else
        {
            m_barr[i]->setPos(EDGE_BOUNDING.width()/4+BARRIER_BOUNDING.width()/2,
                              BARRIER_BOUNDING.height()/2+OK_WIDTH/2);
            m_barr[i]->lastPos = m_barr[i]->pos();
        }
    }
}

void Widget::beginBarrier()
{
    if(num == BARRIER_NUM/2)
    {
        m_timer->stop();
        return;
    }
    m_barr[2*num]->BeginMove();//up flow
    m_barr[2*num+1]->BeginMove();//down flow
    num++;

}

void Widget::showButton()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->label->show();
    ui->label_4->show();
    ui->label_2->show();
    ui->label_3->show();
}

void Widget::hideButton()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->label->hide();
    ui->label_4->hide();
    ui->label_2->hide();
    ui->label_3->hide();
}

void Widget::onBirdDied()
{
    showButton();
    ScoringTimer->stop();
    ui->label_2->setText(QString::number(score));
    if(settings->value("score").toInt()<score)
    {
        settings->setValue("score",score);
        ui->label_4->setText(QString::number(score));
    }else
    {
        ui->label_4->setText(QString::number(settings->value("score").toInt()));
    }
    score = 0;
//    scene()->update(scene()->sceneRect());

}

void Widget::on_pushButton_clicked()
{
    num = 0;
    initBarrier();
    m_bird->reBegin();
    m_bird->setPos(0,0);
    for(int i=0;i<BARRIER_NUM;i++)//barrier_num what's this
    {
        m_barr[i]->reBegin();
    }
    hideButton();
    QTimer::singleShot(3000,this,SLOT(delayBegin()));
    scene()->update(scene()->sceneRect());
}

void Widget::Scoring()
{
    score++;
}

void Widget::delayBegin()
{
    m_timer->start((EDGE_BOUNDING.width()/2+BARRIER_BOUNDING.width())/BARRIER_NUM*2/SPEED*1000);
    ScoringTimer->start((EDGE_BOUNDING.width()/2+BARRIER_BOUNDING.width())/BARRIER_NUM*2/SPEED*1000);
}

void Widget::on_pushButton_2_clicked()
{
    close();
}
