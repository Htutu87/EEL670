// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#include "covidData.h"

int main () {

    Estadual RJ("Rio de Janeiro", -1);
    Estadual SP("Sao Paulo", 0);
    Estadual MG("Minas Gerais", 1);

    array <uint, 8> buffer;


    cout << "Serie historica por estado:\n" << endl;

    cout << RJ.getNome() << ": " << endl;
    RJ.getSerieHistorica(buffer); 
    for(auto dia:buffer)
         cout << dia << setw(4);
     cout << endl; 
    cout << setw(4) << fixed << setprecision(0) << "Media movel: " << RJ.calcularMediaMovel(7) << endl << endl;

    cout << SP.getNome() << ": " << endl;
    SP.getSerieHistorica(buffer);
    for(auto dia:buffer)
         cout << dia << setw(4);
     cout << endl <<endl; 
    cout << setw(4) << "Media movel: " << fixed << setprecision(0)<<  SP.calcularMediaMovel(7) << endl << endl;

    cout << MG.getNome() << ": " << endl;
    MG.getSerieHistorica(buffer);
    for(auto dia:buffer)
         cout << dia << setw(4);
     cout << endl <<endl; 
    cout << setw(4) << "Media movel: " << fixed << setprecision(0) << MG.calcularMediaMovel(7) <<  endl << endl;

    return 0;
}