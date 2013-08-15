#-------------------------------------------------
#
# Project created by QtCreator 2013-06-28T23:03:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CurseurMidi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cmidiinput.cpp \
    cmidiinputthread.cpp \
    cmidi.cpp \
    cmidioutput.cpp \
    cmidioutputevent.cpp \
    cmidievent.cpp

HEADERS  += mainwindow.h \
    cmidiinput.h \
    cmidiinputthread.hpp \
    cmidi.hpp \
    cmidioutput.hpp \
    cmidioutputevent.hpp \
    cmidievent.hpp

FORMS    += mainwindow.ui

LIBS += -lasound

OTHER_FILES += \
    PoubelleACode.txt
