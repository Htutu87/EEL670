// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 02
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/vertice.h"

Vertice::Vertice(string _nome){
    setNome(_nome);
}

Vertice::Vertice(){
    setNome("Default");
}

string Vertice::getNome(){
    return nome;
}

void Vertice::setNome(string _nome){
    nome = _nome;
}
