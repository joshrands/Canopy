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
    ../CanopyParser/EmailParser.cpp \
    FrameButton.cpp \
    EmailWindow.cpp \
    ../CanopyData/TextAnalysis.cpp \
    StartWindow.cpp \
    AddDataWindow.cpp \
    SessionWindow.cpp \
    Data.cpp \
    ContentWindow.cpp \
    ../CanopyParser/LocalEmailData.cpp \
    ../CanopyParser/ParseEmail.cpp

HEADERS  += SearchWindow.h \
    WelcomeWindow.h \
    ../CanopyParser/EmailParser.h \
    FrameButton.h \
    EmailWindow.h \
    ../CanopyData/TextAnalysis.h \
    StartWindow.h \
    AddDataWindow.h \
    SessionWindow.h \
    Data.h \
    ContentWindow.h \
    ../CanopyParser/LocalEmailData.h \
    ../CanopyParser/ParseEmail.h

FORMS    += SearchWindow.ui \
    WelcomeWindow.ui \
    EmailWindow.ui \
    StartWindow.ui \
    AddDataWindow.ui \
    SessionWindow.ui \
    ContentWindow.ui

DISTFILES += \
    ../images/CanopyLogo-04.png
