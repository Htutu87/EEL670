// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#include "covidData.h"

Estadual::Estadual(string _nome, int _tendencia){

    nome = _nome;

    switch(_tendencia){
        case CRESCENTE:
            // Inicializa a serie historica do estado como um array arbitrário de numeros crescentes.
            serieHistorica = {20,24,30,40,50,65,79,100};
            break;
        case DECRESCENTE:
            // Inicializa a serie historica do estado como um array arbitrário de numeros decrescentes.
            serieHistorica = {100, 110, 121, 106, 95, 90, 89, 85};
            break;
        case ESTAVEL:
            // Inicializa a serie historica do estado como um array arbitrário de numeros estaveis.
            serieHistorica = {88, 89, 95, 103, 94, 97, 90, 96};
            break;    
    }

}

string Estadual::getNome(){
    return nome;
}

void Estadual::getSerieHistorica (array <uint, comprimentoDaSerie> &_buffer) {
    _buffer = serieHistorica;
}

double Estadual::calcularMediaMovel(uint intervaloEmDias){

    double mediaMovel = 0;

    if (intervaloEmDias > 7){
        cout << "O limite maximo de calculo da media movel eh de 7 dias." << endl;
        cout<< "Calculando para esse valor." << endl;
        intervaloEmDias = 7;
    }

    for (int i = 0; i < intervaloEmDias; i++){
        mediaMovel += serieHistorica[comprimentoDaSerie-1 -i];
        //cout << serieHistorica[comprimentoSerie-1-i] << endl;
    }
    
    mediaMovel /= intervaloEmDias;

    return mediaMovel;

} 