#-------------------------------------------------
#
# Project created by QtCreator 2017-04-06T17:06:23
#
#-------------------------------------------------

QT       += core gui
QT       += quick
QT += quickwidgets
QT       += multimedia

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
    pov.cpp \
    android_textarea.cpp \
    pov_container.cpp \
    pov_swipe.cpp \
    pov_init.cpp

HEADERS  += imap.h \
    clicklabel.h \
    pov.h \
    define.h \
    android_textarea.h \
    pov_container.h \
    anchor.h

FORMS    += imap.ui \
    pov.ui \
    pov_container.ui

CONFIG += mobility
CONFIG(P_DESKTOP):DEFINES += PLATFORM_DESK
CONFIG(P_ANDROID):DEFINES += PLATFORM_AND
MOBILITY = 

RESOURCES += \
    audio0.qrc \
    audio1.qrc \
    audio2.qrc \
    audio3.qrc \
    background.qrc \
    icone.qrc \
    qmlfiles.qrc \
    text.qrc

DISTFILES += \
    PovQuickForm.ui.qml \
    PovQuick.qml \
    QuickchooseForm.ui.qml \
    Quickchoose.qml \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    DesignForm.ui.qml \
    Design.qml \
    flickcore.qml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

