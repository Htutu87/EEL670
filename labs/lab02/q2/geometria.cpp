// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#include "geometria.h"

Ponto::Ponto(double _x, double _y, double _z){

    setX(_x);
    setY(_y);
    setZ(_z);
}

void Ponto::setX(double _x){
    x = _x;
}

void Ponto::setY(double _y){
    y = _y;
}

void Ponto::setZ(double _z){
    z = _z;
}

double Ponto::getX(){
    return x;
}

double Ponto::getY(){
    return y;
}

double Ponto::getZ(){
    return z;
}

Linha::Linha(Ponto _p1, Ponto _p2){
    setPontos(_p1, _p2);
}

void Linha::setPontos(Ponto _p1, Ponto _p2){
    p1 = _p1;
    p2 = _p2;
}

double Linha::getComprimento(){

    double dX = p2.getX() - p1.getX();
    double dY = p2.getY() - p1.getY();
    double dZ = p2.getZ() - p1.getZ();

    return sqrt( pow(dX,2) + pow(dY,2) + pow(dZ,2) );
}

void PrintCoordenadas(Ponto _p){

    static int nImpressoes = 1;

    cout << "[Impressao no. " << nImpressoes << "] : Coordenadas de p (" <<
    _p.getX() << ", " <<
    _p.getY() << ", " <<
    _p.getZ() << ")" << endl;

    nImpressoes++;
}