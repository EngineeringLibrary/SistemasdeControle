//#include "SistemasdeControle/headers/advancedLinALg/PCA.h"
#ifdef testPolynom
    #include "../../../headers/advancedLinALg/PCA.h"
#else
    #include "SistemasdeControle/headers/advancedLinALg/PCA.h"
#endif

template <typename Type>
LinAlg::PCA<Type>::PCA(LinAlg::Matrix<Type> data, const unsigned &reducedDimensionQuantities)
{
    this->data = data;
    this->dataMean = LinAlg::mean(data,2);
    LinAlg::Matrix<Type> adjustedData;

    for(unsigned i = 0; i< data.getNumberOfRows(); ++i)
        adjustedData = adjustedData || data.getRow(i) - this->dataMean(i,0);

    LinAlg::Matrix<Type> matrixcov = ((adjustedData*(~adjustedData))/(adjustedData.getNumberOfColumns()-1));
    LinAlg::Matrix<Type> eigenvalues  = LinAlg::eigenValues(matrixcov);
    LinAlg::Matrix<Type> eigenvectors = -LinAlg::eigenVectors(matrixcov);

    this->projectioMatrix = eigenvectors(from(0)-->eigenvectors.getNumberOfRows()-1, LinAlg::LineVector<Type>(0,reducedDimensionQuantities-1));
    LinAlg::Matrix<Type> Y = (~this->projectioMatrix) * adjustedData;
    this->eigenvalueOrder = LinAlg::LineVector<Type>(0,eigenvectors.getNumberOfRows()-1);

    LinAlg::Matrix<Type> originalData;
    for (unsigned i = 0; i < data.getNumberOfRows(); ++i)
        originalData = originalData || this->projectioMatrix.getRow(i) * Y + this->dataMean(i,0);
    this->originalData = originalData;
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::PCAf::subspaceSimulation(LinAlg::Matrix<Type> dataIn, LinAlg::Matrix<Type> a, LinAlg::Matrix<Type> M)
{
    LinAlg::Matrix<Type> R, ret;
    for (unsigned i = 0; i < dataIn.getNumberOfRows(); ++i)
        R = (R || (dataIn.getRow(i) - a(i,0)));

    //Projeção
    LinAlg::Matrix<Type> Y1 = (~M)*R;
    //LinAlg::Matrix<Type> DadoFinal = M * Y1;

    //PCA na reconstrução
    //for (unsigned i = 0; i < DadoFinal.getNumberOfRows(); ++i)
    //    ret = DadoFinal.getRow(i) + a(i,0);

    for (unsigned i = 0; i < dataIn.getNumberOfRows(); ++i)
        ret = ret || M.getRow(i) * Y1 + a(i,0);
    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::PCAf::grid(uint32_t dimension, Type lowerLimit, Type upperLimit, Type step)
{
    LinAlg::Matrix<Type> referenceState = LinAlg::LineVector<Type>(lowerLimit, upperLimit, step);
    uint32_t sizeState = referenceState.getNumberOfColumns(), totalDimension = pow(sizeState,dimension);
    LinAlg::Matrix<Type> ret(dimension,totalDimension);

    for(uint32_t i = 0; i < dimension; ++i)
    {
        double size = pow(sizeState,i);
        for(uint32_t k = 0; k < totalDimension; ++k)
            ret(i,k) = referenceState(0,(uint32_t(k/size))%sizeState);
    }

    return ret;
}

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
LinAlg::Matrix<double> LinAlg::PCAf::linSolve(LinAlg::Matrix<double> obj, LinAlg::Matrix<double> A, LinAlg::Matrix<double> b, LinAlg::Matrix<double> Aeq, LinAlg::Matrix<double> beq)
{
    GRBEnv* env=0;
    GRBVar* x=0;

    try{
        //iniciando ambiente e modelo
        env = new GRBEnv();
        GRBModel model(*env);

        //Declarando variavel
        x=model.addVars(A.getNumberOfRows(),GRB_INTEGER);
        model.update();

        for (int i=0;i<A.getNumberOfRows();i++){
            std::stringstream ss;
            ss << 'x' << i;
            x[i].set(GRB_DoubleAttr_Obj,obj(0,i));
            x[i].set(GRB_StringAttr_VarName, ss.str());
        }

        //minimizando função
        model.set(GRB_IntAttr_ModelSense, 1); //"1" para minimizar e "2" para maximizar
        model.update();

        //Restrição 1: A.x<=b
        for(int i=0; i<A.getNumberOfRows();i++){

             GRBLinExpr f0=0;

            for(int j=0; j<A.getNumberOfColumns();j++){
               f0+=A(i,j)*x[j];
            model.addConstr(f0 <= b(i,0),"f0");

            }
        }

        //Restrição 2: Aeq.x=beq
        for(int i=0; i<Aeq.getNumberOfRows();i++){

             GRBLinExpr f1=0;

            for(int j=0; j<A.getNumberOfColumns();j++){
               f1+=Aeq(i,j)*x[j];
            model.addConstr(f1 == beq(i,0),"f1");

            }
        }
        //Resolução do modelo
        model.update();
        model.write("model.lp");
        model.optimize();

    //    std::cout << x[0].get(GRB.StringAttr_VarName) <<" "<< x[0].get(GRB.DoubleAttr_X) << std::endl;

    //    std::cout << x[1].get(GRB.StringAttr_VarName) <<" "<< x[1].get(GRB.DoubleAttr_X) << std::endl;

    //    std::cout << x[2].get(GRB.StringAttr_VarName) <<" "<< x[2].get(GRB.DoubleAttr_X) << std::endl;

    //    std::cout << "Obj:"<< model.get(GRB.DoubleAttr_ObjVal) << std::endl;

    //    model.dispose();
    //    env->dispose();

    }catch (GRBException e) {
        std::cout<<"Error code: "<< e.getErrorCode()<<"."<<e.getMessage()<<endl;

        }
    delete[] x;
    delete env;

       /* GRBVar *X = new GRBVar[A.getNumberOfRows()];

        for(uint8_t i = 0; i < x.getNumberOfRows(); ++i)
        {
            std::stringstream ss; ss << 'x' << i;
            GRBVar X[i] = model.addVar(0.0, GRB.INFINITY, 0.0, GRB.CONTINUOUS, ss.str().c_str());
        }

        GRBLinExpr expr = new GRBLinExpr();
        for(uint8_t i = 0; i < x.getNumberOfRows(); ++i)
        {
              expr.addTerm(1.0, z);
              model.setObjective(expr, GRB.MINIMIZE);
        }*/
}
