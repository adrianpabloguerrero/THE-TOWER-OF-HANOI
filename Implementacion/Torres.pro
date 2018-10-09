#-------------------------------------------------
#
# Project created by QtCreator 2014-09-10T19:41:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Torres
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    escena.cpp \
    Disco.cpp \
    movimientos.cpp \
    dialog.cpp \
    dialog2.cpp


HEADERS  += mainwindow.h \
    Disco.h \
    Lista.h \
    pila.h \
    escena.h \
    movimientos.h \
    dialog.h \
    dialog2.h


FORMS    += mainwindow.ui \
    dialog.ui \
    dialog2.ui

RESOURCES += \
    Imagenes.qrc

