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


