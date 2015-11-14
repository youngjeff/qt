#-------------------------------------------------
#
# Project created by QtCreator 2014-02-20T11:53:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlappyBird
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    bird.cpp \
    edge.cpp \
    barrier.cpp

HEADERS  += widget.h \
    bird.h \
    edge.h \
    Define.h \
    barrier.h

FORMS    += widget.ui

RESOURCES += \
    src.qrc
