#include "SistemasdeControle/headers/restrictedOptimization/simplex.h"

template <typename Type>
void restrictedOptimizationHandler::simplex<Type>::optimize()
{
    if(this->N.A.getNumberOfColumns() == 0 && this->N.A.getNumberOfRows() == 0)
    {
        this->A = (this->P.A | LinAlg::Eye<Type>(this->P.A.getNumberOfRows())                               | LinAlg::Zeros<Type>(this->N.A.getNumberOfRows(),this->N.A.getNumberOfRows())) ||
                  (this->N.A | LinAlg::Zeros<Type>(this->P.A.getNumberOfRows(),this->P.A.getNumberOfRows()) | -LinAlg::Eye<Type>(this->N.A.getNumberOfRows()));
        this->b = this->P.b || this->N.b;
        this->A = this->A   | LinAlg::Eye<Type>(this->A.getNumberOfRows())||
                  this->E.A | LinAlg::Zeros<Type>(this->E.A.getNumberOfRows(),this->A.getNumberOfRows());
        this->b = this->P.b || this->E.b;
//        LinAlg::Matrix<Type> c = this->function2Optimize || LinAlg::Zeros<Type>(1,this->P.b.getNumberOfRows() - this->E.b.getNumberOfRows() + this->N.b.getNumberOfRows());
        LinAlg::Matrix<Type> w = LinAlg::Zeros<Type>(A.getNumberOfColumns() - this->P.A.getNumberOfRows(),1)||
                                 LinAlg::Ones<Type>(this->P.A.getNumberOfRows(),this->P.A.getNumberOfRows());
        LinAlg::Matrix<Type> B = LinAlg::LineVector<Type>(this->A.getNumberOfColumns() - this->P.A.getNumberOfRows() +1, this->A.getNumberOfColumns(),1);
        LinAlg::Matrix<Type> n = LinAlg::LineVector<Type>(1,this->A.getNumberOfColumns() - this->P.A.getNumberOfRows());
        simplexOptimization(w,A,b,B,N);
        this->x = this->x(1,from(1)-->this->x.getNumberOfRows()-this->P.A.getNumberOfRows());
        this->A = this->A(from(1)-->this->A.getNumberOfRows(),from(1)-->this->x.getNumberOfRows()-this->P.A.getNumberOfRows());
        LinAlg::Matrix<Type> c = this->function2Optimize ||
                                 LinAlg::Zeros<Type>(1, this->b.getNumberOfColumns());
        n = n(1,from(1)-->n.getNumberOfColumns()-this->P.A.getNumberOfRows());
        simplexOptimization(c,A,b,B,n);
    }
    else
    {
        this->A = (this->P.A | LinAlg::Eye<Type>(this->P.A.getNumberOfRows()))||
                  (this->E.A | LinAlg::Zeros<Type>(this->E.A.getNumberOfRows(),this->P.A.getNumberOfRows()));
        this->b = this->P.b || this->E.b;

        LinAlg::Matrix<Type> c = this->function2Optimize ||
                                 LinAlg::Zeros<Type>(1, this->b.getNumberOfColumns());

        LinAlg::Matrix<Type> B = LinAlg::LineVector<Type>(this->A.getNumberOfColumns() - this->P.A.getNumberOfRows() +1, this->A.getNumberOfColumns(),1);
        LinAlg::Matrix<Type> n = LinAlg::LineVector<Type>(1,this->A.getNumberOfColumns() - this->P.A.getNumberOfRows());
        simplexOptimization(c,A,b,B,n);
    }
}

template <typename Type>
void restrictedOptimizationHandler::simplexOptimization(const LinAlg::Matrix<Type> &c,
                                                        const LinAlg::Matrix<Type> &A,
                                                        const LinAlg::Matrix<Type> &b,
                                                        const LinAlg::Matrix<Type> &B,
                                                        const LinAlg::Matrix<Type> &N)
{
//    %% selecione uma base B e calcule B^-1
    LinAlg::Matrix<Type> Ab = A(from(1)-->this->A.getNumberOfRows(),B);
    LinAlg::Matrix<Type> Abinv = Ab^-1;
//    %% Verifique o vetor dos custos reduzidos
    while(1)
    {
        LinAlg::Matrix<Type> cn = c(1,N);
        LinAlg::Matrix<Type> cb = c(1,B);
        LinAlg::Matrix<Type>An = A(from(1)-->this->A.getNumberOfRows(),N);
        Ab = A(from(1)-->this->A.getNumberOfRows(),B);
        LinAlg::Matrix<Type> r = (~cn) - (~cb)*Abinv*An;
        this->cost = (~cb)*Abinv*b;
        LinAlg::Matrix<Type> xb = Abinv*b;
        unsigned contFlag = 0;
        for (unsigned i=1; i <= r.getNumberOfColumns(); ++i)
           if(r(1,i) >= 0)
           {
               contFlag = contFlag + 1;
%               break;
           }
        if(contFlag == r.getNumberOfColumns())
            break;
        //%determine o vetor de chegada
        unsigned indMinD = LinAlg::lineOfMinValue(~r);

        X = Abinv*An(from(1)-->An.getNumberOfRows(),indMinD);
        LinAlg::Matrix<Type> d = LinAlg::divPoint(xb,X);
        unsigned dMin = inf;
        unsigned indMinB = 1;
        for (unsigned i = 1; i < d.getNumberOfRows(); ++i)
           if(X(i,1) > 0 && d(i,1) < dMin)
           {
//%                if(testeRestricao(Binv,Xb,X,i,indMinD,B,a,RevSimpForm))
//                 {
               dMin = d(i,1);
               indMinB = i;
//                 }
           }
//%
        Abinv = EscalSimplex((Abinv | xb | X),indMinB);
        Bout = B(1,indMinB);
        Nout = N(1,indMinD);
        N = N(1,from(1)-->(indMinD-1)) | Bout | N(1, from(indMinD+1)-->(N.getNumberOfColumns()));
        B = B(1,from(1)-->(indMinB-1)) | Nout | B(1,from(indMinB+1)-->(B.getNumberOfColumns()));
    }

    x = xb || LinAlg::Zeros<Type>(An.getNumberOfColumns(),1),1;
    LinAlg::Matrix<Type> ind = LinAlg::sortColumnVector<Type>(B|N);
    x = x(ind,1);
    N = LinAlg::sortColumnVector<Type>(N);
    B = LinAlg::sortColumnVector<Type>(B);

}

template <typename Type>
LinAlg::Matrix<Type> restrictedOptimizationHandler::EscalSimplex(LinAlg::Matrix<Type> A,
                                                                 unsigned index)
{
    for(unsigned i = 1; i <= A.getNumberOfColumns(); ++i)
        A(index,i) = A(index,i)/A(index,A.getNumberOfColumns());

    for (unsigned i = 1; i <= A.getNumberOfRows(); ++i)
        if(i ~= index)
        {
            m = A(i,A.getNumberOfColumns())/A(index,A.getNumberOfColumns());
            for(unsigned j = 1; j <= A.getNumberOfColumns(); ++j)
                A(i,j)=A(i,j)-m*A(index,j);
        }

    Xb   = A(from(1)-->A.getNumberOfRows(),A.getNumberOfColumns()-1);
    Binv = A(from(1)-->A.getNumberOfRows(),from(1)-->A.getNumberOfColumns()-2);
    X    = A(from(1)--> A.getNumberOfRows(),A.getNumberOfColumns());
    return Binv;
}
