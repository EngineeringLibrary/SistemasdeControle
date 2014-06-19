#ifndef LSIM_H
#define LSIM_H

#include "matrix.h"
#include "fstream"

class Lsim
{
    private:
        Matrix output, input, Phi, A, X, b, PeriodicTime;//Saídas,Entradas,Matriz montada a partir dos dados, coeficientes, Saída simulada
        string Model;

    public:
        Lsim();
        void addIO(Matrix in, Matrix out);
        friend void addIO(const char *namefile, Lsim Sis);
        void modelCoef(Matrix coef);
    //Modelos polinomiais
        void polyModel(int grau);
        void simPoly(int grau);
        void polyCoef(int grau);
    //Modelos ARX (Auto Recursive with eXogenous output)
        void arxModel(int ny, int nu);
        void arxModelOneStep(int ny, int nu, int line);
        Matrix simArxOneStep(int ny, int nu, Matrix ArxPar);
        void simArx(int ny, int nu);
        void arxCoef(int ny, int nu);
    //Modelos de equações diferenciais
        void eqdifModel(float h);
        void eqdifCoef(float h);
    //Retornando a entrada e a saída
        Matrix getInput();
        Matrix getOutput();

};

#endif // LSIM_H
