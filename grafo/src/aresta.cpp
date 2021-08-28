// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 02
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/aresta.h"

Aresta::Aresta(Vertice _verticeOrigem ,Vertice _verticeDestino, double _custo) :
    verticeOrigem(_verticeOrigem), verticeDestino(_verticeDestino) // Lista de inicialização
{
    verticeOrigem = _verticeOrigem;
    verticeDestino = _verticeDestino;
    custo = _custo;

    visual = getVerticeOrigem().getNome() + "--" + to_string(getCusto()).substr(0,3) + "-->" + getVerticeDestino().getNome();

}

Vertice Aresta::getVerticeOrigem(){
    return verticeOrigem;
}

Vertice Aresta::getVerticeDestino(){
    return verticeDestino;
}

double Aresta::getCusto(){
    return custo;
}

void Aresta::exibirNaTela(){
    cout << visual << endl;
}
