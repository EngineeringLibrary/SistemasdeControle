#include "sim.h"

template <class UsedType>
Sim<UsedType>::Sim(Matrix<UsedType> InPut, Matrix<UsedType> OutPut, string Model, int var1, int var2, int var3, int var4, int var5)
{
    this->InPut = InPut;
    this->OutPut = OutPut;
    DataChange = 1;

    if(Model == "POLINOMIAL")
    {
        this->TypeModel = Model;
        this->Degree    = var1;
        this->nSample   = var2;

        this->nError = 0;
        this->nInPut = 0;
        this->NonLinDegree = 0;
        this->nOutPut = 0;
    }
    else if(Model == "MA")
    {
        this->TypeModel = Model;
        this->nOutPut   = var1;
        this->nSample   = var2;

        this->nError = 0;
        this->nInPut = 0;
        this->NonLinDegree = 0;
        this->Degree = 0;
    }
    else if(Model == "FIR")
    {
        this->TypeModel = Model;
        this->nInPut    = var1;
        this->nSample   = var2;

        this->nError = 0;
        this->nOutPut = 0;
        this->NonLinDegree = 0;
        this->Degree = 0;
    }
    else if(Model == "ARX")
    {
        this->TypeModel = Model;
        this->nInPut    = var1;
        this->nOutPut   = var2;
        this->nSample   = var3;

        this->nError = 0;
        this->NonLinDegree = 0;
        this->Degree = 0;
    }
    else if(Model == "ARMAX")
    {
        this->TypeModel = Model;
        this->nInPut    = var1;
        this->nOutPut   = var2;
        this->nError    = var3;
        this->nSample   = var4;

        this->NonLinDegree = 0;
        this->Degree = 0;
    }
//    else if(Model == "NARX")
//    {
//        this->TypeModel = Model;
//        this->nInPut    = var1;
//        this->nSample   = var2;
        this->NonLinDegree = var5;
//    }
//    else if(Model == "NARMAX")
//    {
//        this->TypeModel = Model;
//        this->nInPut    = var1;
//        this->nSample   = var2;
//    }
}

//-----------------------------------------------------------------------//
//--------------------One Step Model Construction------------------------//
//-----------------------------------------------------------------------//

template <class UsedType>
void Sim<UsedType>::SetPolyOneStep()
{
    this->LinSysOneStep.ones(1, (this->Degree + 1)*this->InPut.getCols());

    for(int i = 0; i < this->InPut.getCols(); i++)
        for(int j = 2; j <= this->Degree + 1; j++)
            this->LinSysOneStep.add(1, j + ((this->Degree + 1)*i), pow((double) this->InPut(this->nSample, i + 1), j - 1));
}

template <class UsedType>
void Sim<UsedType>::SetArmaxOneStep()
{
    this->LinSysOneStep.zeros(1, this->nInPut*this->InPut.getCols() + this->nOutPut*this->OutPut.getCols() + this->nError);

    int cont = 1;
    for(int i = 1; i <= this->OutPut.getCols(); i++)
    {
        for(int j = 1; j <= this->nOutPut; j++)
        {
            this->LinSysOneStep.add(1, cont, -this->EstOutPut(this->nSample - j, i));
            cont++;
        }
    }
    for(int i = 1; i <= this->InPut.getCols(); i++)
    {
        for(int j = 1; j <= this->nInPut; j++)
        {
            this->LinSysOneStep.add(1, cont, this->InPut(this->nSample - j, i));
            cont++;
        }
    }

    for(int j = 1; j <= this->nError; j++)
    {
        this->LinSysOneStep.add(1, cont, this->Error(this->nSample - j, 1));
        cont++;
    }
}

//-----------------------------------------------------------------------//
//---------------------Mult Step Model Construction----------------------//
//-----------------------------------------------------------------------//

