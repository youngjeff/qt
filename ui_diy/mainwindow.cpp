#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace
{
    const int g_padding = 4;
    int helperCalcPosition(int pos, int range)
    {
        return (pos < g_padding) ? 0 : ((pos > (range - g_padding)) ? 2 : 1);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_bLeftMouseButtonPressed = false;
    m_lastPosition = 11;
    m_currentCursor = Qt::ArrowCursor;


    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Window);
    //可获取鼠标跟踪效果
    setMouseTracking(true);
    ui->setupUi(this);

    m_closeButton = new QToolButton(this);
    m_closeButton->setGeometry(this->width() - 53, 5, 48, 48);
    m_closeButton->setFixedSize(48, 48);
    m_closeButton->setIcon(QIcon(":/images/close.png"));
    m_closeButton->setIconSize(QSize(48, 48));
    m_closeButton->setStyleSheet(QStringLiteral("background-color:transparent;"));
    m_closeButton->setToolTip(tr("关闭"));
    connect(m_closeButton, SIGNAL(clicked()), this, SLOT(closeApp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect titleBarRect(0, 0, this->width(), 58);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(20, 150, 210));
    painter.drawRect(titleBarRect);
    return;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_bLeftMouseButtonPressed = true;
    m_ptLast = event->globalPos();
    m_lastPosition = calcPosition(event->pos());
    event->ignore();
    return;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_bLeftMouseButtonPressed)
    {
        m_bLeftMouseButtonPressed = false;
    }
    event->ignore();
    return;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    setCursorType(calcPosition(event->pos()));
    if(m_bLeftMouseButtonPressed)
    {
        QPoint ptNew = event->globalPos();
        ptNew -= m_ptLast;
        if(11 == m_lastPosition) //拖动
        {
            ptNew += pos();
            move(ptNew);
        }
        else //调整大小
        {
            QRect rectWindow = geometry();
            switch(m_lastPosition)
            {
            case 00:
                rectWindow.setTopLeft(rectWindow.topLeft() + ptNew);
                break;
            case 02:
                rectWindow.setTopRight(rectWindow.topRight() + ptNew);
                break;
            case 20:
                rectWindow.setBottomLeft(rectWindow.bottomLeft() + ptNew);
                break;
            case 22:
                rectWindow.setBottomRight(rectWindow.bottomRight() + ptNew);
                break;
            case 10:
                rectWindow.setLeft(rectWindow.left() + ptNew.x());
                break;
            case 12:
                rectWindow.setRight(rectWindow.right() + ptNew.x());
                break;
            case 01:
                rectWindow.setTop(rectWindow.top() + ptNew.y());
                break;
            case 21:
                rectWindow.setBottom(rectWindow.bottom() + ptNew.y());
                break;
            //case 11:
            default:
                Q_ASSERT(0);
            }
            setGeometry(rectWindow);
            //qDebug() << rectWindow.topLeft() << ", " << rectWindow.bottomRight();
        }
        m_ptLast  = event->globalPos();
    }
    event->ignore();
    return;
}

void MainWindow::closeApp()
{
    qApp->quit();
}

int MainWindow::calcPosition(const QPoint &point)
{
    int row, column;
    row = helperCalcPosition(point.y(), rect().height());
    column = helperCalcPosition(point.x(), rect().width());
    return row * 10 + column;
}

void MainWindow::setCursorType(int value)
{
    Qt::CursorShape cursor;
    switch(value)
    {
    case 00:
    case 22:
        cursor = Qt::SizeFDiagCursor;
        break;
    case 02:
    case 20:
        cursor = Qt::SizeBDiagCursor;
        break;
    case 10:
    case 12:
        cursor = Qt::SizeHorCursor;
        break;
    case 01:
    case 21:
        cursor = Qt::SizeVerCursor;
        break;
    case 11:
        cursor = Qt::ArrowCursor;
        break;
    default:
        Q_ASSERT(0);
        break;
    }
    if(cursor != m_currentCursor)
    {
        m_currentCursor = cursor;
        setCursor(m_currentCursor);
    }
    return;
}
