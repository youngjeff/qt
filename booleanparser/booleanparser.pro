TEMPLATE      = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS       = booleanmodel.h \
                booleanparser.h \
                booleanwindow.h \
                node.h
SOURCES       = booleanmodel.cpp \
                booleanparser.cpp \
                booleanwindow.cpp \
                main.cpp \
                node.cpp
