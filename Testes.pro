#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T11:44:00
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_testestest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_testestest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    SistemasdeControle/headers/advancedApplication/datarecognition/classification.h \
    SistemasdeControle/headers/advancedApplication/datarecognition/movingmask.h \
    SistemasdeControle/headers/advancedControlLibs/droneControl/dronecontrol.h \
    SistemasdeControle/headers/advancedLinALg/PCA.h \
    SistemasdeControle/headers/advancedModelLibs/droneModel/dronemodel.h \
    SistemasdeControle/headers/controlLibs/modelpredictivecontrol.h \
    SistemasdeControle/headers/controlLibs/pid.h \
    SistemasdeControle/headers/graphicLibs/plot.h \
    SistemasdeControle/headers/modelLibs/activefunction.h \
    SistemasdeControle/headers/modelLibs/armax.h \
    SistemasdeControle/headers/modelLibs/arx.h \
    SistemasdeControle/headers/modelLibs/conversions.h \
    SistemasdeControle/headers/modelLibs/fir.h \
    SistemasdeControle/headers/modelLibs/integrativemodel.h \
    SistemasdeControle/headers/modelLibs/ma.h \
    SistemasdeControle/headers/modelLibs/model.h \
    SistemasdeControle/headers/modelLibs/neuron.h \
    SistemasdeControle/headers/modelLibs/neuron.hpp \
    SistemasdeControle/headers/modelLibs/nfir.h \
    SistemasdeControle/headers/modelLibs/predictionmodel.h \
    SistemasdeControle/headers/modelLibs/rna.h \
    SistemasdeControle/headers/modelLibs/rna.hpp \
    SistemasdeControle/headers/modelLibs/simfunction.h \
    SistemasdeControle/headers/modelLibs/statespace.h \
    SistemasdeControle/headers/modelLibs/transferfunction.h \
    SistemasdeControle/headers/optimizationLibs/leastsquare.h \
    SistemasdeControle/headers/optimizationLibs/optimization.h \
    SistemasdeControle/headers/optimizationLibs/pso.h \
    SistemasdeControle/headers/optimizationLibs/recursiveleastsquare.h \
    SistemasdeControle/headers/optimizationLibs/relay.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrixrestriction.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrixrestriction.hpp \
    SistemasdeControle/headers/primitiveLibs/polynom.h \
    SistemasdeControle/headers/restrictedOptimization/activeset.h \
    SistemasdeControle/headers/restrictedOptimization/activeset.hpp \
    SistemasdeControle/headers/restrictedOptimization/generalisedrestrictednewton.h \
    SistemasdeControle/headers/restrictedOptimization/linprog.h \
    SistemasdeControle/headers/restrictedOptimization/polyhedron.h \
    SistemasdeControle/headers/restrictedOptimization/polyhedron.hpp \
    SistemasdeControle/headers/restrictedOptimization/quadprog.h \
    SistemasdeControle/headers/restrictedOptimization/recursiveactiveset.h \
    SistemasdeControle/headers/restrictedOptimization/simplex.h \
    SistemasdeControle/headers/simulationLibs/sim.h \
    SistemasdeControle/headers/zeroFunctionLib/bisseccao.h \
    SistemasdeControle/headers/zeroFunctionLib/fzero.h \
    SistemasdeControle/headers/zeroFunctionLib/newton.h \
    SistemasdeControle/headers/zeroFunctionLib/secant.h \
    SistemasdeControle/headers/zeroFunctionLib/steffensen.h \
    SistemasdeControle/src/advancedApplication/datarecognition/classification.hpp \
    SistemasdeControle/src/advancedApplication/datarecognition/movingmask.hpp \
    SistemasdeControle/src/advancedControlLibs/droneControl/dronecontrol.hpp \
    SistemasdeControle/src/advancedLinALg/PCA.hpp \
    SistemasdeControle/src/advancedModelLibs/droneModel/dronemodel.hpp \
    SistemasdeControle/src/controlLibs/modelpredictivecontrol.hpp \
    SistemasdeControle/src/controlLibs/pid.hpp \
    SistemasdeControle/src/graphicLibs/plot.hpp \
    SistemasdeControle/src/modelLibs/armax.hpp \
    SistemasdeControle/src/modelLibs/arx.hpp \
    SistemasdeControle/src/modelLibs/conversions.hpp \
    SistemasdeControle/src/modelLibs/fir.hpp \
    SistemasdeControle/src/modelLibs/integrativemodel.hpp \
    SistemasdeControle/src/modelLibs/ma.hpp \
    SistemasdeControle/src/modelLibs/model.hpp \
    SistemasdeControle/src/modelLibs/nfir.hpp \
    SistemasdeControle/src/modelLibs/predictionmodel.hpp \
    SistemasdeControle/src/modelLibs/simfunction.hpp \
    SistemasdeControle/src/modelLibs/statespace.hpp \
    SistemasdeControle/src/modelLibs/transferfunction.hpp \
    SistemasdeControle/src/optimizationLibs/leastsquare.hpp \
    SistemasdeControle/src/optimizationLibs/optimization.hpp \
    SistemasdeControle/src/optimizationLibs/pso.hpp \
    SistemasdeControle/src/optimizationLibs/recursiveleastsquare.hpp \
    SistemasdeControle/src/optimizationLibs/relay.hpp \
    SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrixrestriction.hpp \
    SistemasdeControle/src/primitiveLibs/polynom.hpp \
    SistemasdeControle/src/restrictedOptimization/activeset.hpp \
    SistemasdeControle/src/restrictedOptimization/generalisedrestrictednewton.hpp \
    SistemasdeControle/src/restrictedOptimization/linprog.hpp \
    SistemasdeControle/src/restrictedOptimization/polyhedron.hpp \
    SistemasdeControle/src/restrictedOptimization/quadprog.hpp \
    SistemasdeControle/src/restrictedOptimization/recursiveactiveset.hpp \
    SistemasdeControle/src/restrictedOptimization/simplex.hpp \
    SistemasdeControle/src/simulationLibs/sim.hpp \
    SistemasdeControle/src/zeroFunctionLib/bisseccao.hpp \
    SistemasdeControle/src/zeroFunctionLib/fzero.hpp \
    SistemasdeControle/src/zeroFunctionLib/newton.hpp \
    SistemasdeControle/src/zeroFunctionLib/secant.hpp \
    SistemasdeControle/src/zeroFunctionLib/steffensen.hpp \
    Testes/SistemasdeControle/primitiveLibs/LinAlg/test_matrix.h

