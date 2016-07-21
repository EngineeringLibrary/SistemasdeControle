#include "SistemasdeControle/headers/restrictedOptimization/activeset.h"

//template <typename Type>
//restrictedOptimizationHandler::activeSet<Type>::activeSet()
//{

//}

template <typename Type>
void restrictedOptimizationHandler::activeSet<Type>::optimize()
{
//    this->tol = 1e-2;
//    this->initializeMethod(this->P.A,this->P.b,this->N.A,this->N.b);
    LinAlg::Matrix<Type> A0 = this->P.A || -this->N.A;
    LinAlg::Matrix<Type> b0 = this->P.b || -this->N.b;
    this->activeSetMethod(this->QuadMat,this->LinMat,A0,b0,this->tol);
}

template <typename Type>
void restrictedOptimizationHandler::activeSet<Type>::initializeMethod(const LinAlg::Matrix<Type> &Ap,
                                                                      const LinAlg::Matrix<Type> &bp,
                                                                      const LinAlg::Matrix<Type> &An,
                                                                      const LinAlg::Matrix<Type> &bn,
                                                                      Type tol)
{
    simplex<Type> simp;
    simp.setRestrictions(this->E,this->N,this->P);
    simp.setfunction2Optimize(-LinAlg::Ones<Type>(this->P.b.getNumberOfRows(),1));
    simp.optimize();
    this->x = simp.getOptimizatedValue();
    this->set = simp.getSet();

    this->x   = this->x(from(1)-->this->P.A.getNumberOfColumns(),1);
//    std::cout <<"\n\n"<< this->x << "\n\n";
    this->set = this->set(1,from(1)-->this->P.A.getNumberOfColumns());
//    std::cout <<"\n\n"<< this->set << "\n\n";
}

template <typename Type>
void restrictedOptimizationHandler::activeSet<Type>::activeSetMethod(const LinAlg::Matrix<Type> &P,
                                                                     const LinAlg::Matrix<Type> &q,
                                                                     const LinAlg::Matrix<Type> &A0,
                                                                     const LinAlg::Matrix<Type> &b0,
                                                                     Type tol)
{
//    std::cout << this->x;
//    LinAlg::Matrix<Type> S = this->activeRestrictions(A0,b0,tol);
//    std::cout << S;

    this->x = (((~this->QuadMat)*this->QuadMat)^-1)*(~this->QuadMat)*-this->LinMat;
    LinAlg::Matrix<Type> Cov = LinAlg::Eye<Type>(A0.getNumberOfColumns())*1e8;
//    LinAlg::Matrix<Type> S = this->activeRestrictions(A0,b0,tol);
//    std::cout << S;

    while(1){
        LinAlg::Matrix<Type> S = this->activeRestrictions(A0,b0,tol);
//        std::cout << S;
        if(S.getNumberOfColumns() == 0)
            break;
        LinAlg::Matrix<Type> A = A0(S,from(1)-->A0.getNumberOfColumns());
        LinAlg::Matrix<Type> b = b0(S,1);
        this->RKKT(A,b,Cov,this->x);
//        std::cout << Cov << this->x;
    }

//    if(S.getNumberOfColumns() > P.getNumberOfRows())
//        S = S(1,from(1)-->P.getNumberOfRows());

//    if(S.getNumberOfColumns() == 0 || S.getNumberOfRows() == 0)
//        S = LinAlg::Matrix<Type>(1);

//    unsigned contS = 0;
//    for(unsigned terminate = 1; terminate <= 100; ++terminate)
//    {
//        LinAlg::Matrix<Type> A = A0(S,from(1)-->A0.getNumberOfColumns());
//        LinAlg::Matrix<Type> b = b0(S,1);
//        LinAlg::Matrix<Type> Xeqp,v,t(b0.getNumberOfRows(),1);

//        this->KKT(A,b,Xeqp,v);
////        std::cout << "\n\n" << Xeqp << "\n\n" << v << "\n\n";

//        if(LinAlg::sumOfColumnsElements(A0*Xeqp - b0 <= tol)(1,1) == b0.getNumberOfRows())
//        {
//            if(v.getNumberOfRows() == 0)
//            {
//                this->x = Xeqp;
//                break;
//            }
//            else if((LinAlg::sumOfColumnsElements<Type>(v >= 0.0)(1,1) == v.getNumberOfRows()))
//            {
//               this->x = Xeqp;
//               break;
//            }
//            else
//            {
//               for (unsigned i = 1; i <= v.getNumberOfRows(); ++i)
//               {
//                    if(v(i,1)< 0)
//                    {
//                        S.removeColumn(i);
//                        contS = S.getNumberOfColumns();
//                        break;
//                    }
//                }
//            }

//            this->x = Xeqp;
//        }
//        else
//        {
//            LinAlg::Matrix<Type> pos;
//            A = LinAlg::Matrix<Type>();
//            b = LinAlg::Matrix<Type>();
//            t = LinAlg::Zeros<Type>(b0.getNumberOfRows(),1);
//            for (unsigned i = 1; i<= A0.getNumberOfRows(); ++i)
//            {
//               if((A0(i,from(1)-->A0.getNumberOfColumns())*Xeqp)(1,1) > b0(i,1))
//               {
//                   A = A || A0(i,from(1)-->A0.getNumberOfColumns());
//                   b = b || LinAlg::Matrix<Type>(b0(i,1));
//                   LinAlg::Matrix<Type> tTemp = (b0(i,1) - (A0(i,from(1)-->A0.getNumberOfColumns())*this->x)(1,1)/((A0(i,from(1)-->A0.getNumberOfColumns())*(Xeqp-this->x))(1,1)));
//                   LinAlg::Matrix<Type> xTemp =  this->x + tTemp*(Xeqp - this->x);
//                   if(LinAlg::sumOfColumnsElements<Type>((A0*xTemp - b0) <= tol)(1,1) == b0.getNumberOfRows())
//                   {
//                       t = t|tTemp;
//                       pos = pos | i;
//                   }
//               }
//             }
//            Type MaxT = LinAlg::MaxValue(t);
//            unsigned posMax = LinAlg::lineOfMaxValue(t);
//            this->x = this->x + MaxT*(Xeqp - this->x);
//            if(S.getNumberOfColumns() < this->QuadMat.getNumberOfRows() && pos.getNumberOfColumns() != 0 && pos.getNumberOfRows() != 0)
////            {
////               contS = contS+1;
////               S(1,contS) = pos(1,posMax);
//                S = S | pos(1,posMax);
////            }
////            else
////            {
////               contS = 0;
////            }
//        }
//    }
}

