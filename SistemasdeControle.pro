#-------------------------------------------------
#
# Project created by QtCreator 2014-12-20T19:15:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += opengl widgets

LIBS += -lfreeglut \

INCLUDEPATH += -L/usr/lib/

TARGET = untitled2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    src/communicationLibs/serial/comunicacao.cpp \
    src/externalLibs/externalfunctions.cpp \
    src/optimizationLibs/optimization.cpp \
    src/optimizationLibs/pid.cpp \
    src/optimizationLibs/pso.cpp \
    src/optimizationLibs/relay.cpp \
    src/primitiveLibs/matrix.cpp \
    src/primitiveLibs/polynom.cpp \
    src/simulationLibs/bisseccao.cpp \
    src/simulationLibs/eqdifsim.cpp \
    src/simulationLibs/fzero.cpp \
    src/simulationLibs/lsim.cpp \
    src/simulationLibs/model.cpp \
    src/simulationLibs/sim.cpp \
    src/simulationLibs/simfunction.cpp \
    src/simulationLibs/transferfunction.cpp \
    src/simulationLibs/statespace.cpp \
    src/simulationLibs/armax.cpp \
    src/simulationLibs/arx.cpp \
    src/simulationLibs/fir.cpp \
    src/simulationLibs/ma.cpp \
    src/optimizationLibs/leastsquare.cpp \
    src/optimizationLibs/recursiveleastsquare.cpp

HEADERS += src/communicationLibs/serial/comunicacao.h \
    src/externalLibs/externalfunctions.h \
    src/optimizationLibs/optimization.h \
    src/optimizationLibs/pid.h \
    src/optimizationLibs/pso.h \
    src/optimizationLibs/relay.h \
    src/primitiveLibs/matrix.h \
    src/primitiveLibs/polynom.h \
    src/simulationLibs/bisseccao.h \
    src/simulationLibs/eqdifsim.h \
    src/simulationLibs/fzero.h \
    src/simulationLibs/lsim.h \
    src/simulationLibs/model.h \
    src/simulationLibs/sim.h \
    src/simulationLibs/simfunction.h \
    src/simulationLibs/transferfunction.h \
    src/simulationLibs/statespace.h \
    src/simulationLibs/conversions.h \
    src/simulationLibs/armax.h \
    src/simulationLibs/arx.h \
    src/simulationLibs/fir.h \
    src/simulationLibs/ma.h \
    src/optimizationLibs/leastsquare.h \
    src/optimizationLibs/recursiveleastsquare.h
