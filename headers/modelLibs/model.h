#ifndef MODEL_H
#define MODEL_H
#include <cfloat>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace ModelHandler {
    template <typename Type>
    class Model
    {
    public:
        Model(ModelHandler::Model<Type>* InheritedModel);
        Model(): InheritedModel{NULL}, input{0}, output{0}, step{1}{}
        virtual ~Model();

        Type diff(Type x);
        void setStep(Type step);
        void setModelCoef(LinAlg::Matrix<Type> coef);
        void setIO(LinAlg::Matrix<Type> in, LinAlg::Matrix<Type> out);

        Type getOutput();
        LinAlg::Matrix<Type> getModelCoef();
        LinAlg::Matrix<Type> getInputMatrix();
        LinAlg::Matrix<Type> getOutputMatrix();
        LinAlg::Matrix<Type> getLinearVectorA();
        LinAlg::Matrix<Type> getLinearMatrixA();
        LinAlg::Matrix<Type> getLinearEqualityB();
        LinAlg::Matrix<Type> getLinearEqualityVectorB();

        void operator= (ModelHandler::Model<Type>* InheritedModel); // implementar

        virtual Type         sim(Type x) = 0;
        virtual Type         sim(Type x, Type y) = 0;
        virtual LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x) = 0;
        virtual LinAlg::Matrix<Type> sim(Type lsim, Type lmax, Type step) = 0;
        virtual LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y) = 0;

        virtual std::ostream& print()=0;
        virtual void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output) = 0;
        virtual void setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)=0;

    protected:
//        virtual bool isFunction() = 0;

        Model<Type> *InheritedModel;
        Type                 input,    output,      lmin,lmax,            step;
        LinAlg::Matrix<Type> Input,    Output,      EstOutput,       ModelCoef,
                         LinearVectorA,   LinearEqualityVectorB, LinearMatrixA,
                         LinearEqualityB, InputLinearVector, OutputLinearVector;

    };

    template<typename Type> // implementar
    std::ostream& operator<< (std::ostream& output, const ModelHandler::Model<Type> *model);
    template<typename Type> // implementar
    std::string&  operator<< (std::string& output,  const ModelHandler::Model<Type> *model);

    template<typename Type> // implementar
    void sim(const ModelHandler::Model<Type> *model, Type x);
    template<typename Type> // implementar
    void sim(const ModelHandler::Model<Type> *model, Type x, Type y);
    template<typename Type> // implementar
    void sim(const ModelHandler::Model<Type> *model, LinAlg::Matrix<Type> X);
    template<typename Type> // implementar
    void sim(const ModelHandler::Model<Type> *model, Type lsim, Type lmax, Type step);
    template<typename Type> // implementar
    void sim(const ModelHandler::Model<Type> *model, LinAlg::Matrix<Type> X, LinAlg::Matrix<Type> Y);

}

#include "SistemasdeControle/src/modelLibs/model.hpp"
#endif // MODEL_H
