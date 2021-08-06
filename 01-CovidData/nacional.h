// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#ifndef NACIONAL_H
#define NACIONAL_H

#include "estadual.h"

class Nacional{

    private:
        // Arrays - Representam a série histórica do país e armazenam os objetos dos 27 estados, instanciandos na construção dessa classe.
        const static uint   quantidadeEstados = 26+1;
        Estadual            estados[quantidadeEstados]; 
        // OBS: Foi muito mais simples implementar a lista de estados (acima) como array convencional. O array da STL apresentou várias complicações para armazenar objetos da classe Estadual. Por essa razão este array destoa dos demais.

        const static uint               comprimentoDaSerie = 8;
        array <uint,comprimentoDaSerie> serieHistoricaNacional;        

        // Atributos gerais.
        string  nome;
        double  mediaMovel;
        int     tendencia;
        uint    obitosAcumulados;
        enum    indiceEstados{AC, AL, AP, AM, BA, CE, ES, GO, MA,
                                MT, MS, MG, PA, PB, PR, PE, PI, RJ,
                                RN, RS, RO, RR, SC, SP, SE, TO, DF};
    
    public:
        // Construtor 
        Nacional();  

        // Métodos que computam dados a partir da série histórica.
        void    computarSerieHistoricaNacional();
        double  calcularMediaMovel(uint intervaloEmDias = 3, bool diaAnterior = false); 
        int     calcularTendencia();   
        uint    calcularObitosAcumulados();

        // Métodos get.
        uint    getEstadoComMaiorAlta();
        uint    getEstadoComMenorBaixa();
        void    getSerieHistoricaNacional(array <uint, comprimentoDaSerie> &);
        void    getListaDeEstados(Estadual [], uint);
        double  getMediaMovel(bool diaAnterior = false);
        int     getTendencia();
        uint    getObitosAcumulados();
        uint    getQuantidadeEstados();
        uint    getComprimentoDaSerie();



};

#endif