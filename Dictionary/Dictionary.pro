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
    review.cpp

HEADERS  += widget.h \
    mainwindow.h \
    sizewidget.h \
    review.h

FORMS    += widget.ui \
    mainwindow.ui \
    sizewidget.ui
