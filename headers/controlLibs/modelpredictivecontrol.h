#ifndef PREDITIVO_H
#define PREDITIVO_H

#include "SistemasdeControle/headers/modelLibs/model.h"
#include "SistemasdeControle/headers/modelLibs/statespace.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/modelLibs/integrativemodel.h"
#include "SistemasdeControle/headers/modelLibs/predictionmodel.h"

namespace ControlHandler{
    template <class Type>
    class ModelPredictiveControl
    {
        ModelHandler::StateSpace<Type> SSd;
        ModelHandler::PredictionModel<Type> SSP;
        ModelHandler::IntegrativeModel<Type> SSI;
        LinAlg::Matrix<Type> K, W, Q, R, U;

    public:
        ModelPredictiveControl(){}
        ModelPredictiveControl(const ModelHandler::StateSpace<Type>       &SS,
                               const ModelHandler::IntegrativeModel<Type> &SSI,
                               const ModelHandler::PredictionModel <Type> &SSP,
                               const LinAlg::Matrix<Type> &Q, const LinAlg::Matrix<Type> &R,
                               const LinAlg::Matrix<Type> &W);

        void setReference(LinAlg::Matrix<Type> W);
        void setErrorWeight(LinAlg::Matrix<Type> Q);
        void setInitialState(LinAlg::Matrix<Type> X0);
        void setControlWeight(LinAlg::Matrix<Type> R);
        void setNewModel(ModelHandler::StateSpace<Type>       SS,
                         ModelHandler::IntegrativeModel<Type> SSI,
                         ModelHandler::PredictionModel <Type> SSP,
                         LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R,
                         LinAlg::Matrix<Type> W);

        LinAlg::Matrix<Type> getReference() const;
        LinAlg::Matrix<Type> getErrorWeight() const;
        LinAlg::Matrix<Type> getInitialState() const;
        LinAlg::Matrix<Type> getControlWeight() const;

        LinAlg::Matrix<Type> OutputControlCalc(LinAlg::Matrix<Type> X_input);
        LinAlg::Matrix<Type> OutputControlCalc(LinAlg::Matrix<Type> X_input, LinAlg::Matrix<Type> W);
        LinAlg::Matrix<Type> OutputControlCalc(LinAlg::Matrix<Type> X_input, LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R, LinAlg::Matrix<Type> W);

    };
}

#include "SistemasdeControle/src/controlLibs/modelpredictivecontrol.hpp"
#endif // PREDITIVO_H
