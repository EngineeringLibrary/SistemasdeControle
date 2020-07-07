#ifdef testPolynom
    #include "../../../headers/restrictedOptimization/gurobioptimization.h"
#else
    #include "SistemasdeControle/headers/restrictedOptimization/gurobioptimization.h"
#endif

template <typename Type>
LinAlg::Matrix<Type> LinAlg::PCAf::optimalSignalControlGenerator(LinAlg::Matrix<Type> A, LinAlg::Matrix<Type> B, LinAlg::Matrix<Type> C,
                                                                 LinAlg::Matrix<Type> D, LinAlg::Matrix<Type> G, LinAlg::Matrix<Type> rho,
                                                                 LinAlg::Matrix<Type> w, LinAlg::Matrix<Type> eta, LinAlg::Matrix<Type> x)
{
    // given A,C,G,rho,y, find psi(i) for i=1:g such that
    //      psi(i) = max G(i,:)*A*e
    //                x
    //	under  G*x <= rho
    //	       |C*x - y| <= eta
    LinAlg::Matrix<Type> GC = (G||C||-C), rhoEta = (rho||eta+x||eta-x), obj, psi;
    uint32_t g = G.getNumberOfRows();

    for(uint8_t i = 0; i < g; ++i)
    {
        obj = (-G(i,from(0)-->G.getNumberOfColumns()-1)*A);
        //psi = (psi||-linSolve(obj, Gc, rhoEta));
    }

    LinAlg::Matrix<Type> delta;
    for(uint8_t i = 0; i < g; ++i)
        delta = (delta||G(i,from(0)-->G.getNumberOfColumns()-1)*B*linSolve(-G(i,from(0)-->G.getNumberOfColumns()-1)*B,D,w));

    uint32_t n = A.getNumberOfRows();
   // LinAlg::Matrix<Type> v = linSolve(LinAlg::Zeros<Type>(n,0)||1.0,G|-rho ,-psi_eta-delta);
   // epsi = v(n);
    //vt = v(from(0)-->n-1,0);
}



