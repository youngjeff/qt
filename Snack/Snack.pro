#-------------------------------------------------
#
# Project created by QtCreator 2015-10-03T15:59:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snack
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    food.cpp \
    gamecontroller.cpp \
    snake.cpp

HEADERS  += mainwindow.h \
    food.h \
    gamecontroller.h \
    snake.h \
    constants.h
