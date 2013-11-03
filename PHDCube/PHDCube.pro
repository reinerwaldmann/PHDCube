#-------------------------------------------------
#
# Project created by QtCreator 2013-10-31T14:52:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG+=console

TARGET = PHDCube
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphicalwidget.cpp

HEADERS  += mainwindow.h \
    graphicalwidget.h \
    consolemsg.h

FORMS    += mainwindow.ui \
    graphicalwidget.ui
