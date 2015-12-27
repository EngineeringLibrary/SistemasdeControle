#ifndef ARX_H
#define ARX_H
#include "SistemasdeControle/headers/modelLibs/model.h"

namespace ModelHandler {
    template <class Type>
    class ARX : public Model<Type>
    {
    private:
        unsigned nInputpar  , nOutputpar  , delay,
                 qdtInputVar, qdtOutputVar, nSample,
                 maxnInOut,sampleTime;
    public:
        ARX(unsigned nInputpar , unsigned nOutputpar,
            unsigned delay = 0,
            unsigned qdtInputVar = 1, unsigned qdtOutputVar = 1, float sampleTime = 0.1);
        ARX(const ARX<Type>& OtherArxModel);

        void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> PastOutput);
        void setLinearModel (LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);

        unsigned getNumberOfInputs();
        unsigned getNumberOfOutputs();
        unsigned getNumberOfInputDelays();
        unsigned getNumberOfOutputDelays();

        float getSampleTime();

        std::string print();
        Type sim(Type input);
        Type sim(Type input, Type output);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> Input);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);
        LinAlg::Matrix<Type> sim(Type lsim, Type lmax, Type step);
    };
}

#endif // ARX_H
