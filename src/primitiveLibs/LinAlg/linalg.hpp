#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

template <typename Type>
void LinAlg::Balance (LinAlg::Matrix<Type> &matrix_to_balance)
{
    unsigned aux = 0;
    Type radix = FLT_RADIX, sqrdx = radix*radix, s, r, g, f, c;

    while(aux == 0)
    {
        aux = 1;
        for(unsigned i = 1; i <= matrix_to_balance.getNumberOfRows(); i++)
        {
            r = c = 0.0;
            for(unsigned j = 1; j <= matrix_to_balance.getNumberOfColumns(); j++)
                if( j != i)
                {
                    c += std::fabs(matrix_to_balance(j, i));
                    r += std::fabs(matrix_to_balance(i, j));
                }
            if(c && r)
            {
                g = r/radix;
                f = 1.0;
                s = c + r;
                while(c < g)
                {
                    f *= radix;
                    c *= sqrdx;
                }

                g = r*radix;
                while(c > g)
                {
                    f /= radix;
                    c /= sqrdx;
                }
                if((c + r)/f < 0.95*s)
                {
                    aux = 0;
                    g = 1.0/f;
                    for(unsigned j = 1; j <= matrix_to_balance.getNumberOfColumns(); j++)
                    {
                        matrix_to_balance(i, j) *= g;
                        matrix_to_balance(j, i) *= f;
                    }
                }
            }
        }
    }

}

