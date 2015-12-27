#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include "SistemasdeControle/headers/modelLibs/model.h"
#include "SistemasdeControle/headers/modelLibs/arx.h"
#include "SistemasdeControle/headers/primitiveLibs/polynom.h"

namespace ModelHandler {
    template <typename Type>
    class TransferFunction : public Model<Type>
    {
    public:
        TransferFunction(ARX<Type> gz); // não feito
        TransferFunction(unsigned rows, unsigned cols); // ok
        TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF); // OK
        TransferFunction(): var('s'), isContinuous(1), sampleTime(0.1), timeSimulation(10) {} // ok
//        virtual ~TransferFunction(); // ok

        unsigned getNumberOfRows() const; // OK
        unsigned getNumberOfColumns() const; // OK

//        void setSampleTime(double sampleTime);
//        void setIsContinuous(bool isContinuous);
//        void setTimeSimulation(double timeSimulation);
//        void setTransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF);
        void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output); // não feito
        void setLinearModel (LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output); // não feito

        void c2d(Type sampleTime); // não feito

        PolynomHandler::Polynom<Type>& operator()(unsigned row, unsigned column); // ok
        PolynomHandler::Polynom<Type>  operator()(unsigned row, unsigned column) const; // ok

//        void operator= (TransferFunction<Type> rhs);
        TransferFunction<Type>& operator= (const TransferFunction<Type>& otherTransferFunction); //ok
        template<typename OtherTransferFunctionType> // não funciona
        TransferFunction<Type>& operator= (const TransferFunction<OtherTransferFunctionType>& otherTransferFunction);


        Type sim(Type input);
        Type sim(Type x, Type y);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y);
        LinAlg::Matrix<Type> sim(Type lsim, Type lmax, Type step);

        std::string print();

    private:
//        void initTfNumber();
        void c2dConversion();

        char var;
        bool isContinuous;
        double sampleTime, timeSimulation;
        LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF;
    };

    template<typename Type> // ok
    std::ostream& operator<< (std::ostream& output, ModelHandler::TransferFunction<Type> TF);
    template<typename Type> //ok
    std::string&  operator<< (std::string& output,  ModelHandler::TransferFunction<Type> TF);

}

#include "SistemasdeControle/src/modelLibs/transferfunction.hpp"
#endif // TRANSFERFUNCTION_H
