#include "eqdifsim.h"

template <class UsedType>
EqdifSim<UsedType>::EqdifSim()
{

}

template <class UsedType>
EqdifSim<UsedType>::EqdifSim(Matrix<UsedType> AdIn, Matrix<UsedType> BdIn, Matrix<UsedType> CdIn, Matrix<UsedType> DdIn, float Time)
{
    this->Ad = AdIn;
    this->Bd = BdIn;
    this->Cd = CdIn;
    this->Dd = DdIn;
    ss2tfd();
    d2c();
    tf2ssc();
    this->SampleTime = Time;
    this->typeModel = "SSDiscrete";
}

template <class UsedType>
EqdifSim<UsedType>::EqdifSim(Matrix<UsedType> AIn, Matrix<UsedType> BIn, Matrix<UsedType> CIn, Matrix<UsedType> DIn)
{
    this->A = AIn;
    this->B = BIn;
    this->C = CIn;
    this->D = DIn;
//    this->SampleTime = 0.1;
    ss2tfc();
    c2d(0.1);
    ss2tfd();
    this->typeModel = "SSContinuous";
}

template <class UsedType>
EqdifSim<UsedType>::EqdifSim(Matrix<UsedType> NumIn, Matrix<UsedType> DenIn)
{
    this->TransferFunction = new Polynom<UsedType>*[1];
    for(int i = 0; i < 1; i++)
        this->TransferFunction[i] = new Polynom<UsedType>[1];
    this->TransferFunction[0][0] = Polynom<UsedType>(NumIn, DenIn);

    tf2ssc();
    c2d(0.1);
    ss2tfd();

    this->typeModel = "TFContinuous";
}

template <class UsedType>
EqdifSim<UsedType>::EqdifSim(Matrix<UsedType> NumdIn, Matrix<UsedType> DendIn, float Time)
{
    this->DiscreteTransferFunction = new Polynom<UsedType>*[1];
    for(int i = 0; i < 1; i++)
        this->DiscreteTransferFunction[i] = new Polynom<UsedType>[1];
    this->DiscreteTransferFunction[0][0] = Polynom<UsedType>(NumdIn, DendIn);
    this->SampleTime = Time;

    tf2ssd();
    d2c();
    ss2tfc();

    this->typeModel = "TFDiscrete";
}

template <class UsedType>
void EqdifSim<UsedType>::d2c()
{
    Matrix<UsedType> Mat, E, Temp, Root, I, ZeroVector, IAd;

    Mat = this->Ad.eigenvalues();
    IAd.eye(this->Ad.getRows());
    for(int j = 1; j < 4; j++)//deixar a ordem flexivel
        E.add( 1, j+1, pow(this->SampleTime, j)/factorial(j));

    I.eye(E.getCols()-2);
    ZeroVector.zeros( E.getCols()-2, 1);

    for (int i = 0; i < Mat.getRows(); i++)
    {
        E.add( 1, 1, 1 - Mat(1, i+1));
        Temp = E||(I|ZeroVector);
        Root = Temp.eigenvalues();
        float autovalor = max(abs(Root));
        this->A.add( i+1, i+1, autovalor);
    }
    this->B = (((this->A^-1)*(this->Ad - IAd))^-1)*this->Bd;
    this->C = this->Cd;
    this->D = this->Dd;
}


template <class UsedType>
void EqdifSim<UsedType>::c2d(float Time)
{
    this->SampleTime = Time;
    this->Ad.zeros(this->A.getRows(), this->A.getCols());
    for(int i = 0; i < 4; i++)
        this->Ad = this->Ad + (1/factorial(i))*(this->A^i)*(pow(this->SampleTime, i));
    this->Bd = this->A.inv()*(this->Ad - (this->Ad^0))*this->B;
    this->Cd = this->C;
    this->Dd = this->D;
    this->typeModel = "SSDiscrete";
}

