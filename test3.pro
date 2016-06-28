#-------------------------------------------------
#
# Project created by QtCreator 2016-06-26T12:54:04
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myplot.cpp

HEADERS  += mainwindow.h \
    myplot.h

FORMS    += mainwindow.ui

LIBS += -lqwt
INCLUDEPATH += /usr/local/qwt-5.2.4-svn/lib

LIBS += -L/usr/local/lib -lQtSvg

unix|win32: LIBS += -lqwt

DISTFILES += \
    montreal.json \
    result.txt
