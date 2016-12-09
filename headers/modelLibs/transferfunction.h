#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H

#ifdef testModel
    #include "../../../headers/modelLibs/model.h"
    #include "../../../headers/modelLibs/statespace.h"
#else
    #include "SistemasdeControle/headers/modelLibs/model.h"
    #include "SistemasdeControle/headers/modelLibs/statespace.h"
#endif

namespace ModelHandler {
    template <typename Type>
    class TransferFunction : public Model<Type>
    {
    public:
        TransferFunction(unsigned rows, unsigned cols); // ok
        TransferFunction(const PolynomHandler::Polynom<Type> &TFSISO); // OK
        TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF); // OK
        TransferFunction(const LinAlg::Matrix<Type> &numPol, const LinAlg::Matrix<Type> &denPol); // OK
        TransferFunction(): var('s'), Continuous(1), TF(1,1) { this->step = 0.1; this->timeSimulation = 10;} // ok

        TransferFunction(unsigned rows, unsigned cols, double sampleTime); // ok
        TransferFunction(const PolynomHandler::Polynom<Type> &TFSISO, double sampleTime); // OK
        TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF, double sampleTime); // OK
        TransferFunction(const LinAlg::Matrix<Type> &numPol, const LinAlg::Matrix<Type> &denPol, double sampleTime); // OK

        template<typename OtherType>
        TransferFunction (const ModelHandler::TransferFunction<OtherType>& otherPolynom);
//        virtual ~TransferFunction(); // ok

        bool isContinuous() const;
        char getVar() const {return this->var;}
        double getSampleTime() const;
        double getTimeSimulation() const{return this->timeSimulation;}
        unsigned getNumberOfRows() const; // OK
        unsigned getNumberOfColumns() const; // OK
        unsigned getNumberOfVariables() const{return TF.getNumberOfRows() + TF.getNumberOfColumns();}
        unsigned getNumberOfInputs() const { return TF.getNumberOfRows();}
        unsigned getNumberOfOutputs() const { return TF.getNumberOfColumns();}

        void setContinuous(const bool &continuous); //ok
        void setSampleTime(const double &sampleTime);//ok
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

        TransferFunction<Type> operator/= (const Type& rhs /*scalar*/){ return TransferFunction<Type>(this->TF *= 1/rhs);}
        template<typename RightType>
        TransferFunction<Type> operator/= (const TransferFunction<RightType>& rhs){return TransferFunction<Type>(this->TF *= LinAlg::Inverse(rhs.TF));}


        Type sim(Type input);
        Type sim(Type x, Type y);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y);
        LinAlg::Matrix<Type> sim(Type lsim, Type lmax, Type step);

        std::string ContinuosFirstOrderCaracteristics();
        std::string ContinuosSecondOrderCaracteristics();

        std::string print();

    private:
        void c2dConversion(); // Passou a fazer parte de Conversions

        char var;
        bool Continuous;
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

#ifdef testModel
    #include "../../../src/modelLibs/transferfunction.hpp"
#else
    #include "SistemasdeControle/src/modelLibs/transferfunction.hpp"
#endif

#endif // TRANSFERFUNCTION_H
