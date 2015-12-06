#include "SistemasdeControle/Test/matrixtest.h"

void MatrixTest::RunTests()
{
    TestAtribuicaoStringMatrixInt();
    TestAtribuicaoStringMatrixDouble();
}

void MatrixTest::TestAtribuicaoStringMatrixInt()
{
    double_t deltaTime;
    clock_t t;

    std::cout << "    Testando a Atribuicao de String: Matriz<int> 1X3\n";

    t = clock();
    LinAlg::Matrix<int> M1 = "1 ,2, 3";
    deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

    if(1 == M1(1,1) && 2 == M1(1,2) && 3 == M1(1,3))
        std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
    else
        std::cout << "NAO PASSOU no teste, resultou em: " << M1 << '\n';

//-----------------------------------------------------------------------------

    std::cout << "    Testando a Atribuicao de String: Matriz<int> 2X3\n";

    t = clock();
    LinAlg::Matrix<int> M2 = "1,2 ,3; 1, 2,3";
    deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

    if(1 == M2(1,1) && 2 == M2(1,2) && 3 == M2(1,3) && 1 == M2(2,1) && 2 == M2(2,2) && 3 == M2(2,3))
        std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
    else
        std::cout << "NAO PASSOU no teste, resultou em: " << M2 << '\n';

//-----------------------------------------------------------------------------

    std::cout << "    Testando a Atribuicao de String: Matriz<int> Vazia\n";
    t = clock();
    LinAlg::Matrix<int> M3 = " ";
    deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

    if(M3.getNumberOfRows() == 0, M3.getNumberOfColumns() == 0)
        std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
    else
        std::cout << "NAO PASSOU no teste, resultou em: " << M3 << '\n';

//-----------------------------------------------------------------------------

    std::cout << "    Testando a Atribuicao de String: Erro nas linhas\n";
    t = clock();
    LinAlg::Matrix<int> M4 = "1,";
    deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

    if(M4.getNumberOfRows() == 0, M4.getNumberOfColumns() == 0)
        std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
    else
        std::cout << "NAO PASSOU no teste, resultou em: " << M4 << '\n';

//-----------------------------------------------------------------------------

    std::cout << "    Testando a Atribuicao de String: Erro nas linhas\n";
    t = clock();
    LinAlg::Matrix<int> M5 = " , ";
    deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

    if(M5.getNumberOfRows() == 0, M5.getNumberOfColumns() == 0)
        std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
    else
        std::cout << "NAO PASSOU no teste, resultou em: " << M5 << '\n';

    //-----------------------------------------------------------------------------

        std::cout << "    Testando a Atribuicao de String: Erro nas Colunas\n";
        t = clock();
        LinAlg::Matrix<int> M6 = "1;";
        deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

        if(M6.getNumberOfRows() == 0, M6.getNumberOfColumns() == 0)
            std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
        else
            std::cout << "NAO PASSOU no teste, resultou em: " << M6 << '\n';

    //-----------------------------------------------------------------------------

        std::cout << "    Testando a Atribuicao de String: Erro nas linhas\n";
        t = clock();
        LinAlg::Matrix<int> M7 = ";";
        deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

        if(M7.getNumberOfRows() == 0, M7.getNumberOfColumns() == 0)
            std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
        else
            std::cout << "NAO PASSOU no teste, resultou em: " << M7 << '\n';

        //-----------------------------------------------------------------------------

            std::cout << "    Testando a Atribuicao de String: Erro com caracteres\n";
            t = clock();
            LinAlg::Matrix<int> M8 = "a";
            deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

            if(M8.getNumberOfRows() == 0, M8.getNumberOfColumns() == 0)
                std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
            else
                std::cout << "NAO PASSOU no teste, resultou em: " << M8 << '\n';
}

void MatrixTest::TestAtribuicaoStringMatrixDouble()
{
    double_t deltaTime;
    clock_t t;

    std::cout << "    Testando a Atribuicao de String: Matriz<double> 1X3\n";

    t = clock();
    LinAlg::Matrix<double> M1 = "1.5 ,2.34, 3.456";
    deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

    if(1.5 == M1(1,1) && 2.34 == M1(1,2) && 3.456 == M1(1,3))
        std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
    else
        std::cout << "NAO PASSOU no teste, resultou em: " << M1 << '\n';

//-----------------------------------------------------------------------------

    std::cout << "    Testando a Atribuicao de String: Matriz<double> 2X3\n";

    t = clock();
    LinAlg::Matrix<double> M2 = "1.5,2.34 ,3.456; 1, 0.5,5.9877";
    deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

    if(1.5 == M2(1,1) && 2.34 == M2(1,2) && 3.456 == M2(1,3) && 1 == M2(2,1) && 0.5 == M2(2,2) && 5.9877 == M2(2,3))
        std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
    else
        std::cout << "NAO PASSOU no teste, resultou em: " << M2 << '\n';

//-----------------------------------------------------------------------------

    std::cout << "    Testando a Atribuicao de String: Matriz<double> Vazia\n";
    t = clock();
    LinAlg::Matrix<double> M3 = " ";
    deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

    if(M3.getNumberOfRows() == 0, M3.getNumberOfColumns() == 0)
        std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
    else
        std::cout << "NAO PASSOU no teste, resultou em: " << M3 << '\n';

//-----------------------------------------------------------------------------

    std::cout << "    Testando a Atribuicao de String: Erro nas linhas\n";
    t = clock();
    LinAlg::Matrix<double> M4 = "1.34,";
    deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

    if(M4.getNumberOfRows() == 0, M4.getNumberOfColumns() == 0)
        std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
    else
        std::cout << "NAO PASSOU no teste, resultou em: " << M4 << '\n';

//-----------------------------------------------------------------------------

    std::cout << "    Testando a Atribuicao de String: Erro nas linhas\n";
    t = clock();
    LinAlg::Matrix<double> M5 = " , ";
    deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

    if(M5.getNumberOfRows() == 0, M5.getNumberOfColumns() == 0)
        std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
    else
        std::cout << "NAO PASSOU no teste, resultou em: " << M5 << '\n';

    //-----------------------------------------------------------------------------

        std::cout << "    Testando a Atribuicao de String: Erro nas Colunas\n";
        t = clock();
        LinAlg::Matrix<double> M6 = "1.34;";
        deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

        if(M6.getNumberOfRows() == 0, M6.getNumberOfColumns() == 0)
            std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
        else
            std::cout << "NAO PASSOU no teste, resultou em: " << M6 << '\n';

    //-----------------------------------------------------------------------------

        std::cout << "    Testando a Atribuicao de String: Erro nas linhas\n";
        t = clock();
        LinAlg::Matrix<double> M7 = ";";
        deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

        if(M7.getNumberOfRows() == 0, M7.getNumberOfColumns() == 0)
            std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
        else
            std::cout << "NAO PASSOU no teste, resultou em: " << M7 << '\n';

        //-----------------------------------------------------------------------------

            std::cout << "    Testando a Atribuicao de String: Erro com caracteres\n";
            t = clock();
            LinAlg::Matrix<double> M8 = "a";
            deltaTime = (double_t(clock()-t))/CLOCKS_PER_SEC;

            if(M8.getNumberOfRows() == 0, M8.getNumberOfColumns() == 0)
                std::cout << "PASSOU no teste em " << deltaTime*1e6 << " us \n";
            else
                std::cout << "NAO PASSOU no teste, resultou em: " << M8 << '\n';
}
