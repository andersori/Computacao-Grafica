#-------------------------------------------------
#
# Project created by QtCreator 2018-04-23T14:43:52
#
#-------------------------------------------------

QT       += core gui opengl
LIBS     += -lOpengl32
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NaveGL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    desenho.cpp \
    nave.cpp \
    bala.cpp \
    inimigo.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    desenho.h \
    nave.h \
    bala.h \
    inimigo.h

FORMS    += mainwindow.ui
