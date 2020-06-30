QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_pca.cpp

HEADERS += \
    ../../../headers/advancedLinALg/PCA.h \
    ../../../headers/primitiveLibs/LinAlg/linalg.h \
    ../../../headers/primitiveLibs/LinAlg/matrix.h \
    ../../../headers/primitiveLibs/polynom.h \
    ../../../src/advancedLinALg/PCA.hpp \
    ../../../src/primitiveLibs/LinAlg/linalg.hpp \
    ../../../src/primitiveLibs/LinAlg/matrix.hpp \
    ../../../src/primitiveLibs/polynom.hpp

INCLUDEPATH += C:/gurobi901/win64/include
LIBS += -L C:/gurobi901/win64/lib -lgurobi_c++mdd2019 -lgurobi_c++mtd2019 -lgurobi90 -lpthread
