#-------------------------------------------------
#
# Project created by QtCreator 2015-09-06T13:07:16
#
#-------------------------------------------------

QT       += widgets

TARGET = UiPushButton
TEMPLATE = lib

DEFINES += UIPUSHBUTTON_LIBRARY

SOURCES += uipushbutton.cpp

HEADERS += uipushbutton.h\
        uipushbutton_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
