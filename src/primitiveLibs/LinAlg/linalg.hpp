#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"

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
Type LinAlg::CaracteristicPolynom (const LinAlg::Matrix<Type>& mat)
{

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
    LinAlg::QR_Factorization(input_matrix, output_Q_matrix, output_R_matrix);
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
LinAlg::Matrix<Type> LinAlg::EigenValues(const LinAlg::Matrix<Type> &matrix_to_get_eigenvalues, unsigned iterations = 100)
{
    LinAlg::Matrix<Type> ret(matrix_to_get_eigenvalues), temp = LinAlg::Eye<Type>(ret.getNumberOfRows());

    LinAlg::Balance(ret);
    ret = LinAlg::Hess(ret);

    for(unsigned i = 0; i < iterations; i++)
    {
        LinAlg::Matrix<Type> Q, R;

        LinAlg::QR(ret, Q, R);

        ret = R*Q;
    }

    return ret;
}
