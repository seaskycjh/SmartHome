#-------------------------------------------------
#
# Project created by QtCreator 2020-01-10T15:58:40
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartHome
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
        menu.cpp \
    app.cpp \
    xml.cpp \
    voice.cpp

HEADERS  += menu.h \
    app.h \
    xml.h \
    voice.h

FORMS    += menu.ui \
    app.ui

RESOURCES += \
    images.qrc

INCLUDEPATH += /usr/local/libxml2/include/libxml2
LIBS += -L /usr/local/libxml2/lib -lxml2
