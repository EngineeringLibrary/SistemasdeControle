#include "eqdifsim.h"

EqdifSim::EqdifSim()
{

}

EqdifSim::EqdifSim(Matrix AdIn, Matrix BdIn, Matrix CdIn, Matrix DdIn, float Time)
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

EqdifSim::EqdifSim(Matrix AIn, Matrix BIn, Matrix CIn, Matrix DIn)
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

EqdifSim::EqdifSim(Matrix NumdIn, Matrix DendIn, float Time)
{
    this->Numd = NumdIn;
    this->Dend = DendIn;
    this->SampleTime = Time;
    tf2ssd();
    d2c();
    ss2tfc();
    this->typeModel = "TFDiscrete";
}

EqdifSim::EqdifSim(Matrix NumIn, Matrix DenIn)
{
    this->Num = NumIn;
    this->Den = DenIn;
//    this->SampleTime = 0.1;
    tf2ssc();
    c2d(0.1);
    ss2tfd();
    this->typeModel = "TFContinuous";

}

void EqdifSim::c2d(float Time)
{
    this->SampleTime = Time;
    this->Ad.zeros(this->A.getRows(), this->A.getCols());
    for(int i = 0; i < 4; i++)
        this->Ad = this->Ad + (1/factorial(i))*(this->A^i)*(pow(this->SampleTime, i));
    this->Bd = this->A.inv()*(this->Ad - (this->Ad^0))*this->B;
    this->Cd = this->C;
    this->Dd = this->D;
//    this->typeModel = "SSDiscrete";

}

