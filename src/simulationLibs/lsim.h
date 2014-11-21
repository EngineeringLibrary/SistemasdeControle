#ifndef __LSIM_H_INCLUDED
#define __LSIM_H_INCLUDED

#include "..\primitiveLibs\matrix.h"
#include "fstream"

template <class UsedType>
class Lsim
{
    private:
        Matrix<UsedType> output, input, Phi, A, X, b, PeriodicTime;//Saídas,Entradas,Matriz montada a partir dos dados, coeficientes, Saída simulada
        string Model;

    public:
        Lsim();
        void addIO(Matrix<UsedType> in, Matrix<UsedType> out);
        template <class FriendType> friend void addIO(const char *namefile, Lsim<FriendType> Sis);
        void modelCoef(Matrix<UsedType> coef);
    //Modelos polinomiais
        void polyModel(int grau);
        void simPoly(int grau);
        void polyCoef(int grau);
    //Modelos ARX (Auto Recursive with eXogenous output)
        void arxModel(int ny, int nu);
        void arxModelOneStep(int ny, int nu, int line);
        void arxModelOneStepReal(int ny, int nu, int line);
        Matrix<UsedType> getArxPhi(int ny, int nu, int line);
        Matrix<UsedType> simArxOneStep(int ny, int nu, Matrix<UsedType> ArxPar);
        void simArx(int ny, int nu);
        void arxCoef(int ny, int nu);
    //Modelos de equações diferenciais
        void eqdifModel(UsedType h);
        void eqdifCoef(UsedType h);
    //Retornando a entrada e a saída
        Matrix<UsedType> getInput();
        Matrix<UsedType> getOutput();
//        Matrix<UsedType> getPhi(int ny, int nu, int line);
};

#endif // LSIM_H
