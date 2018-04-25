
QT       += core gui \
            network
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = phonesimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainscreen.cpp \
    vrcontroller.cpp \
    notificationhandler.cpp \
    notificationviewer.cpp

HEADERS  += mainscreen.h \
    vrcontroller.h \
    notificationhandler.h \
    notificationviewer.h

FORMS    += mainscreen.ui \
    notificationviewer.ui


INCLUDEPATH += ../../headers

LIBS += -L../../lib/win64 -lopenvr_api

DESTDIR = ../bin/win64
