# --------------------------------------------------
# Project created by freedomxura 2009-05-27T09:15:17
# The Qt version is Qt 4.5.1
# --------------------------------------------------
QT += sql
TARGET = key_new
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    ../SerialPort/ManageSerialPort.cpp \
    ../SerialPort/posix_qextserialport.cpp \
    ../SerialPort/qextserialbase.cpp \
    ../SerialPort/qextserialport.cpp
HEADERS += mainwindow.h \
    ../SerialPort/ManageSerialPort.h \
    ../SerialPort/posix_qextserialport.h \
    ../SerialPort/qextserialbase.h \
    ../SerialPort/qextserialport.h
FORMS += mainwindow.ui
OTHER_FILES += zhpy_table.db
QT += widgets