template <class UsedType>
void EqdifSim<UsedType>::tf2ssc()
{
    Matrix<UsedType> I, ZeroVector, tempDen( 1, this->TransferFunction[0][0].getDen().getCols()-1);

    I.eye(this->TransferFunction[0][0].getDen().getCols()-2);
    ZeroVector.zeros( this->TransferFunction[0][0].getDen().getCols()-2, 1);
    for (int i = 2; i <= this->TransferFunction[0][0].getDen().getCols(); i++)
        tempDen.add( 1, i-1, -(this->TransferFunction[0][0].getDen()( 1, i)));

    this->A = tempDen||(I|ZeroVector);
    this->B.zeros(this->A.getRows(), 1);
    this->B.add( 1, 1, 1);

    if (this->TransferFunction[0][0].getNum().getCols() == 1)
    {
        this->C.add( 1, this->B.getRows(), this->TransferFunction[0][0].getNum()( 1, 1));
        this->D.add( 1, 1, 0);
    }
    else if (this->TransferFunction[0][0].getNum().getCols() < this->TransferFunction[0][0].getDen().getCols())
    {
        for (int i = this->B.getRows(); i > 1; i--)
            this->C.add( 1, i, this->TransferFunction[0][0].getNum()( 1, this->TransferFunction[0][0].getNum().getCols() -( this->B.getRows() - i )));
        this->D.add( 1, 1, 0);
    }

    else if (this->TransferFunction[0][0].getNum().getCols() == this->TransferFunction[0][0].getDen().getCols())
    {
        float B0 = this->TransferFunction[0][0].getNum()( 1, 1);

        for (int i = 1; i <= this->B.getRows(); i++)
         {
            this->C.add( 1, i, this->TransferFunction[0][0].getNum()( 1, i+1)- this->TransferFunction[0][0].getDen()( 1, i+1)*B0);
         }
        this->D.add( 1, 1,  B0);
    }
}

template <class UsedType>
void EqdifSim<UsedType>::tf2ssd()
{
    Matrix<UsedType> I, ZeroVector, tempDen( 1, this->DiscreteTransferFunction[0][0].getDen().getCols()-1);

    I.eye(this->DiscreteTransferFunction[0][0].getDen().getCols()-2);
    ZeroVector.zeros( this->DiscreteTransferFunction[0][0].getDen().getCols()-2, 1);
    for (int i = 2; i <= this->DiscreteTransferFunction[0][0].getDen().getCols(); i++)
        tempDen.add( 1, i-1, -(this->DiscreteTransferFunction[0][0].getDen()( 1, i)));

    this->Ad = tempDen||(I|ZeroVector);
    this->Bd.zeros(this->Ad.getRows(), 1);
    this->Bd.add( 1, 1, 1);

    if (this->DiscreteTransferFunction[0][0].getNum().getCols() == 1)
    {
        this->Cd.add( 1, this->Bd.getRows(), this->DiscreteTransferFunction[0][0].getNum()( 1, 1));
        this->Dd.add( 1, 1, 0);
    }
    else if (this->DiscreteTransferFunction[0][0].getNum().getCols() < this->DiscreteTransferFunction[0][0].getDen().getCols())
    {
        for (int i = this->Bd.getRows(); i > 1; i--)
            this->Cd.add( 1, i, this->DiscreteTransferFunction[0][0].getNum()( 1, this->DiscreteTransferFunction[0][0].getNum().getCols() -( this->Bd.getRows() - i )));
        this->Dd.add( 1, 1, 0);
    }

    else if (this->DiscreteTransferFunction[0][0].getNum().getCols() == this->DiscreteTransferFunction[0][0].getDen().getCols())
    {
        float B0 = this->DiscreteTransferFunction[0][0].getNum()( 1, 1);

        for (int i = 1; i <= this->Bd.getRows(); i++)
         {
            this->Cd.add( 1, i, this->DiscreteTransferFunction[0][0].getNum()( 1, i+1)- this->DiscreteTransferFunction[0][0].getDen()( 1, i+1)*B0);
         }
        this->Dd.add( 1, 1,  B0);
    }
}

template <class UsedType>
void EqdifSim<UsedType>::ss2tfc()
{
    Matrix<UsedType> tempB, tempC;

    this->TransferFunction = new Polynom<UsedType>*[this->C.getRows()];
    for(int i = 0; i < this->C.getRows(); i++)
        this->TransferFunction[i] = new Polynom<UsedType>[this->B.getCols()];

    for(int i = 1; i <= this->C.getRows(); i++)
        for(int j = 1; j<= this->B.getCols(); j++)
        {
            tempB = this->B.getColumn(j);
            tempC = this->C.getLine(i);

            this->TransferFunction[i-1][j-1] = Polynom<UsedType>((this->A - tempB*tempC).pol() - this->A.pol(), this->A.pol());
            this->TransferFunction[i-1][j-1] = this->TransferFunction[i-1][j-1] + this->D(i,j);
        }
}

