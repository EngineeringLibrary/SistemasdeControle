#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include "SistemasdeControle/headers/modelLibs/model.h"
#include "SistemasdeControle/headers/modelLibs/statespace.h"

namespace ModelHandler {
    template <typename Type>
    class TransferFunction : public Model<Type>
    {
    public:
        TransferFunction(unsigned rows, unsigned cols); // ok
        TransferFunction(const PolynomHandler::Polynom<Type> &TFSISO); // OK
        TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF); // OK
        TransferFunction(): var('s'), Continuous(1), sampleTime(0.1), timeSimulation(10) {} // ok
        TransferFunction(const LinAlg::Matrix<Type> &numPol, const LinAlg::Matrix<Type> &denPol); // OK

        TransferFunction(unsigned rows, unsigned cols, double sampleTime); // ok
        TransferFunction(const PolynomHandler::Polynom<Type> &TFSISO, double sampleTime); // OK
        TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF, double sampleTime); // OK
        TransferFunction(const LinAlg::Matrix<Type> &numPol, const LinAlg::Matrix<Type> &denPol, double sampleTime); // OK
//        virtual ~TransferFunction(); // ok

        bool isContinuous() const;
        double getSampleTime() const;
        unsigned getNumberOfRows() const; // OK
        unsigned getNumberOfColumns() const; // OK
        unsigned getNumberOfVariables(){}
        unsigned getNumberOfInputs() const { return TF.getNumberOfRows();}
        unsigned getNumberOfOutputs() const { return TF.getNumberOfColumns();}

        void setContinuous(const bool &continuous); //ok
        void setSampleTime(const double &sampleTime);//ok
//        void setIsContinuous(bool isContinuous);
//        void setTimeSimulation(double timeSimulation);
//        void setTransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF);
        void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output); // não feito
        void setLinearModel (LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output); // não feito


        PolynomHandler::Polynom<Type>& operator()(unsigned row, unsigned column); // ok
        PolynomHandler::Polynom<Type>  operator()(unsigned row, unsigned column) const; // ok

        void operator= (const PolynomHandler::Polynom<Type> &rhs);
        TransferFunction<Type>& operator= (const TransferFunction<Type>& otherTransferFunction); //ok
        template<typename OtherTransferFunctionType> // não funciona
        TransferFunction<Type>& operator= (const TransferFunction<OtherTransferFunctionType>& otherTransferFunction);

        TransferFunction<Type> operator+= (const Type& rhs /*scalar*/){ return TransferFunction<Type>(this->TF += rhs);} //testada
        template<typename RightType> //testada
        TransferFunction<Type> operator+= (const TransferFunction<RightType>& rhs){return TransferFunction<Type>(this->TF += rhs.TF);}

        TransferFunction<Type> operator-= (const Type& rhs /*scalar*/){return TransferFunction<Type>(this->TF -= rhs);} // testada
        template<typename RightType>
        TransferFunction<Type> operator-= (const TransferFunction<RightType>& rhs){return TransferFunction<Type>(this->TF -= rhs.TF);}

        TransferFunction<Type> operator*= (const Type& rhs /*scalar*/){return TransferFunction<Type>(this->TF *= rhs);} // testada
        template<typename RightType>
        TransferFunction<Type> operator*= (const TransferFunction<RightType>& rhs){return TransferFunction<Type>(this->TF *= rhs.TF);}

        TransferFunction<Type> operator/= (const Type& rhs /*scalar*/){ //Definidos apenas para o caso monovariavel
            if(this->TF.getNumberOfColumns() == 1 && this->TF.getNumberOfRows() == 1)
                return TransferFunction<Type>(this->TF(1,1) /= rhs);
        }
        template<typename RightType>
        TransferFunction<Type> operator/= (const TransferFunction<RightType>& rhs){ //Definidos apenas para o caso monovariavel
            if(this->TF.getNumberOfColumns() == 1 && this->TF.getNumberOfRows() == 1)
                return TransferFunction<Type>(this->TF(1,1) /= rhs.TF(1,1));
        }


        Type sim(Type input);
        Type sim(Type x, Type y);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y);
        LinAlg::Matrix<Type> sim(Type lsim, Type lmax, Type step);

        std::string ContinuosFirstOrderCaracteristics();
        std::string ContinuosSecondOrderCaracteristics();

        std::string print();

    private:
//        void initTfNumber();
        void c2dConversion(); // Passou a fazer parte de Conversions

        char var;
        bool Continuous;
        double sampleTime, timeSimulation;
        LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF;
        LinAlg::Matrix<Type> state;
    };

    template<typename PolynomType, typename ScalarType>
    TransferFunction<PolynomType> operator+ (TransferFunction<PolynomType> lhs, const ScalarType& rhs) {return lhs += rhs;}
    template<typename PolynomType, typename ScalarType>
    TransferFunction<PolynomType> operator+ (const ScalarType& lhs, TransferFunction<PolynomType> rhs) {return rhs += lhs;}
    template<typename LeftType, typename RightType>
    TransferFunction<LeftType> operator+ (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs += rhs;}

    template<typename PolynomType, typename ScalarType>
    TransferFunction<PolynomType> operator- (TransferFunction<PolynomType> lhs, const ScalarType& rhs) {return lhs -= rhs;}
    template<typename PolynomType, typename ScalarType>
    TransferFunction<PolynomType> operator- (const ScalarType& lhs, TransferFunction<PolynomType> rhs) {return -1*(rhs -= lhs);}
    template<typename LeftType, typename RightType>
    TransferFunction<LeftType> operator- (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs -= rhs;}

    template<typename PolynomType, typename ScalarType>
    TransferFunction<PolynomType>  operator* (TransferFunction<PolynomType>  lhs, const ScalarType& rhs) {return lhs *= rhs;}
    template<typename PolynomType, typename ScalarType>
    TransferFunction<PolynomType>  operator* (const ScalarType& lhs, TransferFunction<PolynomType>  rhs) {return rhs *= lhs;}
    template<typename LeftType, typename RightType>
    TransferFunction<LeftType> operator* (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs *= rhs;}

    template<typename PolynomType, typename ScalarType>
    TransferFunction<PolynomType> operator/ (TransferFunction<PolynomType> lhs, const ScalarType& rhs) {return lhs /= rhs;}
    template<typename PolynomType, typename ScalarType>
    TransferFunction<PolynomType> operator/ (ScalarType rhs, TransferFunction<PolynomType> lhs) {return TransferFunction<PolynomType>(rhs) /= lhs;}
    template<typename LeftType, typename RightType>
    TransferFunction<LeftType> operator/ (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs /= rhs;}

    template<typename Type> // ok
    std::ostream& operator<< (std::ostream& output, ModelHandler::TransferFunction<Type> TF);
    template<typename Type> //ok
    std::string&  operator<< (std::string& output,  ModelHandler::TransferFunction<Type> TF);


}

#include "SistemasdeControle/src/modelLibs/transferfunction.hpp"
#endif // TRANSFERFUNCTION_H
