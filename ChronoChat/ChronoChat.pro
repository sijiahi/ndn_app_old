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
    add-contact-panel.cpp \
    browse-contact-dialog.cpp \
    chat-dialog-backend.cpp \
    chat-dialog.cpp \
    chat-message.cpp \
    chatroom-discovery-backend.cpp \
    chatroom-info.cpp \
    conf.cpp \
    contact-manager.cpp \
    contact-panel.cpp \
    contact-storage.cpp \
    controller-backend.cpp \
    controller.cpp \
    digest-tree-scene.cpp \
    discovery-panel.cpp \
    endorse-certificate.cpp \
    endorse-collection.cpp \
    endorse-combobox-delegate.cpp \
    endorse-extension.cpp \
    endorse-info.cpp \
    invitation-dialog.cpp \
    invitation-request-dialog.cpp \
    invitation.cpp \
    invite-list-dialog.cpp \
    main.cpp \
    nfd-connection-checker.cpp \
    profile-editor.cpp \
    profile.cpp \
    set-alias-dialog.cpp \
    setting-dialog.cpp \
    start-chat-dialog.cpp \
    tree-layout.cpp \
    trust-tree-scene.cpp \
    validator-invitation.cpp \
    validator-panel.cpp

HEADERS += \
    add-contact-panel.hpp \
    browse-contact-dialog.hpp \
    chat-dialog-backend.hpp \
    chat-dialog.hpp \
    chat-message.hpp \
    chatroom-discovery-backend.hpp \
    chatroom-info.hpp \
    common.hpp \
    conf.hpp \
    contact-manager.hpp \
    contact-panel.hpp \
    contact-storage.hpp \
    contact.hpp \
    controller-backend.hpp \
    controller.hpp \
    cryptopp.hpp \
    digest-tree-scene.hpp \
    discovery-panel.hpp \
    endorse-certificate.hpp \
    endorse-collection.hpp \
    endorse-combobox-delegate.hpp \
    endorse-extension.hpp \
    endorse-info.hpp \
    invitation-dialog.hpp \
    invitation-request-dialog.hpp \
    invitation.hpp \
    invite-list-dialog.hpp \
    nfd-connection-checker.hpp \
    profile-editor.hpp \
    profile.hpp \
    set-alias-dialog.hpp \
    setting-dialog.hpp \
    start-chat-dialog.hpp \
    tlv.hpp \
    tree-layout.hpp \
    trust-tree-node.hpp \
    trust-tree-scene.hpp \
    validator-invitation.hpp \
    validator-panel.hpp

FORMS += \
    add-contact-panel.ui \
    browse-contact-dialog.ui \
    chat-dialog.ui \
    contact-panel.ui \
    discovery-panel.ui \
    invitation-dialog.ui \
    invitation-request-dialog.ui \
    invite-list-dialog.ui \
    profile-editor.ui \
    set-alias-dialog.ui \
    setting-dialog.ui \
    start-chat-dialog.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libndn-cxx



SUBDIRS += \
    app.pro \
    ChronoChat.pro


INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

unix|win32: LIBS += -lprotobuf
