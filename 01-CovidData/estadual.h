// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

// Definição da classe Estadual -> Representa os estados brasileiros, encapsulando
// informações e procedimentos relevantes ao manuseio de seus dados de covid-19.

#ifndef ESTADUAL_H
#define ESTADUAL_H

#include "dependencias.h"

#define CRESCENTE 1
#define ESTAVEL 0
#define DECRESCENTE -1

class Estadual {

    private:
        // Atributos gerais
        string  nome;
        double  mediaMovel;
        int     tendencia;
        double     razaoTendencia;
        uint    obitosAcumulados;

        // Array - Série histórica de óbitos por covid.
        const static uint               comprimentoDaSerie = 8;
        array <uint,comprimentoDaSerie> serieHistorica;

        // Métodos que computam dados a partir da série histórica.
        double  calcularMediaMovel(uint intervaloEmDias = 3, bool diaAnterior = false); 
        int     calcularTendencia();                                                                   
        uint    calcularObitosAcumulados();

    public:
        // Construtor
        Estadual() = default;                                               // É necessária a existencia de um construtor padrão para a classe Nacional funcionar.
        Estadual(string /*nomeDoEstado*/, int /*tendenciaDaSerie*/);        // Inicializa os atributos do objeto.

        // Métodos get -> Retornam os atributos do objeto.
        void    getSerieHistorica(array <uint, comprimentoDaSerie> &);
        string  getNome();
        double  getMediaMovel(bool diaAnterior = false);
        int     getTendencia();
        double  getRazaoTendencia();
        uint    getObitosAcumulados();

};

#endif