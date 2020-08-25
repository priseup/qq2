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
    3rdparty/sqlite3/include    \
    include

LIBS += /home/neolix/github/qq2/3rdparty/sqlite3/lib/libsqlite3.a
LIBS += -lpthread   \
        -ldl

SOURCES += main.cpp\
    src/sign_login.cpp \
    src/tips_dialog.cpp \
    src/sign_dialog.cpp \
    src/qq_window.cpp

HEADERS += include/sign_login.h \
    include/tips_dialog.h \
    include/sign_dialog.h   \
    include/qq_window.h     \
    3rdparty/sqlite3/include/sqlite3.h

FORMS += ui/sign_login.ui \
    ui/tips_dialog.ui \
    ui/sign_dialog.ui \
    ui/qq_window.ui
