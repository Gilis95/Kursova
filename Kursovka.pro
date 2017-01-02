QT += core
QT -= gui

TARGET = Kursovka
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    date.cpp \
    student.cpp

HEADERS += \
    student.h \
    date.h \
    constants.h

