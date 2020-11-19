#-------------------------------------------------
#
# Project created by QtCreator 2020-09-24T02:15:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        ndn_app.cpp \
    chatbuf.pb.cc \
    test-chrono-chat.cpp \
    chatbuf.pb.cc \
    main.cpp \
    ndn_app.cpp \
    test-chrono-chat.cpp

HEADERS += \
    ndn_app.h \
    chatbuf.pb.h \
    chatbuf.pb.h \
    ndn_app.h \
    ui_dialog.h \
    ui_ndn_app.h

FORMS += \
        ndn_app.ui \
    ndn_app.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libndn-cpp


SUBDIRS += \
    app.pro \
    app_ndn-cpp.pro


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/local/lib/release/ -lndn-cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/local/lib/debug/ -lndn-cpp
else:unix: LIBS += -L$$PWD/../../../../usr/local/lib/ -lndn-cpp

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

unix|win32: LIBS += -lprotobuf

DISTFILES += \
    chat.o \
    chatbuf.pb.o \
    main.o \
    nfd_report.o \
    app.pro.user \
    app_ndn-cpp.pro.user \
    chatbuf.proto
