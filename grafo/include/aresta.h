// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 02
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "vertice.h"

class Aresta{

    public:
        Aresta(Vertice, Vertice, double);
        Vertice getVerticeOrigem();
        Vertice getVerticeDestino();
        double getCusto();
        void exibirNaTela();

    private:
        Vertice verticeOrigem;
        Vertice verticeDestino;
        double custo;

};
