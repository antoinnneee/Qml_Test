#-------------------------------------------------
#
# Project created by QtCreator 2017-04-06T17:06:23
#
#-------------------------------------------------
QT       += multimedia
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = audio_smart_guide
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        imap.cpp \
    clicklabel.cpp \
    pov.cpp

HEADERS  += imap.h \
    clicklabel.h \
    pov.h \
    define.h

FORMS    += imap.ui \
    pov.ui

CONFIG += mobility
CONFIG(P_DESKTOP):DEFINES += PLATFORM_DESK
CONFIG(P_ANDROID):DEFINES += PLATFORM_AND
MOBILITY = 

RESOURCES += \
    pic.qrc

