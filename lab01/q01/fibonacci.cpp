// EEL660 - Laboratório 0x - questão 0x
// Artur Amaral - xx/2021
// Implementação da função
//

int CalcularTermoSerieFibonacci(unsigned indiceDoTermo){
    
    int valorDoTermo = 1;
    int valorAnterior = 0;
    int auxiliar;
    unsigned indice;


    if (indiceDoTermo <= 2)
        return indiceDoTermo-1;    

    for (indice = 1; indice <= indiceDoTermo; indice++){

        auxiliar = valorDoTermo;
        valorDoTermo += valorAnterior;
        valorAnterior = auxiliar;    
    }

    return valorAnterior;
}
