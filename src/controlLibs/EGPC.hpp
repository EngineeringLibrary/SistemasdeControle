#ifdef testControl
    #include "../../../headers/controlLibs/EGPC.h"
#else
    #include "SistemasdeControle/headers/controlLibs/EGPC.h"
#endif

template<typename Type>
ControlHandler::EGPC<Type>::EGPC(const uint8_t &nInputDelay, const uint8_t &nOutputDelay,
                                 const uint8_t &nInput,      const uint8_t &nOutput)
{
    this->inputSize = nInput;
    this->freeY  = LinAlg::Zeros<Type>(nOutput, nOutputDelay+1);
    this->freeDU = LinAlg::Zeros<Type>(nInput , nInputDelay);
    this->pastInputs = LinAlg::Zeros<Type>(nInput, 1);
}

template <typename Type>
void ControlHandler::EGPC<Type>::setStates(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{
    this->freeDU =  Input |this->freeDU;
    this->freeY  =  Output|this->freeY;
    this->freeDU.removeColumn(this->freeDU.getNumberOfColumns()-1);
    this->freeY.removeColumn(this->freeY.getNumberOfColumns()-1);
    LinAlg::Matrix<Type> temporaryStates = ~this->pastInputs;

    for(unsigned i = 0; i < this->freeDU.getNumberOfRows(); ++i)
        temporaryStates = temporaryStates | this->freeDU.getRow(i);

    for(unsigned i = 0; i < this->freeY.getNumberOfColumns(); ++i)
        temporaryStates = temporaryStates | ~this->freeY.getColumn(i);

    temporaryStates = temporaryStates | this->Reference;

    this->states = ~temporaryStates;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::EGPC<Type>::outputControlActionsCalc(LinAlg::Matrix<Type> Reference, LinAlg::Matrix<Type> SignalInput)
{
    this->Reference  = Reference;
    this->pastInputs = Input;
    this->setStates(Input, SignalInput);
    if(this->isInside(this->states)) // Verifica em qual poliedro os estados estão (inWhitchRegion).
        this->Input = this->controllerParameters[this->inWitchRegion](from(0)-->this->inputSize-1,from(0)-->this->states.getNumberOfRows()-1)*this->states;
    else //Esse caso não deve acontecer exceto que o sistema seja iniciado de maneira errada.
    	std::cout << "Valor enviado nao pertence ao conjunto de restricoes!" << std::endl;

    return this->Input;
}

