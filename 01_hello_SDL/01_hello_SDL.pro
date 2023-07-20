QT -= core gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ..\SDL2\x86_64-w64-mingw32\include

LIBS += -L..\SDL2\x86_64-w64-mingw32\lib

LIBS += -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2

SOURCES += \
        01_hello_SDL.c
