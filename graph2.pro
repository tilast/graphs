#-------------------------------------------------
#
# Project created by QtCreator 2015-02-01T23:22:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = graph2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    graph.cpp

HEADERS  += mainwindow.h \
    node.h \
    graph.h

FORMS    += mainwindow.ui
