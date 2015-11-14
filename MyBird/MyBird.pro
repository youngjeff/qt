#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T11:24:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyBird
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    barrier.cpp \
    bird.cpp \
    edge.cpp

HEADERS  += widget.h \
    barrier.h \
    bird.h \
    define.h \
    edge.h

FORMS    += widget.ui

RESOURCES += \
    src.qrc