template <class UsedType>
void EqdifSim<UsedType>::ss2tfd()
{
   Matrix<UsedType> tempBd, tempCd;

    this->DiscreteTransferFunction = new Polynom<UsedType>*[this->Cd.getRows()];
    for(int i = 0; i < this->Cd.getRows(); i++)
        this->DiscreteTransferFunction[i] = new Polynom<UsedType>[this->Bd.getCols()];

    for(int i = 1; i <= this->Cd.getRows(); i++)
        for(int j = 1; j<= this->Bd.getCols(); j++)
        {
            tempBd = this->Bd.getColumn(j);
            tempCd = this->Cd.getLine(i);

            this->DiscreteTransferFunction[i-1][j-1] = Polynom<UsedType>((this->Ad - tempBd*tempCd).pol() - this->Ad.pol(), this->Ad.pol());
            this->DiscreteTransferFunction[i-1][j-1] = this->DiscreteTransferFunction[i-1][j-1] + this->Dd(i,j);
        }

}

template <class UsedType>
void EqdifSim<UsedType>::setModel(std::string model)
{
    this->typeModel = model;
}

template <class UsedType>
void EqdifSim<UsedType>::printSS()
{

    if (this->typeModel == "SSDiscrete")
    {
        cout<<endl<<"Ad = "<<endl;
        this->Ad.print();
        cout<<endl<<endl<<"Bd = "<<endl;
        this->Bd.print();
        cout<<endl<<"Cd = "<<endl;
        this->Cd.print();
        cout<<endl<<"Dd = "<<endl;
        this->Dd.print();
        cout<<endl<<endl;
    }
    if (this->typeModel == "SSContinuous")
    {
        cout<<endl<<"A = "<<endl;
        this->A.print();
        cout<<endl<<"B = "<<endl;
        this->B.print();
        cout<<endl<<"C = "<<endl;
        this->C.print();
        cout<<endl<<"D = "<<endl;
        this->D.print();
        cout<<endl;
    }

}

template <class UsedType>
void EqdifSim<UsedType>::printTF()
{
    if(this->typeModel == "TFContinuous")
        for(int i = 1; i <= this->C.getRows(); i++)
            for(int j = 1; j <= this->B.getCols(); j++)
            {
                this->TransferFunction[i-1][j-1].setVar('s');
                this->TransferFunction[i-1][j-1].print();
            }

    if(this->typeModel == "TFDiscrete")
        for(int i = 1; i <= this->Cd.getRows(); i++)
            for(int j = 1; j <= this->Bd.getCols(); j++)
            {
                this->TransferFunction[i-1][j-1].setVar('z');
                this->DiscreteTransferFunction[i-1][j-1].print();
            }
}

template <class UsedType>
void EqdifSim<UsedType>::print()
{
    int a  = this->typeModel.find("SS");
    cout<<endl<< "The type of the model is " << this->typeModel << endl;
    if (a != -1)
        this->printSS();
    else
        this->printTF();
}

template <class UsedType>
Matrix<UsedType> EqdifSim<UsedType>::Simulation(Matrix<UsedType> SystemInput, bool getState)
{
    int SampleLength = SystemInput.getCols();
    Matrix<UsedType> X(this->A.getRows(), SampleLength);
    Matrix<UsedType> SystemOutput(this->C.getRows(), SampleLength);

    for(int i = 1; i <= SampleLength; i++)
    {
        X.setLine(i+1, this->Ad*X.getColumn(i) + this->Bd*SystemInput.getColumn(i));
        SystemOutput = this->Cd*X.getLine(i+1) + this->Dd*SystemInput.getColumn(i);
    }

    if(getState == 0)
        return SystemOutput;
    else
        return X;
}

//---------------------------------------------------------------------------------
template <class UsedType>
UsedType EqdifSim<UsedType>::factorial(float n)
{
    UsedType retval = 1;

    for (int i = n; i > 1; --i)
        retval *= i;

    return retval;
}

//class template EqdifSim<int>;
template class EqdifSim <float>;
template class EqdifSim <double>;
