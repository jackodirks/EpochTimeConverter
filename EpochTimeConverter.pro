#-------------------------------------------------
#
# Project created by QtCreator 2013-01-22T20:57:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EpochTimeConverter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    epochtohuman.cpp \
    humantoepoch.cpp
PRECOMPILED_HEADER  = preCompiled.h

HEADERS  += mainwindow.h \
    Forms.h \
    epochtohuman.h \
    humantoepoch.h \
    preCompiled.h

FORMS    += mainwindow.ui \
    epochtohuman.ui \
    humantoepoch.ui
