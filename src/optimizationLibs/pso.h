#ifndef __PSO_H_INCLUDED
#define __PSO_H_INCLUDED

#include "..\simulationLibs\lsim.h"

//! Classe de otimização por nuvem de partículas

/*!
    Essa classe (PSO) faz parte de um conjunto de classes de otimização. A sua responsabilidade é receber um problema que deve ser otimizado e devolver os parâmetros que minimizam ou maximizam a função objetivo do problema.
    \param MinMax Variável booleana que representa se é para maximizar ou minimizar a função objetivo. Quando essa variável é setada em (1) true o PSO funcionará como um maximizador da função objetivo, caso o parâmetro seja setado em 0 (false) o PSO funcionará como um minimizador da função objetivo. Por default a função inicializa com false.
    \param varNum Variável inteira que representa o número de parâmetros que o PSO terá de encontrar durante o processo de otimização.
    \param PopSize Variável inteira que representa o número de indivíduos que estarão buscando por uma solução otimizada para o problema.
    \param GenSize Variável inteira que representa quantas iterações serão realizadas no algoritmo. OBS: Lembrando que o algoritmo realizará PopSize * GenSize vezes a função objetivo, por isso, esse é um processo de otimização relativamente demorado.
    \param phi1 Variável Real que representa o componente cognitivo do PSO.
    \param phi2 Variável Real que representa o componente social do PSO.
    \param omega Variável Real que representa o coeficiente de inercia do PSO.
    \param V é uma matriz contendo a velocidade calculada de cada partícula em relação a sua melhor posição e em relação a melhor posição de todas as partículas do PSO.
    \param X é uma matriz contendo a posição de cada partícula do PSO.
    \param P é uma matriz contendo a melhor posição em que cada partícula do PSO já esteve.
    \param G é uma matriz contendo a melhor posição em que a melhor partícula do PSO já esteve.
    \param Xfitness é uma matriz contendo as avaliações de cada partícula (indicando se a partícula está em uma boa posição ou não).
    \param Pfitness é uma matriz contendo as melhores avaliações de cada partícula (indicando a melhor avaliação já obtida pela partícula).
    \param Gfitness é uma matriz contendo a avaliação da melhor partícula em todo o processo de otimização.
*/

template <class UsedType>
class PSO
{
private:
    Matrix<UsedType> V, X, P, G, GGen, GnTimes, Xfitness, Pfitness, Gfitness, GfitnessGen, GfitnessnTime, RunTime;
    Lsim<UsedType> Model;

    //! Recebe uma matriz e devolve uma matriz simbolizando a avaliação das partículas inseridas.

    /*!
        A responsabilidade desta função é permitir que o PSO disponibilize um número de referência que possa ser minimizado ou minimizado.
        \param Matrix2Evaluate É uma matriz de coeficientes que serão inseridos na função objetivo para obter o resultado da avaliação.

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    Matrix<UsedType> Evaluation(Matrix<UsedType> Matrix2Evaluate);

    //! Atualiza as partículas X.

    /*!
        A responsabilidade desta função é calcular X = X + V, função de atualização das partículas do PSO.

        Obs: Os parâmetros de atualização deste método são internos, ou seja, pertencem à classe.

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */


    void ParticleUpdate();

    //! Avalia as partículas X.

    /*!
        A responsabilidade desta função é chamar o método Evaluation() avaliando, assim, as partículas X.

        Obs: Os parâmetros de atualização deste método são internos, ou seja, pertencem à classe.

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    void ParticleEvaluation();

    //! Atualiza as velocidades (V) das partículas (X).

    /*!
        A responsabilidade desta função é calcular V = wV + phi1*r1(P-X) + phi2*r2(G-X), função de atualização das velocidades das partículas do PSO.

        Obs: Os parâmetros de atualização deste método são internos, ou seja, pertencem à classe.

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    void VelocityUpdate();

    //! Inicializa os parâmetros do PSO.

    /*!
        Inicializa os parâmetros do PSO para que ele possa começar a realizar as iterações.

        Obs: Os parâmetros de atualização deste método são internos, ou seja, pertencem à classe.

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    void initAlgorithm();

    //! Realiza a verificação da existencia de melhores partículas locais e globais

    /*!
        Realiza a verificação da existencia de melhores partículas locais e globais e atualiza as variáveis preparando o algoritmo para uma nova iteração (geração).

        Obs: Os parâmetros de atualização deste método são internos, ou seja, pertencem à classe.

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */


