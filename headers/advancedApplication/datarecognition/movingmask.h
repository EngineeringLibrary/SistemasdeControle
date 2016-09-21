#ifndef MOVINGMASK_H
#define MOVINGMASK_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"

namespace AdvancedApplication {
    template <class Type>
    class movingMask
    {

    public:

        movingMask(){}
        movingMask(const unsigned &quantidadeVariaveis , const unsigned &tamanho);

        void dataRecognitionStart(const unsigned &quantidadeVariaveis, const unsigned &tamanho);
        void operator << (const LinAlg::Matrix<Type> &inputData);
        Type dataRecognition(const LinAlg::Matrix<Type> &defaultData, Type tolerance = 1000);

    private:

        LinAlg::Matrix<Type> data2Register;
        Type quantidadeVariaveis, tamanho;
        unsigned counter;
    };
}


#include "SistemasdeControle/src/advancedApplication/datarecognition/movingmask.hpp"
#endif // MOVINGMASK_H
