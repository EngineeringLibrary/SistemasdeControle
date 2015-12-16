QT += core
QT -= gui

TARGET = ConstrutorCopiaDaClasse
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.cpp

HEADERS += \
    SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp

