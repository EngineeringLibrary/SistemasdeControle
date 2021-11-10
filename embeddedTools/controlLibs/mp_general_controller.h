#ifndef MPGENERALCONTROLLER_H_INCLUDED
#define MPGENERALCONTROLLER_H_INCLUDED

#include "SistemasdeControle/embeddedTools/primitiveLibs/LinAlg/matrix.h"
#include <vector>

namespace ControlHandler{
	template <typename Type>
    class MP_General_Controller
    {
    public:
    	MP_General_Controller(){}
		void insertRegion(uint16_t index, std::string set, std::string pwa_function);
    	// std::string setRestrictions(std::string restrictions); // Recebe uma string com R no final de cada conjunto de restrições. Converte cada trecho do início até encontrar o R em uma matriz e deleta o trecho da string.
        // std::string setControllerParameters(std::string controllers);// Recebe uma string com C no final de cada conjunto parâmetros do controlador afim por partes. Converte cada trecho do início até encontrar o C em uma matriz e deleta o trecho da string.
    	virtual Type OutputControl(Type Reference, Type SignalInput) = 0; // Obriga as classes filhas a implementar essa função.

    protected://significa que todas as classes filhas podem acessar os atributos abaixo.
    	std::map< uint16_t, LinAlg::Matrix<Type> > constraints; // Vetor de Matrizes contendo todas as restrições para cada conjunto.
    	std::map< uint16_t, LinAlg::Matrix<Type> > controllerParameters; // Vetor de Matrizes contendo todos os parâmetros de controlador para cada conjunto.
    	uint16_t quantityOfRegions; // Quantidade de regiões em que o conjunto foi subdividido.
    	int inWitchRegion; // Sinalisa em qual região pertence o estado calculado.

    	bool isInside(const LinAlg::Matrix<Type> &_point);// Verifica se um estado pertence ao conjunto invariante.
        bool any(const LinAlg::Matrix<Type> &H);// função para auxiliar isInside.
	};
}

#include "mp_general_controller.hpp"
#endif