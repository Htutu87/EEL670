// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#include "nacional.h"

class Estadual;
class Nacional;

// TIVE UM PROBLEMAO COM O FATO DA CLASSE ESTADUAL NAO TER UM CONSTRUTOR DEFAULT.

Nacional::Nacional(){

    Estadual AC("Acre",1);
    Estadual AL("Alagoas",1);
    Estadual AP("Amapa",1);
    Estadual AM("Amazonas",1);
    Estadual BA("Bahia",1);
    Estadual CE("Ceara",1);
    Estadual ES("Espirito Santo",1);
    Estadual GO("Goias",1 );
    Estadual MA("Maranhao",1);
    Estadual MT("Mato Grosso",1);
    Estadual MS("Mato Grosso do Sul",1);
    Estadual MG("Minas Gerais",-1);
    Estadual PA("Para",-1);
    Estadual PB("Paraiba",-1);
    Estadual PR("Parana",-1);
    Estadual PE("Pernambuco",-1);
    Estadual PI("Piaui",-1);
    Estadual RJ("Rio de Janeiro",-1);
    Estadual RN("Rio Grande do Norte",-1);
    Estadual RS("Rio Grande do Sul",0);
    Estadual RO("Rondonia",0);
    Estadual RR("Roraima",0);
    Estadual SC("Santa Catarina",0);
    Estadual SP("Sao Paulo",0);
    Estadual SE("Sergipe",0);    
    Estadual TO("Tocantins",0);
    Estadual DF("Brasilia",0);

    estados[0] = AC;
    estados[1] = AL;
    estados[2] = AP;
    estados[3] = AM;
    estados[4] = BA;
    estados[5] = CE;
    estados[6] = ES;
    estados[7] = GO;
    estados[8] = MA;
    estados[9] = MT;
    estados[10] = MS;
    estados[11] = MG;
    estados[12] = PA;
    estados[13] = PB;
    estados[14] = PR;
    estados[15] = PE;
    estados[16] = PI;
    estados[17] = RJ;
    estados[18] = RN;
    estados[19] = RS;
    estados[20] = RO;
    estados[21] = RR;
    estados[22] = SC;
    estados[23] = SP;
    estados[24] = SE;
    estados[25] = TO;
    estados[26] = DF;
}

void Nacional::computarSerieHistoricaNacional(){

    array <uint, comprimentoDaSerie> buffer;
    uint indice;

    // Garante que os elementos da serie historica nacional sejam zero, ja que eles provirão de um somatório.
    for (indice = 0; indice < comprimentoDaSerie; indice++)
            serieHistoricaNacional[indice] += 0;

    for (auto estado: estados)
    {
        estado.getSerieHistorica(buffer);    
        for (indice = 0; indice < comprimentoDaSerie; indice++)
            serieHistoricaNacional[indice] += buffer[indice];
    }

}

double Nacional::calcularMediaMovel(uint intervaloEmDias, bool diaAnterior){

    double mediaMovel = 0;

    if (intervaloEmDias > 7){
        cout << "O limite maximo de calculo da media movel eh de 7 dias." << endl;
        cout<< "Calculando para esse valor." << endl;
        intervaloEmDias = 7;
    }

    for (int i = 0; i < intervaloEmDias; i++){
        mediaMovel += serieHistoricaNacional[comprimentoDaSerie-1-diaAnterior-i];
        //cout << serieHistorica[comprimentoSerie-1-i] << endl;
    }
    
    mediaMovel /= intervaloEmDias;

    return mediaMovel;

}

void Estadual::getSerieHistorica (array <uint, comprimentoDaSerie> &_buffer) {
    _buffer = serieHistorica;
}


