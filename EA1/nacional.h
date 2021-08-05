// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#ifndef NACIONAL_H
#define NACIONAL_H

#include "dependencias.h"
#include "estadual.h"

class Nacional{

    public:
        Nacional();  // Vai inicializar os objetos dos estados.
        void computarSerieHistoricaNacional(); // Soma os dados de todos os estados em cada dia, atribuindo ao array de serieHistorica nacional.
        double calcularMediaMovel(uint intervaloEmDias = 3, bool diaAnterior = false); 
        int calcularTendencia();   
        uint calcularObitosAcumulados();
        void getSerieHistorica(array <uint, comprimentoDaSerie> &);

    //private: 
        const static uint quantidadeEstados = 26+1;
        //array <Estadual, quantidadeEstados> estados;
        Estadual estados[quantidadeEstados];

        const static uint comprimentoDaSerie = 8;
        array <uint,comprimentoDaSerie> serieHistoricaNacional;

};

#endif