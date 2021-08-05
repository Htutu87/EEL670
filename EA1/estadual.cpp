// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#include "estadual.h"

Estadual::Estadual(string _nome, int _tendencia){

    nome = _nome;

    switch(_tendencia){
        case CRESCENTE:
            // Inicializa a serie historica do estado como um array arbitrário de numeros crescentes.
            serieHistorica = {20,24,30,40,50,65,79,100};
            break;
        case DECRESCENTE:
            // Inicializa a serie historica do estado como um array arbitrário de numeros decrescentes.
            serieHistorica = {130, 110, 121, 106, 95, 90, 63, 55};
            break;
        case ESTAVEL:
            // Inicializa a serie historica do estado como um array arbitrário de numeros estaveis.
            serieHistorica = {88, 89, 95, 103, 94, 97, 90, 96};
            break;    
    }

    mediaMovel = calcularMediaMovel(7,false);
    tendencia = calcularTendencia();
    obitosAcumulados = calcularObitosAcumulados();

}

string Estadual::getNome(){
    return nome;
}

double Estadual::getMediaMovel(bool diaAnterior){
    mediaMovel = calcularMediaMovel(comprimentoDaSerie-1, diaAnterior);
    return mediaMovel;
}
int Estadual::getTendencia(){
    return tendencia;
}
uint Estadual::getObitosAcumulados(){
    return obitosAcumulados;
}

void Estadual::getSerieHistorica (array <uint, comprimentoDaSerie> &_buffer) {
    _buffer = serieHistorica;
}

double Estadual::calcularMediaMovel(uint intervaloEmDias, bool diaAnterior){

    double mediaMovel = 0;

    if (intervaloEmDias > 7){
        cout << "O limite maximo de calculo da media movel eh de 7 dias." << endl;
        cout<< "Calculando para esse valor." << endl;
        intervaloEmDias = 7;
    }

    for (int i = 0; i < intervaloEmDias; i++){
        mediaMovel += serieHistorica[comprimentoDaSerie-1-diaAnterior-i];
        //cout << serieHistorica[comprimentoSerie-1-i] << endl;
    }
    
    mediaMovel /= intervaloEmDias;

    return mediaMovel;

}

int Estadual::calcularTendencia(){

    double razao = getMediaMovel(false)/getMediaMovel(true);
    
    if (razao > 1.1)
        return 1;
    if (razao < 0.9)
        return -1;
    else
        return 0;
}

uint Estadual::calcularObitosAcumulados(){

    uint obitosAcumulados = 0;

    for (int contador = 0; contador < comprimentoDaSerie; contador++)
        obitosAcumulados += serieHistorica[contador];

    return obitosAcumulados;
}

