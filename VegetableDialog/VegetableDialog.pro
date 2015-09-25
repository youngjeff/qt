#-------------------------------------------------
#
# Project created by QtCreator 2015-03-17T21:09:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VegetableDialog
TEMPLATE = app


SOURCES += main.cpp\
        vegetabledialog.cpp \
    vegedialog.cpp \
    fruitdialog.cpp \
    meatdialog.cpp \
    specialdialog.cpp \
    paydialog.cpp \
    logindialog.cpp

HEADERS  += vegetabledialog.h \
    vegedialog.h \
    fruitdialog.h \
    meatdialog.h \
    specialdialog.h \
    paydialog.h \
    logindialog.h

FORMS    += vegetabledialog.ui \
    vegedialog.ui \
    fruitdialog.ui \
    meatdialog.ui \
    specialdialog.ui \
    paydialog.ui \
    logindialog.ui

RESOURCES += \
    picture.qrc
