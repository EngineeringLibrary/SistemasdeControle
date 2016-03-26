#ifndef STATESPACE_H
#define STATESPACE_H
#include "SistemasdeControle/headers/modelLibs/model.h"

namespace ModelHandler {
    template <typename Type>
    class StateSpace : public Model<Type>
    {
    public:
        StateSpace(){}
        StateSpace(LinAlg::Matrix<Type> A , LinAlg::Matrix<Type> B,
                   LinAlg::Matrix<Type> C , LinAlg::Matrix<Type> D); //ok
        StateSpace(LinAlg::Matrix<Type> Ad, LinAlg::Matrix<Type> Bd,
                   LinAlg::Matrix<Type> C , LinAlg::Matrix<Type> D,
                   Type SampleTime); //ok

        double getSampleTime() const; // ok
        LinAlg::Matrix<Type> getA() const; //ok
        LinAlg::Matrix<Type> getB() const; //ok
        LinAlg::Matrix<Type> getC() const; //ok
        LinAlg::Matrix<Type> getD() const; //ok
        LinAlg::Matrix<Type> getActualState() const; //ok

        unsigned getNumberOfVariables() {}
        unsigned getNumberOfInputs() const {}
        unsigned getNumberOfOutputs() const {}

        void setA(LinAlg::Matrix<Type> A); //ok
        void setB(LinAlg::Matrix<Type> B); //ok
        void setC(LinAlg::Matrix<Type> C); //ok
        void setD(LinAlg::Matrix<Type> D); //ok
        void setContinuous(bool Continuous); //ok
        void setSampleTime(double SampleTime); //ok
        void setInitialState(LinAlg::Matrix<Type> X0); //ok
        void setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);
        void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);
        void SetObserverParameter(LinAlg::Matrix<Type> L);//ok

        bool isContinuous()  const;
        bool isObservable()  const;
        bool isControlable() const;

        Type sim(Type u); //ok
        Type sim(Type u, Type y); // não é usado
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> u); //ok
        LinAlg::Matrix<Type> sim(Type lmin, Type lmax, Type step); //ok
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> u, LinAlg::Matrix<Type> y); // não é usado

        void c2dConversion(); //ok
        void d2cConversion();
        std::string print(); //ok

    private:
        Type factorial(unsigned n); // ok

        LinAlg::Matrix<Type> Observer(LinAlg::Matrix<Type> U, LinAlg::Matrix<Type> Y);

        bool Continuous;
        unsigned nDiscretization;
        Type SampleTime, TimeSimulation;
        LinAlg::Matrix<Type> A, B, C, D, Ad, Bd, X, L, initialState;
    };

    template<typename Type> // ok
    std::ostream& operator<< (std::ostream& output, ModelHandler::StateSpace<Type> SS);
    template<typename Type> //ok
    std::string&  operator<< (std::string& output,  ModelHandler::StateSpace<Type> SS);

    template<typename Type> // ok
    Type sim(ModelHandler::StateSpace<Type> &SS, Type u);
    template<typename Type> // ok
    LinAlg::Matrix<Type> sim(ModelHandler::StateSpace<Type> &SS, LinAlg::Matrix<Type> u);
    template<typename Type> //ok
    LinAlg::Matrix<Type> sim(ModelHandler::StateSpace<Type> &SS, Type lmin, Type lmax, Type step);

    template<typename Type> //ok
    ModelHandler::StateSpace<Type> c2d(const ModelHandler::StateSpace<Type> &SS, Type SampleTime);
    template<typename Type> //ok
    ModelHandler::StateSpace<Type> d2c(const ModelHandler::StateSpace<Type> &discreteSS);
}

#include "SistemasdeControle/src/modelLibs/statespace.hpp"
#endif // STATESPACE_H