    void FitnessUpdate();

    //! Realiza a verificação da existencia de melhores partículas locais e globais para uma função que deve ser minimizada

    /*!
        Realiza a verificação da existencia de melhores partículas locais e globais e atualiza as variáveis preparando o algoritmo para uma nova iteração (geração).

        Obs: Os parâmetros de atualização deste método são internos, ou seja, pertencem à classe.

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    void FitnessUpdateMin();

    //! Realiza a verificação da existencia de melhores partículas locais e globais para uma função que deve ser maximizada

    /*!
        Realiza a verificação da existencia de melhores partículas locais e globais e atualiza as variáveis preparando o algoritmo para uma nova iteração (geração).

        Obs: Os parâmetros de atualização deste método são internos, ou seja, pertencem à classe.

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    void FitnessUpdateMax();

public:

    //! Construtor padrão da biblioteca

    /*!
        Inicializa o PSO com os seguintes parâmetros iniciais para o objeto instanciado.
        \param varNum = 1;
        \param PopSize = 80;
        \param GenSize = 2000;
        \param phi1 = 1;
        \param phi2 = 1;
        \param omega = 1;
        \param MinMax = false;

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    PSO();

    //! Sobrecarga do construtor do PSO

    /*!
        Inicializa o PSO com os seguintes parâmetros iniciais para o objeto instanciado.
        \param this->varNum = varNum; // 1º parâmetro de entrada do construtor
        \param this->PopSize = PopSize; //2º parâmetro de entrada do construtor
        \param this->GenSize = GenSize; //3º parâmetro de entrada do construtor
        \param phi1 = 1;
        \param phi2 = 1;
        \param omega = 1;
        \param MinMax = false;

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    PSO(int varNum, int PopSize, int GenSize);

    //! Sobrecarga do construtor do PSO

    /*!
        Inicializa o PSO com os seguintes parâmetros iniciais para o objeto instanciado.
        \param this->varNum = varNum; // 1º parâmetro de entrada do construtor
        \param this->PopSize = PopSize; //2º parâmetro de entrada do construtor
        \param this->GenSize = GenSize; //3º parâmetro de entrada do construtor
        \param this->phi1 = phi1; //4º parâmetro de entrada do construtor
        \param this->phi2 = phi2; //5º parâmetro de entrada do construtor
        \param omega = 1;
        \param MinMax = false;

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    PSO(int varNum, int PopSize, int GenSize, double phi1, double phi2);

    //! Sobrecarga do construtor do PSO

    /*!
        Inicializa o PSO com os seguintes parâmetros iniciais para o objeto instanciado.
        \param this->varNum = varNum; // 1º parâmetro de entrada do construtor
        \param this->PopSize = PopSize; //2º parâmetro de entrada do construtor
        \param this->GenSize = GenSize; //3º parâmetro de entrada do construtor
        \param this->phi1 = phi1; //4º parâmetro de entrada do construtor
        \param this->phi2 = phi2; //5º parâmetro de entrada do construtor
        \param this->omega = omega; //6º parâmetro de entrada do construtor
        \param this->MinMax = MinMax; //7º parâmetro de entrada do construtor

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    PSO(int varNum, int PopSize, int GenSize, double phi1, double phi2, double omega, bool MinMax);

    //! Destrutor padrão do PSO

    /*!
        Método que é executado no momento em que o PSO é deletado.

        OBS: O método não tem exempo associado.

        Ver também: \sa void Run()
    */


    ~PSO();

    //! Função que inicializa a otimização do problema

    /*!
        Neste método são executadas todas as partes necessárias para realizar GenSize iterações do PSO (GenSize gerações);

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */

    void Run();

    //! Função que inicializa a otimização do problema

    /*!
        Neste método são executadas todas as partes necessárias para realizar GenSize iterações do PSO (GenSize gerações) nTime vezes;
        \param nTimes Quantidade de vezes que o PSO é executado GenSize vezes

        Ex:

\code
        #include <src/primitiveLibs/pso.h>
        int main(int argc, char *argv)
        {

        }
\endcode

        Resultado:

        Ver também: \sa void Run()
    */


    void Run(int nTimes);
    void setData(Matrix<UsedType> dataIn, Matrix<UsedType> dataOut);

    double getTime();
};

#endif // PSO_H
