
QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = phonesimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainscreen.cpp \
    vrcontroller.cpp \
    notificationgetter.cpp

HEADERS  += mainscreen.h \
    vrcontroller.h \
    notificationgetter.h

FORMS    += mainscreen.ui


INCLUDEPATH += ../../headers

LIBS += -L../../lib/win64 -lopenvr_api

DESTDIR = ../bin/win64
