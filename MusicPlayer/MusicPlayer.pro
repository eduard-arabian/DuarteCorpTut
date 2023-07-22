TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c

INCLUDEPATH += $$PWD/include \
               $$PWD/include/vlc

LIBS += -L$$PWD/lib

LIBS += -lvlc -lvlccore -lnpvlc -laxvlc
