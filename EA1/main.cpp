// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#include "nacional.h"

int main () {

    Estadual RJ("Rio de Janeiro", -1);
    Estadual SP("Sao Paulo", 0);
    Estadual MG("Minas Gerais", 1);
    Estadual AC("Acre", 1);

    Nacional BR;

    array <uint, 8> buffer;



    /*

    for (int i = 0; i < 27;i++) {
        cout << "--------------------------------" << endl; 
        cout << BR.estados[i].getNome() << endl;
        BR.estados[i].getSerieHistorica(buffer);
        cout << "Serie historica: ";
        for (auto dia: buffer)
            cout << dia << setw(4);
        cout << endl;
        cout << "Media movel: ";
        cout << BR.estados[i].getMediaMovel() << endl;
        cout << "Tendencia: ";
        cout << BR.estados[i].getTendencia() << endl;
        cout << "Obitos acumulados: ";
        cout << BR.estados[i].getObitosAcumulados() << endl;
        cout << "--------------------------------" << endl << endl; 
    }

    */

    return 0;
}