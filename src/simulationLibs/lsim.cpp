#include "lsim.h"

template  <class UsedType>
Lsim<UsedType>::Lsim()
{

}

template  <class UsedType>
void Lsim<UsedType>::addIO(Matrix<UsedType> in, Matrix<UsedType> out)
{
    this->input = in;
    this->output = out;
}

template  <class UsedType>
void Lsim<UsedType>::modelCoef(Matrix<UsedType> coef)
{
    this->X = coef;
}

template  <class UsedType>
void Lsim<UsedType>::polyModel(int grau)
{
    this->Model = "polinomial";
    this->input.print();
    this->A.ones(this->input.getRows(),1);
    for(int i = 1; i <= grau; i++)
        this->A = this->A|(this->input>i);
}

template  <class UsedType>
void Lsim<UsedType>::simPoly(int grau)
{
    this->polyModel(grau);
    this->b = this->A*this->X;
}

template  <class UsedType>
void Lsim<UsedType>::polyCoef(int grau)
{
    this->polyModel(grau);
    this->X = ((~this->A*this->A)^-1)*(~this->A)*this->output;
}

//Modelos ARX (Auto Recursive with eXogenous output)

template  <class UsedType>
void Lsim<UsedType>::arxModel(int ny, int nu)
{
    int maxNuNy,minRowInOut;
    this->Model = "ARX";

    if(ny>nu)
        maxNuNy = ny;
    else
        maxNuNy = nu;

    if(this->output.getRows() > this->input.getRows())
        minRowInOut = this->input.getRows();
    else
        minRowInOut = this->output.getRows();

    for(int i = maxNuNy; i < minRowInOut; i++)
    {
        this->b.add(i-maxNuNy+1,1,this->output( i, 1));
        for(int j = 0; j < nu+ny; j++)
        {
            if(j<ny)
                this->A.add(i-maxNuNy+1,j+1,-this->output( i-ny+j,1));
            else
                this->A.add(i-maxNuNy+1,j+1,this->input( i-nu-ny+j, 1));
        }
    }

}

template  <class UsedType>
void Lsim<UsedType>::arxModelOneStep(int ny, int nu, int line)
{

    this->Model = "ARX";

    for(int j = 0; j < nu+ny; j++)
    {
        if(j<ny)
            this->Phi.add(1,j+1,-this->b(line-ny+j+1, 1));
        else
            this->Phi.add(1,j+1,this->input(line-nu-ny+j+1, 1));
    }

}

template  <class UsedType>
void Lsim<UsedType>::arxModelOneStepReal(int ny, int nu, int line)
{

    this->Model = "ARX";

    for(int j = 0; j < nu+ny; j++)
    {
        if(j<ny)
            this->Phi.add(1,j+1,-this->output(line-j-1, 1));
        else
            this->Phi.add(1,j+1,this->input(line+ny-j-1, 1));
    }

}

template  <class UsedType>
Matrix<UsedType> Lsim<UsedType>::getArxPhi(int ny, int nu, int line)
{
    this->arxModelOneStepReal(ny, nu, line);
    return this->Phi;
}

template  <class UsedType>
Matrix<UsedType> Lsim<UsedType>::simArxOneStep(int ny, int nu, Matrix<UsedType> ArxPar)
{
//    double TempOutput;
    int maxNuNy,minRowInOut;
    this->b = this->output;


    if(ny>nu)
        maxNuNy = ny;
    else
        maxNuNy = nu;

    if(this->output.getRows() > this->input.getRows())
        minRowInOut = this->input.getRows();
    else
        minRowInOut = this->output.getRows();

    for(int i = maxNuNy; i < minRowInOut; i++)
    {
        arxModelOneStep(ny, nu, i);
        this->b.add(i+1, 1, (this->Phi*~ArxPar)(1,1));
    }

    return this->b;

}

template  <class UsedType>
void Lsim<UsedType>::simArx(int ny, int nu)
{
    this->arxModel(ny,nu);
    this->b = this->A*this->X;
}

template  <class UsedType>
void Lsim<UsedType>::arxCoef(int ny, int nu)
{
    this->arxModel(ny,nu);
    this->X = ((~this->A*this->A)^-1)*(~this->A)*this->b;
}

template  <class UsedType>
void Lsim<UsedType>::eqdifModel(UsedType h)
{
    Matrix<UsedType> dy, d2y;
    dy = diff(this->output,h);
    d2y = diff(dy,h);

    for(int i = 0; i < d2y.getRows(); i++)
    {
        this->A.add(i+1,1,-this->output( i, 1));
        this->A.add(i+1,2,-dy( i, 1));
        this->A.add(i+1,3,this->input( i, 1));
    }
    this->b = d2y;
}

template  <class UsedType>
void Lsim<UsedType>::eqdifCoef(UsedType h)
{
    this->eqdifModel(h);
    this->X = ((~this->A*this->A)^-1)*(~this->A)*this->b;
}

template  <class UsedType>
Matrix<UsedType> Lsim<UsedType>::getInput()
{
    return this->input;
}

template  <class UsedType>
Matrix<UsedType> Lsim<UsedType>::getOutput()
{
    return this->output;
}

template  <class UsedType>
void addIO(const char *namefile, Lsim<UsedType> Sis)
{
    ifstream myfile(namefile);
    string data;

        try
        {
            if (!myfile.is_open())
                throw "Nao foi possivel abrir o arquivo";
            else
            {
                int posBar;
                string input = "", output = "", time = "";


                while(!myfile.eof())
                {
                    getline( myfile, data);
                    posBar = data.find("|");
                    input = input + data.substr( 0, posBar) + ";";
                    data.erase( 0, posBar+1);
                    posBar = data.find("|");
                    output = output + data.substr(0, posBar) + ";";
                    data.erase( 0, posBar+1);
                    time = time + data + ";";
                }
                myfile.close();

                Sis.input = input;
                Sis.output = output;
                Sis.PeriodicTime = time;
            }

        }
        catch(const char* msg)
        {
            cerr<<msg<<endl;
        }
}

//template class Lsim<int>;
template class Lsim<float>;
template class Lsim<double>;
