#include "lsim.h"

Lsim::Lsim()
{

}

void Lsim::addIO(Matrix in, Matrix out)
{
    this->input = in;
    this->output = out;
}




void Lsim::modelCoef(Matrix coef)
{
    this->X = coef;
}
void Lsim::polyModel(int grau)
{
    this->Model = "polinomial";
    this->input.print();
    this->A.ones(this->input.getRows(),1);
    for(int i = 1; i <= grau; i++)
        this->A = this->A|(this->input>i);
}

void Lsim::simPoly(int grau)
{
    this->polyModel(grau);
    this->b = this->A*this->X;
}

void Lsim::polyCoef(int grau)
{
    this->polyModel(grau);
    this->X = ((~this->A*this->A)^-1)*(~this->A)*this->output;
}

//Modelos ARX (Auto Recursive with eXogenous output)

void Lsim::arxModel(int ny, int nu)
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

void Lsim::arxModelOneStep(int ny, int nu, int line)
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

Matrix Lsim::simArxOneStep(int ny, int nu, Matrix ArxPar)
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

void Lsim::simArx(int ny, int nu)
{
    this->arxModel(ny,nu);
    this->b = this->A*this->X;
}

void Lsim::arxCoef(int ny, int nu)
{
    this->arxModel(ny,nu);
    this->X = ((~this->A*this->A)^-1)*(~this->A)*this->b;
}

void Lsim::eqdifModel(float h)
{
    Matrix dy, d2y;
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

void Lsim::eqdifCoef(float h)
{
    this->eqdifModel(h);
    this->X = ((~this->A*this->A)^-1)*(~this->A)*this->b;
}

Matrix Lsim::getInput()
{
    return this->input;
}

Matrix Lsim::getOutput()
{
    return this->output;
}

void addIO(const char *namefile, Lsim Sis)
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
