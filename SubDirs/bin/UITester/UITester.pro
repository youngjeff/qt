#-------------------------------------------------
#
# Project created by QtCreator 2015-09-06T10:09:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UITester
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/UIComponents/JeffPushButton/release/ -lJeffPushButton
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/UIComponents/JeffPushButton/debug/ -lJeffPushButton
else:unix: LIBS += -L$$OUT_PWD/../../lib/UIComponents/JeffPushButton/ -lJeffPushButton

INCLUDEPATH += $$PWD/../../lib/UIComponents/JeffPushButton
DEPENDPATH += $$PWD/../../lib/UIComponents/JeffPushButton
