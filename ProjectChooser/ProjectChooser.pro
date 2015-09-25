QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectChooser
TEMPLATE = app

HEADERS       = projectdialog.h \
                projectlistwidget.h

SOURCES       = main.cpp \
                projectdialog.cpp \
                projectlistwidget.cpp

FORMS         = projectdialog.ui

RESOURCES     = projectchooser.qrc
