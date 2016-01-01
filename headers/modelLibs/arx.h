#ifndef ARX_H
#define ARX_H
#include "SistemasdeControle/headers/modelLibs/model.h"

namespace ModelHandler {
    template <class Type>
    class ARX : public Model<Type>
    {
    public:
        ARX(unsigned nInputpar , unsigned nOutputpar,
            unsigned delay = 0,
            unsigned qdtInputVar = 1, unsigned qdtOutputVar = 1,
            double sampleTime = 0.1);
        ARX(const ARX<Type>& OtherArxModel);

        unsigned getNumberOfInputs() const;
        unsigned getNumberOfOutputs() const;
        unsigned getNumberOfInputDelays() const;
        unsigned getNumberOfOutputDelays() const;

        double getSampleTime() const;
        unsigned getNumberOfVariables();

        void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> PastOutput);
        void setLinearModel (LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);


        std::string print();
        Type sim(Type input);
        Type sim(Type input, Type output);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> Input);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);
        LinAlg::Matrix<Type> sim(Type lsim, Type lmax, Type step);

    private:
        unsigned nInputpar  , nOutputpar  , delay,
                 qdtInputVar, qdtOutputVar, nSample,
                 maxnInOut,sampleTime;
    };
}

#include "SistemasdeControle/src/modelLibs/arx.hpp"
#endif // ARX_H
