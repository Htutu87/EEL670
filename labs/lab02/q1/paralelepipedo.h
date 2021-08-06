// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#include <iostream>

using namespace std;

class Paralelepipedo {

    public:
        Paralelepipedo(double, double, double);
        void setAltura(double);
        void setLargura(double);
        void setProfundidade(double);
        double getVolume();

    private:
        double computeVolume();
        double altura;
        double largura;
        double profundidade;
};