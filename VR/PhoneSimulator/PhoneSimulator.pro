
QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhoneSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainscreen.cpp \
    vrcontroller.cpp

HEADERS  += mainscreen.h \
    vrcontroller.h

FORMS    += mainscreen.ui
