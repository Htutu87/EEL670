// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#include "paralelepipedo.h"

Paralelepipedo::Paralelepipedo(double altura, double largura, double profundidade){

    setAltura(altura);
    setLargura(largura);
    setProfundidade(profundidade);
}

void Paralelepipedo::setAltura(double a){

    if (a <= 0){
        altura = 1;
        cout << "Altura inserida invalida. Definindo altura como 1." << endl;
    } else {
        altura = a;
    }
}

void Paralelepipedo::setLargura(double l){

    if (l <= 0){
            largura = 1;
            cout << "Largura inserida invalida. Definindo largura como 1." << endl;
        } else {
            largura = l;
        }
}

void Paralelepipedo::setProfundidade(double p){

    if (p <= 0){
            profundidade = 1;
            cout << "Profundidade inserida invalida. Definindo profundidade como 1." << endl;
        } else {
            profundidade = p;
        }
}

double Paralelepipedo::getVolume(){
    return Paralelepipedo::computeVolume();
}

double Paralelepipedo::computeVolume(){
    return altura*largura*profundidade;
}
