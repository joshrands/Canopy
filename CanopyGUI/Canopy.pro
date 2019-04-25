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
    ./Alpha1.0/WelcomeWindow.cpp \
    ./Alpha1.0/SearchWindow.cpp \
    ../CanopyParser/EmailParser.cpp \
    ./CustomWidgets/FrameButton.cpp \
    ./Alpha1.0/EmailWindow.cpp \
    ../CanopyData/TextAnalysis.cpp \
    StartWindow.cpp \
    AddDataWindow.cpp \
    SessionWindow.cpp \
    Data.cpp \
    ./ContentWindows/ContentWindow.cpp \
    ../CanopyParser/LocalEmailData.cpp \
    ../CanopyParser/ParseEmail.cpp

HEADERS  += ./Alpha1.0/SearchWindow.h \
    ./Alpha1.0/WelcomeWindow.h \
    ../CanopyParser/EmailParser.h \
    ./CustomWidgets/FrameButton.h \
    ./Alpha1.0/EmailWindow.h \
    ../CanopyData/TextAnalysis.h \
    StartWindow.h \
    AddDataWindow.h \
    SessionWindow.h \
    Data.h \
    ./ContentWindows/ContentWindow.h \
    ../CanopyParser/LocalEmailData.h \
    ../CanopyParser/ParseEmail.h \
    ContentWindows/EmailContentWindow.h

FORMS    += ./Alpha1.0/SearchWindow.ui \
    ./Alpha1.0/WelcomeWindow.ui \
    ./Alpha1.0/EmailWindow.ui \
    StartWindow.ui \
    AddDataWindow.ui \
    SessionWindow.ui \
    ./ContentWindows/ContentWindow.ui

DISTFILES += \
    ../images/CanopyLogo-04.png
