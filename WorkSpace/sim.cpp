#include "sim.h"

template <class UsedType>
Sim<UsedType>::Sim(Matrix<UsedType> InPut, Matrix<UsedType> OutPut, string Model, int var1, int var2, int var3, int var4, int var5)
{
    if(Model == "POLINOMIAL")
    {
        this->TypeModel = Model;
        this->Degree    = var1;
        this->nSample   = var2;
    }
    else if(Model == "MA")
    {
        this->TypeModel = Model;
        this->nOutPut   = var1;
        this->nSample   = var2;
    }
    else if(Model == "FIR")
    {
        this->TypeModel = Model;
        this->nInput    = var1;
        this->nSample   = var2;
    }
    else if(Model == "ARX")
    {
        this->TypeModel = Model;
        this->nInput    = var1;
        this->nOutPut   = var2;
        this->nSample   = var3;
    }
    else if(Model == "ARMAX")
    {
        this->TypeModel = Model;
        this->nInput    = var1;
        this->OutPut    = var2;
        this->nError    = var3;
        this->nSample   = var4;
    }
//    else if(Model == "NARX")
//    {
//        this->TypeModel = Model;
//        this->nInput    = var1;
//        this->nSample   = var2;
//    }
//    else if(Model == "NARMAX")
//    {
//        this->TypeModel = Model;
//        this->nInput    = var1;
//        this->nSample   = var2;
//    }
}

//------------------------------------------------------------------------------------------------------//
//----------------------------------One Step Model Construction-----------------------------------------//
//------------------------------------------------------------------------------------------------------//

template <class UsedType>
void Sim<UsedType>::SetPolyOneStep()
{
    this->LinSysOneStep.ones(1, this->Degree+1);
    for(int i = 2; i <= this->Degree+1; i++)
        this->LinSysOneStep.add(1, i, pow((double) this->InPut(this->nSample, 1), i-1));
}

template <class UsedType>
void Sim<UsedType>::SetMaOneStep()
{
    this->LinSysOneStep.zeros(1, this->nOutPut);
    for(int i = 1; i <= this->nOutPut; i++)
        this->LinSysOneStep.add(1, i, -this->EstOutPut(this->nSample - i, 1));
}

template <class UsedType>
void Sim<UsedType>::SetFirOneStep()
{
    this->LinSysOneStep.zeros(1, this->nInPut);
    for(int i = 1; i <= this->nInPut; i++)
        this->LinSysOneStep.add(1, i, this->InPut(this->nSample - i, 1));
}

template <class UsedType>
void Sim<UsedType>::SetArxOneStep()
{
    this->LinSysOneStep.zeros(1, this->nInPut + this->OutPut);
    for(int i = 1; i <= this->nInPut; i++)
    {
        if(i <= this->OutPut)
            this->LinSysOneStep.add(1, i, -this->EstOutPut(this->nSample - i, 1));

        else
            this->LinSysOneStep.add(1, i, this->InPut(this->nSample - i + this->OutPut, 1));
    }
}

template <class UsedType>
void Sim<UsedType>::SetArmaxOneStep()
{
    this->LinSysOneStep.zeros(1, this->nInPut + this->OutPut + this->nError);
    for(int i = 1; i <= this->nInPut; i++)
    {
        if(i <= this->OutPut)
            this->LinSysOneStep.add(1, i, -this->EstOutPut(this->nSample - i, 1));

        else if(i <= this->nInPut + this->OutPut)
            this->LinSysOneStep.add(1, i, this->InPut(this->nSample - i + this->OutPut, 1));

        else
            this->LinSysOneStep.add(1, i, this->Error(this->nSample - i + this->OutPut + this->nError, 1));
    }
}


//------------------------------------------------------------------------------------------------------//
//------------------------------------One Step Model Simulation-----------------------------------------//
//------------------------------------------------------------------------------------------------------//

template <class UsedType>
UsedType Sim<UsedType>::SimOneStep(Matrix<UsedType> LinSysParameters)
{
    this->LinSysParameters = LinSysParameters;
    if(Model == "POLINOMIAL")
        this->SetPolyOneStep();

    else if(Model == "MA")
        this->SetMaOneStep();

    else if(Model == "FIR")
        this->SetFirOneStep();

    else if(Model == "ARX")
        this->SetArxOneStep();

    else if(Model == "ARMAX")
        this->SetArmaxOneStep();

    return ((this->LinSysOneStep*this->LinSysParameters)(1,1));
}

//------------------------------------------------------------------------------------------------------//
//------------------------------Gathering all the Simulation--------------------------------------------//
//------------------------------------------------------------------------------------------------------//
template <class UsedType>
Matrix<UsedType> Sim<UsedType>::RunSimulation(Matrix<UsedType> LinSysParameters, int nSteps)
{
    this->LinSysParameters = LinSysParameters;
    this->EstOutPut.zeros(nSteps, 1);
}

//------------------------------------------------------------------------------------------------------//
//--------------------------------------Getting OutPut Data---------------------------------------------//
//------------------------------------------------------------------------------------------------------//

template  <class UsedType>
Matrix<UsedType> Sim<UsedType>::getInput()
{
    return this->InPut;
}

template  <class UsedType>
Matrix<UsedType> Sim<UsedType>::GetRealOutPut()
{
    return this->OutPut;
}

template  <class UsedType>
Matrix<UsedType> Sim<UsedType>::GetEstimatedOutPut()
{
    return this->EstOutPut;
}

template  <class UsedType>
Matrix<UsedType> Sim<UsedType>::GetError()
{
    return this->Error;
}

template class Sim<float>;
template class Sim<double>;
