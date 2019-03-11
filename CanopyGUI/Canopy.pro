#-------------------------------------------------
#
# Project created by QtCreator 2019-02-28T19:20:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Canopy
TEMPLATE = app


SOURCES += main.cpp\
    WelcomeWindow.cpp \
    SearchWindow.cpp \
    ../CanopyParser/EmailData.cpp \
    ../CanopyParser/EmailParser.cpp \
    FrameButton.cpp \
    EmailWindow.cpp

HEADERS  += SearchWindow.h \
    WelcomeWindow.h \
    ../CanopyParser/EmailData.h \
    ../CanopyParser/EmailParser.h \
    FrameButton.h \
    EmailWindow.h

FORMS    += SearchWindow.ui \
    WelcomeWindow.ui \
    EmailWindow.ui

DISTFILES += \
    ../images/CanopyLogo-04.png
