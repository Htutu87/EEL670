// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#ifndef COVID_DATA_H
#define COVID_DATA_H

#include <string>
#include <array>
#include <iostream>
#include <iomanip>

#define CRESCENTE 1
#define ESTAVEL 0
#define DECRESCENTE -1

using namespace std;

class Estadual {

    private:
        string nome;
        const static uint comprimentoDaSerie = 8;
        array <uint,comprimentoDaSerie> serieHistorica;
        double mediaMovel;

    public:
        Estadual(string /*nomeDoEstado*/, int /*tendenciaDaSerie*/);  // Responsavel por inicializar o nome e a serie histórica do objeto. Dependendo do terceiro argumento, a serie gerada será crescente, decrescente ou estável.
        void getSerieHistorica(array <uint, comprimentoDaSerie> &);
        string getNome();                                       
        double calcularMediaMovel(uint /*intervaloDeDiasCalculado*/); 
        int obterTendencia();                                              // Vai calular a média móvel para do dia atual e penultimo dia, de modo a calcular a razao entre ambas e definir a tendencia do estado.
        uint calcularObitosAcumulados();

};


class Nacional{

    public:
        Nacional();  // Vai inicializar os objetos dos estados.
        void computarSerieHistoricaNacional(); // Soma os dados de todos os estados em cada dia, atribuindo ao array de serieHistorica nacional.
        double calcularMediaMovel(uint /*intervaloDeDiasCalculado*/);
        int obterTendendica();
        uint calcularObitosAcumulados();


    private: 
        const static uint quantidadeEstados = 26+1;
        array <Estadual, quantidadeEstados> estados;

        const static uint comprimentoDaSerie = 8;
        array <uint,comprimentoDaSerie> serieHistoricaNacional;


};

#endif