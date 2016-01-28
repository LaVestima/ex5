#-------------------------------------------------
#
# Project created by QtCreator 2016-01-28T21:44:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ex5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shape.cpp \
    ellipse.cpp \
    rectangle.cpp \
    polygon.cpp \
    circle.cpp \
    square.cpp \
    triangle.cpp

HEADERS  += mainwindow.h \
    shape.h \
    ellipse.h \
    rectangle.h \
    polygon.h \
    circle.h \
    square.h \
    triangle.h

FORMS    += mainwindow.ui
