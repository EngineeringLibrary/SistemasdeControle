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

    UsedType Step; //! Membro onde &ecute armazenado a variação do tempo, o passo da fun&ccedil&aatildee.
    UsedType Error; //! Membro onde &ecute armazenado o erro a medida que o PID &eecute executado.
    UsedType pastError; //! Membro onde &ecute armazenado o erro anterior para compara&ccedil&otildees.
    UsedType integralError; //! Membro onde &ecute armazenado o erro da integral num&ecuterica.
    UsedType derivativeError; //! Membro onde &ecute armazenado o erro da derivada num&ecuterica.

    UsedType kp; //! Membro onde &ecute armazenado o param&ecircto KP do PID.
    UsedType ki; //! Membro onde &ecute armazenado o param&ecircto KI do PID.
    UsedType kd; //! Membro onde &ecute armazenado o param&ecircto KD do PID.

    UsedType upperLimit; //! Membro onde &ecute definido o limite superior do PID.
    UsedType lowerLimit; //! Membro onde &ecute definido o limite superior do PID.

    UsedType PIDout; //! Membro onde &ecute armazenada a sa&icute do PID.

    //! M&ecutetodo privado antReset().

    /*!
        Verifica se o controle PID chegou a um dos limites definidos.
    */
    void antReset();

    //!  M&ecutetodo privado intError().

    /*!
        C&acutelcula o erro integral usado no PID.
    */
    void intError();

    //! M&etodo privado difError().

    /*!
        C&acutelcula o erro da derivada usada no PID.
    */
    void difError();

public:
    //! Construtor padr&atildeo da classe.

    /*!
        Inicia todos os membros em 0 para evitar o uso indevido de lixo da mem&ocuteria.
    */
    PID();

    //! M&ecutetodo o qual define o passo

    /*!
       Toma como param&ecircto o tempo de amostrogram e armazena em Step.
       \param Time Varia&ccedil&atildeo de tempo do sistema.
    */
    void setSampleTime(UsedType Time);

    //! M&ecutetodo o qual define os limites.

    /*!
        Toma como param&ecirctos o limite superior e o limite inferior no qual a faixa do PID deve trabalhar.
        \param upperLimit &Ecute o limite superior do sistema a ser definido.
        \param lowerLimit &Ecute o limite inferior do sistema a ser definido.
    */
    void setLimits(UsedType upperLimit, UsedType lowerLimit);

    //! M&ecute o qual define os param&ecirctos kp, ki, e kd respectivamente do sistema a ser controlado.

    /*!
        Recebe os param&ecirctos kp, ki e kd do sistema.
        \param kp &Ecute o ganho proporcional, este ganho resultada em grandes mudan&ccedila na sa&icuteda
                  dado um determinado erro. Altos valores pode tornar o sistema inst&acutevel.
        \param ki &Ecute o ganho integral, ele &ecute proporcional ao erro e a dura&ccedil&acute do mesmo.
                  O ganho integral acelera a sa&icute do sistema at&ecute o setpoint.
        \param kd &Ecute o ganho derivado, este ganho prev&ecirc o comportamento do sistema, sendo assim,
                  ele melhora a estabilidade do sistema.
    */
    void setParams(UsedType kp, UsedType ki, UsedType kd);

    //! M&ecutetodo o qual c&acute a sa&icuteda do PID.

    /*!
        Recebe a refer&ecircncia e o sinal de entrada, para ent&atildeo calcular o erro e gerar
        o sinal de sa&icuteda do PID.
        \param Reference &Ecute o setpoint do sistema, ou seja, o valor que o PID ir&acute guiar o sistema.
        \param SignalInput &Ecute o sinal de entrada do sistema.
    */
    UsedType OutputControl(UsedType Reference, UsedType SignalInput);
};

#endif // PID_H