void EqdifSim::d2c()
{
    Matrix Mat, E, Temp, Root, I, ZeroVector, IAd;

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



void EqdifSim::printSS()
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
    else
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

void EqdifSim::printTF()
{
    int maxSize;
    char x;
    Matrix num, den;

    if(this->typeModel == "TFContinous")
    {
        num = this->Num;
        den = this->Den;
        x = 's';
    }
    else
    {
        num = this->Numd;
        den = this->Dend;
        x = 'z';
    }
    if(num.length() > den.length())
        maxSize = num.length();
    else
        maxSize = den.length();

    if(den.length() == 0)
    {
        if(num.length() >= 2)
        {
            for(int i = 0; i < num.length() - 2; i++)
            {
                if(num( 1, i+1) != 0)
                {
                    if(num( 1, i+1) != 1)
                        std::cout << num( 1, i+1);
                    std::cout << x << '^' << num.length() - i - 1 << ' ';
                    if(i != num.length() - 3)
                        std::cout << '+' << ' ';
                }
            }
            if(num( 1, num.length() - 1)  != 0)
            {
                if(num( 1, num.length() - 1) != 1)
                        std::cout << '+' << ' ' << num( 1, num.length() - 1);
                std::cout << x << ' ';
            }
        }
        if(num( 1, num.length()) != 0)
            std::cout << '+' << ' ' << num( 1, num.length()) << '\n';

    }
    else {
        if(num.length() >= 2)
        {
            for(int i = 0; i < num.length() - 2; i++)
            {
                if(num( 1, i+1) != 0)
                {
                    if(num( 1, i+1) != 1)
                        std::cout << num( 1, i+1);
                    std::cout << x << '^' << num.length() - i - 1 << ' ';
                    if( i != num.length() - 3)
                       std::cout << '+' << ' ';
                }
            }
            if(num( 1, num.length() - 1) != 0)
            {
                if(num( 1, num.length() - 1) != 1)
                    std::cout << num( 1, num.length() - 1);
                std::cout << x << ' ';
            }
        }
        if(num( 1, num.length()) != 0)
            std::cout << '+' << ' ' << num( 1, num.length()) << '\n';

        for(int i = 0; i < maxSize; i++)
            std::cout << '-' << '-' << '-' << '-' << '-';
        std::cout << '\n';

        if(den.length() >= 2)
        {
            for(int i = 0; i < den.length() - 2; i++)
            {
                if(den( 1, i+1) != 0)
                {
                    if(den( 1, i+1) != 1)
                        std::cout << den( 1, i+1);
                    std::cout << x << '^' << den.length() - i - 1 << ' ';
                    if(i != den.length() - 3)
                       std::cout << '+' << ' ';
                }
            }
            if(den( 1, den.length() - 1)  != 0)
            {
                if(den( 1, den.length() - 1)  != 1)
                   std::cout << '+' << ' ' << den( 1, den.length() - 1);
                std::cout << x << ' ';
            }
        }
       if(den( 1, den.length())  != 0)
           std::cout << '+' << ' ' << den( 1, den.length()) ;
    }
    std::cout << '\n';
}

void EqdifSim::print()
{
    int a  = this->typeModel.find("SS");
    if (a != -1)
        this->printSS();
    else
        this->printTF();
}

void EqdifSim::tf2ssc()
{
    Matrix I, ZeroVector, tempDen( 1, this->Den.getCols()-1);

    I.eye(this->Den.getCols()-2);
    ZeroVector.zeros( this->Den.getCols()-2, 1);
    for (int i = 2; i <= this->Den.getCols(); i++)
        tempDen.add( 1, i-1, -(this->Den( 1, i)));

    this->A = tempDen||(I|ZeroVector);
    this->B.zeros(this->A.getRows(), 1);
    this->B.add( 1, 1, 1);

    if (this->Num.getCols() == 1)
    {
        this->C.add( 1, this->B.getRows(), this->Num( 1, 1));
        this->D.add( 1, 1, 0);
    }
    else if (this->Num.getCols() < this->Den.getCols())
    {
        for (int i = this->B.getRows(); i > 1; i--)
            this->C.add( 1, i, this->Num( 1, this->Num.getCols() -( this->B.getRows() - i )));
        this->D.add( 1, 1, 0);
    }

    else if (this->Num.getCols() == this->Den.getCols())
    {
        float B0 = this->Num( 1, 1);

        for (int i = 1; i <= this->B.getRows(); i++)
         {
            this->C.add( 1, i, this->Num( 1, i+1)- this->Den( 1, i+1)*B0);
         }
        this->D.add( 1, 1,  B0);
    }
}

void EqdifSim::tf2ssd()
{
    Matrix I, ZeroVector, tempDen( 1, this->Dend.getCols()-1);

    I.eye(this->Dend.getCols()-2);
    ZeroVector.zeros( this->Dend.getCols()-2, 1);
    for (int i = 2; i <= this->Dend.getCols(); i++)
        tempDen.add( 1, i-1, -(this->Dend( 1, i)));

    this->Ad = tempDen||(I|ZeroVector);
    this->Bd.zeros(this->Ad.getRows(), 1);
    this->Bd.add( 1, 1, 1);

    if (this->Numd.getCols() == 1)
    {
        this->Cd.add( 1, this->Bd.getRows(), this->Numd( 1, 1));
        this->Dd.add( 1, 1, 0);
    }
    else if (this->Numd.getCols() < this->Dend.getCols())
    {
        for (int i = this->Bd.getRows(); i > 1; i--)
            this->Cd.add( 1, i, this->Numd( 1, this->Numd.getCols() -( this->Bd.getRows() - i )));
        this->Dd.add( 1, 1, 0);
    }

    else if (this->Numd.getCols() == this->Dend.getCols())
    {
        float B0 = this->Numd( 1, 1);

        for (int i = 1; i <= this->Bd.getRows(); i++)
         {
            this->Cd.add( 1, i, this->Numd( 1, i+1)- this->Dend( 1, i+1)*B0);
         }
        this->Dd.add( 1, 1,  B0);
    }
}

void EqdifSim::ss2tfc()
{
    Matrix Temp;

    Temp = this->A - (this->B*this->C);
    this->Num = Temp.pol();
    Num.print();
    this->Den = this->A.pol();
    Den.print();
}

void EqdifSim::ss2tfd()
{
    Matrix Temp, I;

    I.eye(this->Ad.getRows());

    Temp = this->A - (this->Bd*this->Cd);
    this->Numd = Temp.pol();
    Numd.print();
    Dend.print();
//      Temp = this->Cd*((I - this->Ad)^-1)*this->Bd + this->Dd;
//      Temp.print();
}


//Matrix EqdifSim::sumPoly()
//{
//        Matrix ret;
//        unsigned int maxNum, difNum;

//        if(vNumSize1 > vNumSize2) {
//            difNum = vNumSize1 - vNumSize2;
//            maxNum = vNumSize1;
//            ret = (double*)calloc(vNumSize1, sizeof(double));
//            for(unsigned int i = 0; i < maxNum; i++) {
//                if(i >= difNum)
//                    ret[i] = vNum2[i - difNum] + vNum1[i];
//                else
//                    ret[i] = vNum1[i];
////              ret.print();
//            }
//        }
//        else {
//            difNum = vNumSize2 - vNumSize1;
////          std::cout << difNum;
//            maxNum = vNumSize2;
//            ret = (double*)calloc(vNumSize2, sizeof(double));
//            for(unsigned int i = 0; i < maxNum; i++) {
//                if(i >= difNum)
//                    ret[i] = vNum2[i] + vNum1[i - difNum];
//                else
//                    ret[i] = vNum2[i];
////              ret.print();
//            }
//        }
//        return ret;
//}

float EqdifSim::factorial(float n)
{
    float retval = 1;

    for (int i = n; i > 1; --i)
        retval *= i;

    return retval;
}