template <typename Type>
LinAlg::Matrix<Type> restrictedOptimizationHandler::activeSet<Type>::activeRestrictions(const LinAlg::Matrix<Type> &A,
                                                                                        const LinAlg::Matrix<Type> &b,
                                                                                        Type tol)
{
    LinAlg::Matrix<Type> restrictionsTest = (A*this->x - b), ind;
//    std::cout << restrictionsTest;
    for(unsigned i = 1; i <= restrictionsTest.getNumberOfRows(); ++i)
        if(restrictionsTest(i,1) >= tol)
            ind = ind | Type(i);
    return ind;
}

template <typename Type>
void restrictedOptimizationHandler::activeSet<Type>::KKT(LinAlg::Matrix<Type> A,
                                                         LinAlg::Matrix<Type> b,
                                                         LinAlg::Matrix<Type> &x,
                                                         LinAlg::Matrix<Type> &v)
{
    LinAlg::Matrix<Type> K = (this->QuadMat | (~A)) ||
                             (A | LinAlg::Zeros<Type>(A.getNumberOfRows(),A.getNumberOfRows()));
//    std::cout << "\n\n" << K << "\n\n";
    LinAlg::Matrix<Type> L = -this->LinMat || b;
    LinAlg::Matrix<Type> S = (((~K)*K)^-1)*(~K)*L;
    x = S(from(1)-->this->LinMat.getNumberOfRows(),1);
    if(A.getNumberOfRows() > 0)
        v = S(from(this->LinMat.getNumberOfRows()+1)-->(this->LinMat.getNumberOfRows() + b.getNumberOfRows()),
              from(1)-->S.getNumberOfColumns());
}

template <typename Type>
void restrictedOptimizationHandler::activeSet<Type>::RKKT(LinAlg::Matrix<Type> A,
                                                          LinAlg::Matrix<Type> b,
                                                          LinAlg::Matrix<Type> &P,
                                                          LinAlg::Matrix<Type> &x)
{
    LinAlg::Matrix<Type> PHI = A;
    LinAlg::Matrix<Type> Y = b;
    LinAlg::Matrix<Type> E,K;
//    x = LinAlg::Ones<Type>(A.getNumberOfColumns(),1)/1e6;
    Type lambda = 1;

    for(unsigned i = 1; i <= PHI.getNumberOfRows(); ++i)
    {
        LinAlg::Matrix<Type> phi = PHI.GetRow(i);
        E = ~Y.GetRow(i) - ~(phi*x);
        K = (P*~phi)/(((phi*P)*~phi) + lambda);
        LinAlg::Matrix<Type> KxE;
        for(unsigned i = 1; i <= Y.getNumberOfColumns(); ++i)
            KxE = KxE | K*E(i,1);
        x = x + KxE;
        P = (P - (K*(phi*P)))/lambda;
    }

}
