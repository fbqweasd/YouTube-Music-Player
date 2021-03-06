QT       += core gui network xml multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    music_add.cpp \
    playlist.cpp \
    playlist_add_form.cpp \
    qdynamicbutton.cpp \
    widget.cpp \
    youtube.cpp

HEADERS += \
    music_add.h \
    path.h \
    playlist.h \
    playlist_add_form.h \
    qdynamicbutton.h \
    widget.h \
    youtube.h

FORMS += \
    music_add.ui \
    playlist.ui \
    playlist_add_form.ui \
    widget.ui

TRANSLATIONS += \
    YouTube_Player_ko_KR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin

DISTFILES += \
    Img/default_img.png
