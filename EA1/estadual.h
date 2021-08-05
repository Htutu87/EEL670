// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#ifndef ESTADUAL_H
#define ESTADUAL_H

#include "dependencias.h"

#define CRESCENTE 1
#define ESTAVEL 0
#define DECRESCENTE -1

class Estadual {

    private:
        string nome;
        double mediaMovel;
        int tendencia;
        uint obitosAcumulados;
        const static uint comprimentoDaSerie = 8;
        array <uint,comprimentoDaSerie> serieHistorica;

        double calcularMediaMovel(uint intervaloEmDias = 3, bool diaAnterior = false); 
        int calcularTendencia();                                              // Vai calular a média móvel para do dia atual e penultimo dia, de modo a calcular a razao entre ambas e definir a tendencia do estado.
        uint calcularObitosAcumulados();

    public:
        Estadual(string /*nomeDoEstado*/, int /*tendenciaDaSerie*/);  // Responsavel por inicializar o nome e a serie histórica do objeto. Dependendo do terceiro argumento, a serie gerada será crescente, decrescente ou estável.
        Estadual() = default;
        void getSerieHistorica(array <uint, comprimentoDaSerie> &);
        string getNome();
        double getMediaMovel(bool diaAnterior = false);
        int getTendencia();
        uint getObitosAcumulados();



};

#endif