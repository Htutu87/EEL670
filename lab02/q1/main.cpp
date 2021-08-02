// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#include "paralelepipedo.h"

int main (){
    
    Paralelepipedo p(2, 2, 2);
        
    cout << "Volume calculado: " << p.getVolume() << " m2." << endl;

    return 0;
}