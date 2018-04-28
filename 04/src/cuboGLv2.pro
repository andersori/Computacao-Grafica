#-------------------------------------------------
#
# Project created by QtCreator 2018-04-26T15:41:25
#
#-------------------------------------------------

QT       += core gui opengl
LIBS     += -lOpengl32 -lglu32 #-lGLU
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cuboGLv2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    cubo.cpp \
    quadrado.cpp \
    matriz.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    cubo.h \
    quadrado.h \
    matriz.h

FORMS    += mainwindow.ui
