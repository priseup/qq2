#-------------------------------------------------
#
# Project created by QtCreator 2020-07-22T10:51:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qq2
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += \
    /home/uisee/github/sqlite3

LIBS += /home/uisee/github/sqlite3/libsqlite3.a
LIBS += -lpthread   \
        -ldl

SOURCES += main.cpp\
    sign_login.cpp \
    tips_dialog.cpp \
    sign_dialog.cpp \
    qq_window.cpp

HEADERS += sign_login.h \
    tips_dialog.h \
    sign_dialog.h   \
    /home/uisee/git/lslam/3rdparty/database/sqlite3/sqlite3.h \
    qq_window.h

FORMS += sign_login.ui \
    tips_dialog.ui \
    sign_dialog.ui \
    qq_window.ui
