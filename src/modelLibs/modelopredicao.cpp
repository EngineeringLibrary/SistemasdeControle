#include "SistemasdeControle/headers/modelLibs/modelopredicao.h"

template <class Type>
ModeloPredicao<Type>::ModeloPredicao( ModeloIntegrativo<Type> MI,
                                     unsigned HorizontePredicaoMin, unsigned HorizontePredicaoMax, unsigned HorizonteControle)
{
    this->HorizonteControle = HorizonteControle;
    this->HorizontePredicaoMax = HorizontePredicaoMax;
    this->HorizontePredicaoMin = HorizontePredicaoMin;
    this->Continuous = MI.isContinuous();

    if(Continuous)
    {

    }else{

        for(unsigned i = this->HorizontePredicaoMin; i <= this->HorizontePredicaoMax; ++i)
            this->Ad = (this->Ad || MI.getA()^i);

        for(unsigned j = 0; j <= this->HorizontePredicaoMin - 1; ++j)
        {
            LinAlg::Matrix<Type> Btemp = LinAlg::Zeros(j*MI.getB().getNumberOfRows(),
                                                       LinAlg::Zeros<Type>(j*MI.getB().getNumberOfColumns()));

            for(unsigned i = this->HorizontePredicaoMin - 1 + j;  i <= this->HorizontePredicaoMax - 1; ++i)
            {
                Btemp = (Btemp || (MI.getA()^i)*MI.getB());
            }
            this->B = (this->B | Btemp);
        }

        LinAlg::Matrix<Type> zerosC = LinAlg::Zeros(MI.getC().getNumberOfRows(), MI.getC().getNumberOfColumns());

        for(unsigned i = this->HorizontePredicaoMin; i <= this->HorizontePredicaoMax; ++i)
        {
            LinAlg::Matrix<Type> Ctemp;
            for(unsigned j = this->HorizontePredicaoMin; j <= this->HorizontePredicaoMax; ++j)
            {
                if(i == j)
                {
                    Ctemp = (Ctemp || MI.getC());
                }else
                {
                    Ctemp = (Ctemp || LinAlg::Zeros(zerosC));
                }
            }
            this->C = (this->C | Ctemp);
        }
    }

    this->D = MI.getD();
}
