// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#include <string>
#include <array>
#include <iostream>
#include <iomanip>

using namespace std;

// #define QUANTIDADE_DIAS_SERIE_HISTORICA 7

class Estadual{

    public:
        Estadual(string);
        void getSerieHistorica(unsigned *); // Recebe o ponteiro para a posição inicial da serie e seu tamanho.
        double calculaMediaMovel(unsigned); // Calcula a média móvel dos últimos N dias.
        string getName();

    private:
        string nome;
        const static unsigned comprimentoSerie = 7;
        array <Estadual, comprimentoSerie> serieHistorica;
};

class Nacional{

     public:
         Nacional();

    private:
        const static unsigned numeroEstadosBrasileiros = 26+1;
        Estadual estados[numeroEstadosBrasileiros];
        enum estados {AC, AL, AP, AM, BA, CE, ES, GO, MA, MT, MS,
         MG, PA, PB, PR, PE, PI, RJ, RS, RO, RR, SC, SP, SE, TO, DF};

        Estadual AC(string);
        Estadual AL("Alagoas");
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
