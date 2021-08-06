// EEL 660 - Laboratório 01 - questão 01
// Artur Amaral - Jul/2021
//

#include <iostream>
#include "fibonacci.h"

using namespace std;

int main(){

    int indiceDoTermo;

    cout << "Insira o indice do termo para obter seu valor na série de Fibonacci: ";
    cin >> indiceDoTermo;

    indiceDoTermo = CalcularTermoSerieFibonacci(indiceDoTermo);
   
    cout << "O termo da seria de Fibonacci de indice " << indiceDoTermo << " eh "
        << indiceDoTermo << "." <<endl;

    return 0;
}
