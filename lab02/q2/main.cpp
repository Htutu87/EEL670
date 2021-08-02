// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#include "geometria.h"

int main (){
    
    Ponto p1(4.0, -20.5, 1.0);
    Ponto p2(4.0, 5.5, 3.0);

    Linha l(p1, p2);

    PrintCoordenadas(p1);
    PrintCoordenadas(p2);
    
    cout << "Comprimento da reta: " << fixed << setprecision(3) << l.getComprimento() << endl;

    return 0;
}