template <class UsedType>
void Sim<UsedType>::SetPolyMultStep()
{
    this->LinSysOutPut = this->OutPut;
    this->LinSysMultStep.ones(this->LinSysOutPut.getRows(), (this->Degree + 1)*this->InPut.getCols());

    for(int k = 1; k <= this->LinSysOutPut.getRows(); k++)
        for(int i = 0; i < this->InPut.getCols(); i++)
            for(int j = 2; j <= this->Degree + 1; j++)
                this->LinSysOneStep.add(k, j + ((this->Degree + 1)*i), pow((double) this->InPut(this->nSample, i + 1), j - 1));
}

template  <class UsedType>
void Sim<UsedType>::SetArmaxOMultStep()
{
    int maxNuNy,minRowInOut;

    if(this->nOutPut > this->nInPut)
        maxNuNy = this->nOutPut;
    else
        maxNuNy = this->nInPut;

    if(this->OutPut.getRows() > this->InPut.getRows())
        minRowInOut = this->InPut.getRows();
    else
        minRowInOut = this->OutPut.getRows();

    this->LinSysMultStep.zeros(minRowInOut - maxNuNy, this->nInPut*this->InPut.getCols() + this->nOutPut*this->OutPut.getCols() + this->nError);

    for(int k = maxNuNy + 1; k <= minRowInOut; k++)
    {
        int cont = 1;
        for(int i = 1; i <= this->OutPut.getCols(); i++)
        {
            for(int j = 1; j <= this->nOutPut; j++)
            {
                this->LinSysMultStep.add(k - maxNuNy , cont, -this->OutPut(k - j, i));
                cont++;
            }
            this->LinSysOutPut.add(k - maxNuNy, i, this->OutPut(k,i));
        }

        for(int i = 1; i <= this->InPut.getCols(); i++)
        {
            for(int j = 1; j <= this->nInPut; j++)
            {
                this->LinSysMultStep.add(k - maxNuNy, cont, this->InPut(k - j, i));
                cont++;
            }
        }

        for(int j = 1; j <= this->nError; j++)
        {
            this->LinSysMultStep.add(k - maxNuNy, cont, this->Error(k - j, 1));
            cont++;
        }

    }

}



//-----------------------------------------------------------------------//
//------------------------One Step Model Simulation----------------------//
//-----------------------------------------------------------------------//

template <class UsedType>
UsedType Sim<UsedType>::SimOneStep()
{
    this->LinSysParameters = LinSysParameters;
    if(this->TypeModel == "POLINOMIAL")
    {
        if(this->DataChange == 1)
            this->SetPolyMultStep();
        if(nSample != 0)
            this->SetPolyOneStep();
    }

    else if(this->TypeModel == "MA" || this->TypeModel == "FIR" || this->TypeModel == "ARX" || this->TypeModel == "ARMAX")
    {
        if(this->DataChange == 1)
            this->SetArmaxOMultStep();
        if(nSample != 0)
            this->SetArmaxOneStep();
    }

    this->DataChange = 0;
    if(nSample != 0)
        return ((this->LinSysOneStep*this->LinSysParameters)(1,1));
    else
        return ((this->LinSysMultStep*this->LinSysParameters)(1,1));
}

//-----------------------------------------------------------------------//
//---------------------Gathering all the Simulation----------------------//
//-----------------------------------------------------------------------//
template <class UsedType>
Matrix<UsedType> Sim<UsedType>::RunSimulation(Matrix<UsedType> LinSysParameters, int nSteps)
{
    this->nSample = nSteps;
    this->LinSysParameters = LinSysParameters;
    this->EstOutPut.zeros(nSteps, 1);
    this->SimOneStep();
    return this->EstOutPut;
}

//-----------------------------------------------------------------------//
//------------------------Getting OutPut Data----------------------------//
//-----------------------------------------------------------------------//

template  <class UsedType>
Matrix<UsedType> Sim<UsedType>::GetInput()
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
Matrix<UsedType> Sim<UsedType>::GetLinSysOutPut()
{
    return this->LinSysOutPut;
}

template  <class UsedType>
Matrix<UsedType> Sim<UsedType>::GetLinMatrix()
{
    return this->LinSysMultStep;
}

template  <class UsedType>
Matrix<UsedType> Sim<UsedType>::GetError()
{
    return this->Error;
}

template class Sim<float>;
template class Sim<double>;
