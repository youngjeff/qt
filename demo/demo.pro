#-------------------------------------------------
#
# Project created by QtCreator 2016-01-19T22:46:58
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    add.cpp \
    view.cpp \
    search.cpp

HEADERS  += mainwindow.h \
    add.h \
    view.h \
    search.h

FORMS    += mainwindow.ui \
    add.ui \
    view.ui \
    search.ui
