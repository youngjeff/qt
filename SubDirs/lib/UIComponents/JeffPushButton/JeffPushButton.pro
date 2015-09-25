#-------------------------------------------------
#
# Project created by QtCreator 2015-09-06T10:10:49
#
#-------------------------------------------------

QT       += widgets

TARGET = JeffPushButton
TEMPLATE = lib

DEFINES += JEFFPUSHBUTTON_LIBRARY

SOURCES += jeffpushbutton.cpp

HEADERS += jeffpushbutton.h\
        jeffpushbutton_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
