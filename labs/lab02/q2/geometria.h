// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#ifndef GEOMETRIA_H
#define GEOMETRIA_H

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Ponto {

    public:
        Ponto(double x = 1.0, double y = 1.0, double z = 1.0 );
        double getX();
        double getY();
        double getZ();
        void setX(double);
        void setY(double);
        void setZ(double);

    private:
        double x;
        double y;
        double z;

};

void PrintCoordenadas(Ponto);

class Linha {

    public:
        Linha(Ponto, Ponto);
        void setPontos(Ponto, Ponto);
        double getComprimento();

    private:
        Ponto p1, p2;
};

#endif