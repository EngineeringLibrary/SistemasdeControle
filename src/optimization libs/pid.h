#ifndef __PID_H_INCLUDED
#define __PID_H_INCLUDED

#include <cmath>

//! Classe PID.

/*!
    Classe PID criada com o objetivo de simular um controle PID.
*/

template <typename UsedType>
class PID
{
private:

    bool checkUpLim; //! Membro que define se o PID chegou ao limite superior.
    bool checkLowLim; //! Membro que define se o PID chegou ao limite inferior.

    UsedType Step; //! Membro onde é armazenado a variação do tempo, o passo da função.
    UsedType Error; //! Membro onde é armazenado o erro a medida que o PID é executado.
    UsedType pastError; //! Membro onde é armazenado o erro anterior para comparações.
    UsedType integralError; //! Membro onde é armazenado o erro da integral numérica.
    UsedType derivativeError; //! Membro onde é armazenado o erro da derivada numérica.

    UsedType kp; //! Membro onde é armazenado o parâmetro KP do PID.
    UsedType ki; //! Membro onde é armazenado o parâmetro KI do PID.
    UsedType kd; //! Membro onde é armazenado o parâmetro KD do PID.

    UsedType upperLimit; //! Membro onde é definido o limite superior do PID.
    UsedType lowerLimit; //! Membro onde é definido o limite superior do PID.

    UsedType PIDout; //! Membro onde é armazenada a saída do PID.

    //! Método privado antReset().

    /*!
        Verifica se o controle PID chegou a um dos limites definidos.
    */
    void antReset();

    //!  Método privado intError().

    /*!
        Calcula o erro integral usado no PID.
    */
    void intError();

    //! Método privado difError().

    /*!
        Calcula o erro da derivada usada no PID.
    */
    void difError();

public:
    //! Construtor padrão da classe.

    /*!
        Inicia todos os membros em 0 para evitar o uso indevido de lixo da memória.
    */
    PID();

    //! Método o qual define o passo

    /*!
       Toma como parâmetros o tempo de amostragem e armazena em Step.
       \param Time Variação de tempo do sistema.
    */
    void setSampleTime(UsedType Time);

    //! Método o qual define os limites.

    /*!
        Toma como parâmetros o limite superior e o limite inferior no qual a faixa do PID deve trabalhar.
        \param upperLimit é o limite superior do sistema a ser definido.
        \param lowerLimit é o limite inferior do sistema a ser definido.
    */
    void setLimits(UsedType upperLimit, UsedType lowerLimit);

    //! Método o qual define os parâmetros kp, ki, e kd respectivamente do sistema a ser controlado.

    /*!
        Recebe os parâmetros kp, ki e kd do sistema.
        \param kp é o ganho proporcional, este ganho resultada em grandes mudança na saída
                  dado um determinado erro. Altos valores pode tornar o sistema instável.
        \param ki é o ganho integral, ele é proporcional ao erro e a duração do mesmo.
                  O ganho integral acelera a saí do sistema até o setpoint.
        \param kd é o ganho derivado, este ganho prevê o comportamento do sistema, sendo assim,
                  ele melhora a estabilidade do sistema.
    */
    void setParams(UsedType kp, UsedType ki, UsedType kd);

    //! Método o qual cá a saída do PID.

    /*!
        Recebe a referência e o sinal de entrada, para então calcular o erro e gerar
        o sinal de saída do PID.
        \param Reference é o setpoint do sistema, ou seja, o valor que o PID irá guiar o sistema.
        \param SignalInput é o sinal de entrada do sistema.
    */
    UsedType OutputControl(UsedType Reference, UsedType SignalInput);
};

#endif // PID_H