template<typename Type>
Type LinAlg::Trace (const LinAlg::Matrix<Type>& mat)
{
    Type ret = 0;

    if(mat.getNumberOfRows() != mat.getNumberOfColumns())
        std::cout << "O traco so e calculado para matrizes quadradas.";
    else
    {
        for(unsigned i = 1; i <= mat.getNumberOfRows(); i++)
            for(unsigned j = 1; j <= mat.getNumberOfColumns(); j++)
                if(i == j)
                    ret += mat(i, j);
    }

    return ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::CaracteristicPolynom (const LinAlg::Matrix<Type>& mat)
{
    unsigned n = mat.getNumberOfColumns();
    Matrix<Type> z = EigenValues(mat);
    Matrix<Type> zi = EigenValues(mat);
    Matrix<Type> ret(1,n+1);
    std::complex<Type> *tempPoly = new std::complex<Type> [2];
    tempPoly[0] = 1;
    tempPoly[1] = std::complex<Type>(-z(1,1),-z(1,2));
    std::complex<Type> * tempPolyEigenvalue = new std::complex<Type>[2];

    unsigned sizeTempPoly = 2;
    tempPolyEigenvalue[0] = 1;
    for(unsigned i = 2; i <= n ; ++i)
    {
        tempPolyEigenvalue[1] = std::complex<Type>(-z(i,1),-z(i,2));//apos o templade entre (real,imaginario) atribuição
        tempPoly = LinAlg::MultPoly(tempPoly,tempPolyEigenvalue,sizeTempPoly,2);
        sizeTempPoly++;

    }
    for(unsigned i = 0; i < sizeTempPoly ; ++i)
    {
        ret(1,i+1) = tempPoly[i].real();
    }
    return ret;

}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::inv_numeric(LinAlg::Matrix<Type> mat)
{
    LinAlg::Matrix<Type> Id;

//    try
//    {
        if (mat.getNumberOfColumns() != mat.getNumberOfRows())
            std::cout << "A matriz nao e quadrada\n";
//            throw "A matriz nao e quadrada";
        else
        {
            Id = LinAlg::Eye<Type>(mat.getNumberOfRows());

            for(unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
                for(unsigned j = i+1; j <= mat.getNumberOfRows(); ++j)
                {
                    Type m = mat(j,i)/mat(i,i);
                    for(int k = 1; k <= mat.getNumberOfRows(); ++k)
                    {
                        mat(j,k) = mat(j,k)-m*mat(i,k);
                        Id(j,k) = Id(j,k)-m*Id(i,k);
                    }
                }

            for(unsigned i = mat.getNumberOfRows(); i > 1; --i)
                for(unsigned j = i - 1; j >= 1; --j)
                {
//                    std::cout << "\n\n\n" << mat(j,i) << ',' << mat(i,i)<< "\n\n\n";
                    Type m = mat(j,i)/mat(i,i);
                    for(unsigned k = 1; k <= mat.getNumberOfRows(); ++k)
                    {
                        mat(j,k) = mat(j,k)-m*mat(i,k);
                        Id(j,k) = Id(j,k)-m*Id(i,k);
                    }
                }

            for(unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
            {
                Type m = 1/mat(i,i);
                for(unsigned j = 1; j <= mat.getNumberOfRows(); ++j)
                {
                     mat(i,j) = m*mat(i,j);
                     Id(i,j) = m*Id(i,j);
                }

            }
        }
//    }

//    catch (const char* msg)
//    {
//        cerr<<msg<<endl;
//    }

    return Id;
}


template<typename Type>
void LinAlg::QR_Factorization_ModifiedGramSchmidt (LinAlg::Matrix<Type> input_matrix,
                                            LinAlg::Matrix<Type>& output_Q_matrix,
                                            LinAlg::Matrix<Type>& output_R_matrix)
{
    Type s;
    unsigned n = input_matrix.getNumberOfColumns(), m = input_matrix.getNumberOfRows();
    output_Q_matrix = LinAlg::Zeros<Type>(m,n);
    output_R_matrix = LinAlg::Zeros<Type>(m,n);
    for(unsigned k = 1; k <= n; ++k){
        s = 0;

        for(unsigned j = 1; j <= m; ++j){
            s = s + (input_matrix(j,k) * input_matrix(j,k));
        }
        output_R_matrix(k,k) = sqrt(s);

        for(unsigned j = 1; j <= m; ++j){
            output_Q_matrix(j,k) = input_matrix(j,k)/output_R_matrix(k,k);
        }

        for(unsigned i = k + 1; i <= n; ++i){
            s = 0;
            for(unsigned j = 1; j <= m; ++j){
                s += input_matrix(j,i)*output_Q_matrix(j,k);
            }
            output_R_matrix(k,i) = s;
            for(unsigned j = 1; j <= m; ++j){
                input_matrix(j,i) -= (output_R_matrix(k,i)*output_Q_matrix(j,k));
            }
        }
    }

//    std::cout << "QR\n" << output_Q_matrix << output_R_matrix;
}

template<typename Type>
void LinAlg::QR_Factorization (const LinAlg::Matrix<Type>& input_matrix,
                               LinAlg::Matrix<Type>& output_Q_matrix,
                               LinAlg::Matrix<Type>& output_R_matrix)
{

    //Constants calculated and needed for the QR algorithm.
    unsigned R_rows = input_matrix.getNumberOfRows(), R_columns = input_matrix.getNumberOfColumns();
    Type tal, gama, sigma;

    output_Q_matrix = LinAlg::Eye<Type>(R_rows);
    output_R_matrix = input_matrix;

    for(unsigned j = 1; j <= R_columns; j++)
        for(unsigned i = R_rows; i >= j + 1; i--)
        {
            if(output_R_matrix(i, j) != 0)
            {
                LinAlg::Matrix<Type> temp;

                temp = LinAlg::Eye<Type>(R_rows);

                if(std::abs(output_R_matrix(i - 1, j)) > std::abs(output_R_matrix(i, j)))
                {
                    tal = output_R_matrix(i, j)/output_R_matrix(i - 1, j);
                    gama = 1/(std::sqrt(1 + std::pow(tal, 2)));
                    sigma = tal*gama;
                }
                else
                {
                    tal = output_R_matrix(i - 1, j)/output_R_matrix(i, j);
                    sigma = 1/(std::sqrt(1 + std::pow(tal, 2)));
                    gama = sigma*tal;
                }

                temp(i, i) = gama;
                temp(i, i - 1) = sigma;
                temp(i - 1, i) = -sigma;
                temp(i - 1, i - 1) = gama;

                output_R_matrix = (~temp)*output_R_matrix;
                output_Q_matrix *= temp;
            }

        }

}
//Simplified away to call QR_Factorization.
template<typename Type>
void LinAlg::QR (const LinAlg::Matrix<Type>& input_matrix,
                 LinAlg::Matrix<Type>& output_Q_matrix,
                 LinAlg::Matrix<Type>& output_R_matrix)
{
//    LinAlg::QR_Factorization(input_matrix, output_Q_matrix, output_R_matrix);
    LinAlg::QR_Factorization_ModifiedGramSchmidt(input_matrix, output_Q_matrix, output_R_matrix);
}

template<typename Type>
void LinAlg::LU_Factorization (LinAlg::Matrix<Type> &L_input_matrix, LinAlg::Matrix<Type> &U){

    U = L_input_matrix;

    L_input_matrix = LinAlg::Eye<Type>(U.getNumberOfRows());

    for(unsigned j= 1; j < U.getNumberOfColumns(); ++j)
        for(unsigned i = j+1; i <= U.getNumberOfRows(); ++i) {
            Type m = U(i,j)/U(j,j);
            for(unsigned k = j; k <= U.getNumberOfColumns(); ++k){
              U(i,k) = U(i,k) - m*U(j,k);
            }
            L_input_matrix(i,j) = m;
        }
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::Hessemberg_Form (const LinAlg::Matrix<Type> &matrix_to_reduce)
{
    unsigned aux = 1;
    LinAlg::Matrix<Type> ret(matrix_to_reduce);

    if(ret.isSquare())
    {
        for(unsigned i = 3; i <= ret.getNumberOfRows(); i++)
        {
            Type alfa = 0, gama;
            LinAlg::Matrix<Type> omega(ret.getNumberOfRows(), 1), H;

            for(unsigned k = i - 1; k <= ret.getNumberOfRows(); k++)
                alfa += std::pow(ret(k, aux), 2);

            if(ret(i - 1, aux) < 0)
                alfa = -1*std::sqrt(alfa);
            else
                alfa = std::sqrt(alfa);

            gama = std::sqrt((std::pow(alfa, 2)/2) - 0.5*ret(i - 1, aux)*alfa);

            for(unsigned k = 1; k <= i - 2; k++)
                omega(k, 1) = 0;

            omega(i - 1, 1) = ((ret(i - 1, aux) - alfa))/(2*gama);

            for(unsigned k = i; k <= omega.getNumberOfRows(); k++)
                omega(k, 1) = ret(k, aux)/(2*gama);


            H = LinAlg::Eye<Type>(ret.getNumberOfRows()) - 2*omega*(~omega);
            ret = H*ret*H;

            aux++;
        }
    }

    return ret;
}

//Simplified away to call Hessemberg_Form
template<typename Type>
LinAlg::Matrix<Type> LinAlg::Hess (const LinAlg::Matrix<Type>& matrix_to_reduce)
{
    return LinAlg::Hessemberg_Form(matrix_to_reduce);
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::EigenValues(const LinAlg::Matrix<Type> &matrix_to_get_eigenvalues, unsigned iterations)//sincronizado
{
    LinAlg::Matrix<Type> ret = matrix_to_get_eigenvalues, temp = LinAlg::Eye<Type>(ret.getNumberOfRows());

    LinAlg::Balance(ret);
//    ret = LinAlg::Hess(ret);
    Type R,IM;
    Matrix<Type> Raizes(ret.getNumberOfColumns(),2);// EigenVector = LinAlg::Eye<Type>(matrix_to_get_eigenvalues.getNumberOfRows());
    for(unsigned i = 0; i < iterations; ++i)
    {
        LinAlg::Matrix<Type> Q, R;

//        LinAlg::QR(ret - ret(ret.getNumberOfColumns(),ret.getNumberOfColumns())*temp, Q, R);
        LinAlg::QR(ret, Q, R);
//        EigenVector *= Q;
        ret = R*Q;
//        std::cout << ret;
//        ret = R*Q + ret(ret.getNumberOfColumns(),ret.getNumberOfColumns())*temp;
    }

//    std::cout << EigenVector;
    for(unsigned i = 1; i <= ret.getNumberOfColumns(); ++i)
    {
        if(i+1 <= ret.getNumberOfColumns())
            if(ret(i+1,i) <= 1e-10 && ret(i+1,i) >= -1e-10)
            {
                Raizes(i,1) = ret(i,i); Raizes(i,2) = 0;
            }
            else
            {
                R  = (ret(i,i) + ret(i+1,i+1))/2;
                IM = ret(i+1,i)*ret(i,i+1);
                if( IM > 0)
                    IM = (sqrt(IM));
                else
                    IM = (sqrt(-IM));
                Raizes(i,1)   = R;
                Raizes(i,2)   = -IM;
                Raizes(i+1,1) = R;
                Raizes(i+1,2) = IM;
                i++;
            }
         else
        {
            Raizes(i,1) = ret(i,i); Raizes(i,2) = 0;
        }
    }

    return Raizes;
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::EigenValues_LU(const LinAlg::Matrix<Type> &matrix_to_get_eigenvalues, unsigned iterations )//sincronizado
{
    LinAlg::Matrix<Type> L,U = matrix_to_get_eigenvalues;
    LinAlg::LU_Factorization(L,U);

    for(unsigned i = 0; i <= iterations; ++i)
    {
        LinAlg::LU_Factorization(U * L,U);
    }
    return U * L;
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::EigenVector(const LinAlg::Matrix<Type> &matrix_to_get_eigenvector, unsigned iterations)
{//Por enquanto somente para matrizes simetricas, porque so encontra autovetores reais
    srand(time(NULL));
    LinAlg::Matrix<Type> W = LinAlg::Random<Type>(matrix_to_get_eigenvector.getNumberOfRows(), matrix_to_get_eigenvector.getNumberOfColumns())
                       , Q, R;
    LinAlg::QR(W,Q,R);

    for(unsigned i = 0; i < iterations; ++i)
    {
        W = matrix_to_get_eigenvector * Q;
        LinAlg::QR(W,Q,R);
    }
//    std::cout << (Q^-1)* matrix_to_get_eigenvector *Q
//              << (W^-1)* matrix_to_get_eigenvector *W;
    return Q;
}


template <class Type>
Type *LinAlg::MultPoly(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const  unsigned  &rhsSize)
{
    Type *ret;

    ret = (Type*)calloc((lhsSize+rhsSize+1),(lhsSize+rhsSize+1)*sizeof(Type*));
    for(unsigned i = 0; i < lhsSize; ++i)
        for(unsigned j = 0; j < rhsSize; ++j)
        {
            ret[i+j] = ret[i+j] +  lhs[i]*rhs[j];
        }

    return ret;
}

template <typename Type>
Type LinAlg::max(const LinAlg::Matrix<Type> &mat)
{
    Type maxValue = mat(1,1);

    for(unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
            if(maxValue < mat(i,j))
                maxValue = mat(i,j);

    return maxValue;
}

template <typename Type>
Type LinAlg::min(const LinAlg::Matrix<Type> &mat)
{
    Type minValue = mat(1,1);

    for(unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
            if(minValue > mat(i,j))
                minValue = mat(i,j);

    return minValue;
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::abs(const LinAlg::Matrix<Type> &mat)
{
    LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(mat.getNumberOfRows(), mat.getNumberOfColumns());
    for(unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
            if(mat(i,j) > 0)
                ret(i,j) = mat(i,j);
            else
                ret(i,j) = -mat(i,j);

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::sqrtMatrix(const LinAlg::Matrix<Type> &mat)
{
    LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(mat.getNumberOfRows(), mat.getNumberOfColumns());
    for(unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
                ret(i,j) = sqrt(mat(i,j));

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::powMatrix(const LinAlg::Matrix<Type> &mat, const Type &potence)
{
    LinAlg::Matrix<Type> ret = mat;
    for(unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
                ret(i,j) = pow(mat(i,j),potence);

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type>
LinAlg::mean(const LinAlg::Matrix<Type> &mat, const unsigned &rowColumn)
{
    unsigned row = 1, column = 2;
    LinAlg::Matrix<Type> ret;

    if(rowColumn == column)
    {
        unsigned length = mat.getNumberOfColumns();
        ret = Zeros<Type>(mat.getNumberOfRows(),1);

        for(unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
            for(unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
                ret(i,1) += mat(i,j)/length;
    }
    else if(rowColumn == row)
    {
        unsigned length = mat.getNumberOfRows();
        ret = Zeros<Type>(1,mat.getNumberOfColumns());

        for(unsigned i = 1; i <= mat.getNumberOfColumns(); ++i)
            for(unsigned j = 1; j <= mat.getNumberOfRows(); ++j)
                ret(1,i) += mat(i,j)/length;
    }

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type>
LinAlg::sum(const LinAlg::Matrix<Type> &mat, const unsigned &rowColumn)
{
    unsigned row = 1, column = 2;
    LinAlg::Matrix<Type> ret;

    if(rowColumn == column)
    {
        ret = Zeros<Type>(mat.getNumberOfRows(),1);

        for(unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
            for(unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
                ret(i,1) += mat(i,j);
    }
    else if(rowColumn == row)
    {
        ret = Zeros<Type>(1,mat.getNumberOfColumns());

        for(unsigned i = 1; i <= mat.getNumberOfColumns(); ++i)
            for(unsigned j = 1; j <= mat.getNumberOfRows(); ++j)
                ret(1,i) += mat(i,j);
    }

    return ret;
}
