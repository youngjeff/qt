#include "mainwindow.h"

#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
        QVBoxLayout *layout = new QVBoxLayout();

        //QPushButton *pushButton = new QPushButton(this);
       // QLabel *label = new QLabel(this);
        //label->setWindowTitle("showMe");
        QSpinBox *spinBox = new QSpinBox(this);
        QSlider *slider = new QSlider(Qt::Horizontal,this);

       // slider->setGeometry(0,10,50,20);
        //spinBox->setGeometry(60,10,40,20);
        //layout->addWidget(pushButton);

        layout->addWidget(slider,10);
        //tlayout->addWidget(spinBox);
        layout->setStretch(10,10);
        layout->setSpacing(100);
        layout->addWidget(spinBox);
        //layout->addWidget(label);
        this->setLayout(layout);



        QObject::connect(slider,&QSlider::valueChanged,spinBox,&QSpinBox::setValue);
        void (QSpinBox:: *sinBoxSignal)(int ) = &QSpinBox::valueChanged;
        QObject::connect(spinBox,sinBoxSignal,slider,&QSlider::setValue);
        spinBox->setValue(35);




}

MainWindow::~MainWindow()
{

}
