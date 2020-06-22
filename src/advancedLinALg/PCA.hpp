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

    //std::cout << this->dataMean;
    for(unsigned i = 0; i< data.getNumberOfRows(); ++i)
        adjustedData = adjustedData || data.getRow(i) - this->dataMean(i,0);

    //std::cout << (~adjustedData);
    LinAlg::Matrix<Type> matrixcov = ((adjustedData*(~adjustedData))/(adjustedData.getNumberOfColumns()-1));
    //std::cout << (matrixcov);
    LinAlg::Matrix<Type> eigenvalues  = LinAlg::eigenValues(matrixcov);
    LinAlg::Matrix<Type> eigenvectors = -LinAlg::eigenVectors(matrixcov);
   // std::cout << (eigenvalues) << std::endl << eigenvectors;

    //*(this->eigenvalueOrder, eigenvectors) = sort(eigenvectors);
    //this->eigenvalueOrder = LinAlg::sortColumnVectorIndices(-eigenvalues);
    //eigenvectors = eigenvectors(from(0)-->eigenvectors.getNumberOfRows()-1, this->eigenvalueOrder);
    //std::cout << (eigenvalues) << std::endl << eigenvectors;
    this->projectioMatrix = eigenvectors(from(0)-->eigenvectors.getNumberOfRows()-1, LinAlg::LineVector<Type>(0,reducedDimensionQuantities-1));
    //std::cout << this->projectioMatrix;
    LinAlg::Matrix<Type> Y = (~this->projectioMatrix) * adjustedData;

    //std::cout << (~Y);
    //this->eigenvalueOrder = LinAlg::sortColumnVectorIndices(this->eigenvalueOrder);
    this->eigenvalueOrder = LinAlg::LineVector<Type>(0,eigenvectors.getNumberOfRows()-1);
    //*(this->eigenvalueOrder, eigenvectors) = sort(eigenvectors);
    LinAlg::Matrix<Type> originalData;
    for (unsigned i = 0; i < data.getNumberOfRows(); ++i)
        originalData = originalData || this->projectioMatrix.getRow(i) * Y + this->dataMean(i,0);

    this->originalData = originalData;
    //std::cout << std::endl << (~this->originalData) << std::endl;
}

