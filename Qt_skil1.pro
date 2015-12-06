QT += core
QT += sql
QT -= gui
QT += core sql


TARGET = Qt_skil1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ppinterface.cpp \
    data.cpp \
    programmer.cpp \
    utilities/scientistcomparator.cpp \
    utilities/utils.cpp \
    programmers.cpp

HEADERS += \
    programmer.h \
    ppinterface.h \
    data.h \ 
    utilities/constants.h \
    utilities/scientistcomparator.h \
    utilities/utils.h \
    computer.h \
    programmers.h
