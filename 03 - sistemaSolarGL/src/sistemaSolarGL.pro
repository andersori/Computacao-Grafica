#-------------------------------------------------
#
# Project created by QtCreator 2018-04-24T13:48:01
#
#-------------------------------------------------

QT       += core gui opengl
LIBS     += -lOpengl32
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sistemaSolarGL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    esfera.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    esfera.h

FORMS    += mainwindow.ui
