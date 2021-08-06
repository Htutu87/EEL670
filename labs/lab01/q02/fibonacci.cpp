// EEL660 - Laboratório 01 - questão 02
// Artur Amaral - xx/2021

#include "fibonacci.h"

void Fibonacci::setFibonacci(unsigned indice){
    indiceDoTermo = indice;
    valorDoTermo = computeFibonacci(indice);
}

unsigned Fibonacci::getFibonacci(){
    return valorDoTermo;
}

unsigned Fibonacci::computeFibonacci(unsigned indiceDoTermo){
    
    int valorDoTermo = 1;
    int valorAnterior = 0;
    int auxiliar;
    unsigned indice;


    if (indiceDoTermo <= 2)
        return indiceDoTermo-1;    

    for (indice = 1; indice <= indiceDoTermo; indice++){

        auxiliar = valorDoTermo;
        valorDoTermo += valorAnterior;
        valorAnterior = auxiliar;    
    }

    return valorAnterior;
}

