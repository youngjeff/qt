#include "mainwindow.h"
#include <QApplication>

#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();


    return a.exec();
}
