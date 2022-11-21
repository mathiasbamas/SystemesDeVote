TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    MethodeBorda.h \
    ScrutinUninominal.h \
    SystemeFrancais.h \
    VoteParValeur.h

DISTFILES += \
    votants.txt
