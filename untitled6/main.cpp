#include "mainwindow.h"
#include <QApplication>

#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Enter your age");

    QSpinBox *spinBox = new QSpinBox(&w);

    QSlider *slider = new QSlider(Qt::Horizontal,&w);
    spinBox->setRange(0,130);
    slider->setRange(0,130);

    QObject::connect(slider,&QSlider::valueChanged,spinBox,&QSpinBox::setValue);
    void (QSpinBox:: *sinBoxSignal)(int ) = &QSpinBox::valueChanged;
    QObject::connect(spinBox,sinBoxSignal,slider,&QSlider::setValue);
    spinBox->setValue(35);


    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(slider);
    layout->addWidget(spinBox);

    w.setLayout(layout);
    w.show();


    return a.exec();
}
