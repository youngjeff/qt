#-------------------------------------------------
#
# Project created by QtCreator 2015-11-01T21:15:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThreadTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    workerthread.cpp

HEADERS  += mainwindow.h \
    workerthread.h