template <typename Type>
LinAlg::Matrix<Type> OptimizationHandler::linprog(LinAlg::Matrix<Type> obj, LinAlg::Matrix<Type> A, LinAlg::Matrix<Type> b, LinAlg::Matrix<Type> Aeq, LinAlg::Matrix<Type> beq, bool maximization)
{
    GRBEnv* env=0;
    LinAlg::Matrix<GRBVar> x(A.getNumberOfColumns(),1);
    LinAlg::Matrix<Type> ret(A.getNumberOfColumns(),1);

    try{
        //iniciando ambiente e modelo
        env = new GRBEnv();
        GRBModel model(*env);

        //Declarando variavel
        for(uint32_t j=0; j < x.getNumberOfRows(); ++j) {
            x(j,0) = model.addVar(0.0, GRB_INFINITY, 0.0, GRB_CONTINUOUS);
        }

        model.update();

        for(uint32_t i = 0; i < A.getNumberOfRows(); ++i) {
            GRBLinExpr LHS=0;
            for(uint32_t j = 0; j < A.getNumberOfColumns(); j++) {
                LHS += A(i,j)*x(j,0);
            }
            model.addConstr(LHS,GRB_LESS_EQUAL,b(i,0));
        }

        for(uint32_t i = 0; i < Aeq.getNumberOfRows(); ++i) {
            GRBLinExpr LHS=0;
            for(uint32_t j = 0; j < Aeq.getNumberOfColumns(); j++) {
                LHS += Aeq(i,j)*x(j,0);
            }
            model.addConstr(LHS,GRB_EQUAL,beq(i,0));
        }

        if(maximization)
            model.set(GRB_IntAttr_ModelSense, -1);
        else
            model.set(GRB_IntAttr_ModelSense, 1);

        GRBLinExpr Obj = 0;
        for(uint32_t j = 0; j < x.getNumberOfRows(); ++j)
            Obj += obj(0,j)*x(j,0);
        model.setObjective(Obj);
        model.set("OutputFlag", "0");
        model.optimize();

        for(uint32_t i = 0; i < x.getNumberOfRows(); i++) {
            //std::cout<<"x "<< i <<" =" << x(i,0).get(GRB_DoubleAttr_X) << std::endl;
            ret(i,0) = x(i,0).get(GRB_DoubleAttr_X);
        }

    }catch (GRBException e) {
        std::cout<<"Error code: "<< e.getErrorCode()<<"."<<e.getMessage()<<std::endl;

        }

    delete env;
    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> OptimizationHandler::linprog(LinAlg::Matrix<Type> obj, LinAlg::Matrix<Type> A, LinAlg::Matrix<Type> b, bool maximization)
{
    GRBEnv* env=0;
    LinAlg::Matrix<GRBVar> x(A.getNumberOfColumns(),1);
    LinAlg::Matrix<Type> ret(A.getNumberOfColumns(),1);

    try{
        //iniciando ambiente e modelo
        env = new GRBEnv();
        GRBModel model(*env);

        //Declarando variavel
        for(uint32_t j=0; j < x.getNumberOfRows(); ++j) {
            x(j,0) = model.addVar(0.0, GRB_INFINITY, 0.0, GRB_CONTINUOUS);
        }

        model.update();

        for(uint32_t i = 0; i < A.getNumberOfRows(); ++i) {
            GRBLinExpr LHS=0;
            for(uint32_t j = 0; j < A.getNumberOfColumns(); j++) {
                LHS += A(i,j)*x(j,0);
            }
            model.addConstr(LHS,GRB_LESS_EQUAL,b(i,0));
        }

        if(maximization)
            model.set(GRB_IntAttr_ModelSense, -1);
        else
            model.set(GRB_IntAttr_ModelSense, 1);

        GRBLinExpr Obj = 0;
        for(uint32_t j = 0; j < x.getNumberOfRows(); ++j)
            Obj += obj(0,j)*x(j,0);
        model.setObjective(Obj);
        model.set("OutputFlag", "0");
        model.optimize();

        for(uint32_t i = 0; i < x.getNumberOfRows(); i++) {
            //std::cout<<"x "<< i <<" =" << x(i,0).get(GRB_DoubleAttr_X) << std::endl;
            ret(i,0) = x(i,0).get(GRB_DoubleAttr_X);
        }

    }catch (GRBException e) {
        std::cout<<"Error code: "<< e.getErrorCode()<<"."<<e.getMessage()<<std::endl;

        }

    delete env;
    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> OptimizationHandler::linprog(LinAlg::Matrix<Type> obj, LinAlg::Matrix<Type> A, LinAlg::Matrix<Type> b, LinAlg::Matrix<Type> Aeq, LinAlg::Matrix<Type> beq, LinAlg::Matrix<Type> Anineq, LinAlg::Matrix<Type> bnineq, bool maximization)
{
    GRBEnv* env=0;
    LinAlg::Matrix<GRBVar> x(A.getNumberOfColumns(),1);
    LinAlg::Matrix<Type> ret(A.getNumberOfColumns(),1);

    try{
        //iniciando ambiente e modelo
        env = new GRBEnv();
        GRBModel model(*env);

        //Declarando variavel
        for(uint32_t j=0; j < x.getNumberOfRows(); ++j) {
            x(j,0) = model.addVar(0.0, GRB_INFINITY, 0.0, GRB_CONTINUOUS);
        }

        model.update();

        for(uint32_t i = 0; i < A.getNumberOfRows(); ++i) {
            GRBLinExpr LHS=0;
            for(uint32_t j = 0; j < A.getNumberOfColumns(); j++) {
                LHS += A(i,j)*x(j,0);
            }
            model.addConstr(LHS,GRB_LESS_EQUAL,b(i,0));
        }

        for(uint32_t i = 0; i < Aeq.getNumberOfRows(); ++i) {
            GRBLinExpr LHS=0;
            for(uint32_t j = 0; j < Aeq.getNumberOfColumns(); j++) {
                LHS += Aeq(i,j)*x(j,0);
            }
            model.addConstr(LHS,GRB_EQUAL,beq(i,0));
        }

        for(uint32_t i = 0; i < Anineq.getNumberOfRows(); ++i) {
            GRBLinExpr LHS=0;
            for(uint32_t j = 0; j < Anineq.getNumberOfColumns(); j++) {
                LHS += Anineq(i,j)*x(j,0);
            }
            model.addConstr(LHS,GRB_EQUAL,bnineq(i,0));
        }

        if(maximization)
            model.set(GRB_IntAttr_ModelSense, -1);
        else
            model.set(GRB_IntAttr_ModelSense, 1);

        GRBLinExpr Obj = 0;
        for(uint32_t j = 0; j < x.getNumberOfRows(); ++j)
            Obj += obj(0,j)*x(j,0);
        model.setObjective(Obj);
        model.set("OutputFlag", "0");
        model.optimize();

        for(uint32_t i = 0; i < x.getNumberOfRows(); i++) {
            //std::cout<<"x "<< i <<" =" << x(i,0).get(GRB_DoubleAttr_X) << std::endl;
            ret(i,0) = x(i,0).get(GRB_DoubleAttr_X);
        }

    }catch (GRBException e) {
        std::cout<<"Error code: "<< e.getErrorCode()<<"."<<e.getMessage()<<std::endl;

        }

    delete env;
    return ret;
}
