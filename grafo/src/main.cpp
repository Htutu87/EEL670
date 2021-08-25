// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 01 - Exercício avaliado 02
// Autor: Artur Amaral

#include "../include/aresta.h"

int main () 
{
    Vertice vertice01;
    Vertice vertice02("A");
    double custo = 1.2;

    Aresta aresta(vertice01, vertice02, custo);

    cout << aresta.getVerticeOrigem().getNome() << endl;
    cout << aresta.getVerticeDestino().getNome() << endl; 
    cout << aresta.getCusto() + << endl;

    return 0;
}
