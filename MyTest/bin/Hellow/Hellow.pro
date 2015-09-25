#-------------------------------------------------
#
# Project created by QtCreator 2015-09-06T13:15:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hellow
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/UIComponents/UiPushButton/release/ -lUiPushButton
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/UIComponents/UiPushButton/debug/ -lUiPushButton
else:unix: LIBS += -L$$OUT_PWD/../../lib/UIComponents/UiPushButton/ -lUiPushButton

INCLUDEPATH += $$PWD/../../lib/UIComponents/UiPushButton
DEPENDPATH += $$PWD/../../lib/UIComponents/UiPushButton

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/UIComponents/UiPushButton/release/ -lUiPushButton
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/UIComponents/UiPushButton/debug/ -lUiPushButton
else:unix: LIBS += -L$$OUT_PWD/../../lib/UIComponents/UiPushButton/ -lUiPushButton

INCLUDEPATH += $$PWD/../../lib/UIComponents/UiPushButton
DEPENDPATH += $$PWD/../../lib/UIComponents/UiPushButton
