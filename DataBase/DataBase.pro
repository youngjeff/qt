#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T20:06:25
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataBase
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    addwigdet.cpp \
    removewidget.cpp \
    changewidget.cpp \
    findwidget.cpp \
    showwidget.cpp

HEADERS  += widget.h \
    addwigdet.h \
    removewidget.h \
    changewidget.h \
    findwidget.h \
    showwidget.h
