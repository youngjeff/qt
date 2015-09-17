#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T14:04:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dictionary
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mainwindow.cpp \
    sizewidget.cpp \
    timeme.cpp

HEADERS  += widget.h \
    mainwindow.h \
    sizewidget.h \
    timeme.h

FORMS    += widget.ui \
    mainwindow.ui \
    sizewidget.ui \
    timeme.ui
