// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#include "covidData.h"

Estadual::Estadual(string _nome){

    nome = _nome;

    for (int i=0; i < comprimentoSerie; i++)
        serieHistorica[i] = i*i;
}

void Estadual::getSerieHistorica(unsigned * _bufferSerie){

    for (int indice = 0; indice < comprimentoSerie; indice++)
        _bufferSerie[indice] = serieHistorica[indice];
    
}

double Estadual::calculaMediaMovel(unsigned intervaloEmDias){

    double mediaMovel = 0;

    if (intervaloEmDias > 7){
        cout << "O limite maximo de calculo da media movel eh de 7 dias." << endl;
        cout<< "Calculando para esse valor." << endl;
        intervaloEmDias = 7;
    }

    for (int i = 0; i < intervaloEmDias; i++){
        mediaMovel += serieHistorica[comprimentoSerie-1 -i];
        //cout << serieHistorica[comprimentoSerie-1-i] << endl;
    }
    
    mediaMovel /= intervaloEmDias;

    return mediaMovel;

    // Acesso > N+1
    // Maior N = 7
    
}

string Estadual::getName(){
    return nome;
}


Nacional::Nacional(){

    estados[AC] = Estadual AC("Acre");
    estados[AL] = Estadual AL("Alagoas");
    estados[AM] = Estadual AM("Amazonas");
    estados[BA] = Estadual BA("Bahia");
    estados[CE] = Estadual CE("Ceara");
    estados[ES] = Estadual ES("Espirito Santo");
    estados[GO] = Estadual GO("Goias");
    estados[MA] = Estadual MA("Maranhao");
    estados[MT] = Estadual MT("Mato Grosso");
    estados[MS] = Estadual MS("Mato Grosso do Sul");
    estados[MG] = Estadual MG("Minas Gerais");
    estados[PA] = Estadual PA("Para");
    estados[PB] = Estadual PB("Paraiba");
    estados[PR] = Estadual PR("Parana");
    estados[PE] = Estadual PE("Pernambuco");
    estados[PI] = Estadual PI("Piaui");
    estados[RJ] = Estadual RJ("Rio de Janeiro");
    estados[RS] = Estadual RS("Rio Grande do Sul");
    estados[RO] = Estadual RO("Rondonia");
    estados[RR] = Estadual RR("Roraima");
    estados[SC] = Estadual SC("Santa Catarina");
    estados[SP] = Estadual SP("Sao Paulo");
    estados[SE] = Estadual SE("Sergipe");    
    estados[TO] = Estadual TO("Tocantins");
    estados[DF] = Estadual DF("Brasilia");

};