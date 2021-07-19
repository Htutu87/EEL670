// EEL 660 - Laboratório 01 - questão 02
// Artur Amaral - Jul/2021
//

#include <iostream>
#include "fibonacci.h"

using namespace std;

int main(){

    unsigned indiceDoTermo;
    unsigned valorDoTermo;
    Fibonacci FibonacciObject;

    cout << "Insira o indice do termo para obter seu valor na série de Fibonacci: ";
    cin >> indiceDoTermo;

    FibonacciObject.setFibonacci(indiceDoTermo);
    valorDoTermo = FibonacciObject.getFibonacci();


    cout << "O termo da seria de Fibonacci de indice " << indiceDoTermo << " eh "
        << valorDoTermo << "." <<endl;

    return 0;
}
