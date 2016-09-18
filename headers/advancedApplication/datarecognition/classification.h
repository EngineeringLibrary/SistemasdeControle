#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H
#include "SistemasdeControle/headers/modelLibs/arx.h"
#include "SistemasdeControle/headers/modelLibs/fir.h"
#include "SistemasdeControle/headers/modelLibs/nfir.h"
#include "SistemasdeControle/headers/optimizationLibs/leastsquare.h"
#include "SistemasdeControle/headers/optimizationLibs/recursiveleastsquare.h"

namespace AdvancedApplication {
    template <class Type>
    class Classification
    {
    public:
        Classification(ModelHandler::Model<Type> *model = 0, Type tolerance = 0.001);
        void dataRegistration(const LinAlg::Matrix<Type> &data2Register);
        bool dataRecognition(const LinAlg::Matrix<Type> &data2beRecognized);
        LinAlg::Matrix<Type> getError(){return error;}

    private:
        ModelHandler::Model<Type> *model;
        OptimizationHandler::Optimization<Type> *RLS;
        LinAlg::Matrix<Type> error, Output, data2Register;
        Type tolerance;
    };
}

#endif // CLASSIFICATION_H
