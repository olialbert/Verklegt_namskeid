QT += core
QT -= gui

TARGET = Qt_skil1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    programmers.cpp \
    ppinterface.cpp

HEADERS += \
    programmers.h \
    programmer.h \
    ppinterface.h

