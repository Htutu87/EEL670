// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

// estadual.cpp -> Implementação dos métodos da classe Estadual.

#include "estadual.h"

// Construtor
// Inicializa o nome do estado, passado como argumendo, bem como sua série histórica.
// Por simplicidade, decidi utilizar três séries históricas arbitrárias, uma para cada tendencia (ALTA, BAIXA, ESTAVEL),
// passada pelo usuario como argumento no construtor.

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

// getMediaMovel() 
// Esse método recebe um argumento que define se a média móvel retornada será relativa ao dia de hoje ou
// ao dia anterior (utilizada para calcular a tendencia). Por padrão (sem argumento), a média móvel retornada é 
// em relação ao dia atual.

double Estadual::getMediaMovel(bool diaAnterior){
    mediaMovel = calcularMediaMovel(comprimentoDaSerie-1, diaAnterior);
    return mediaMovel;
}
int Estadual::getTendencia(){
    return tendencia;
}

double Estadual::getRazaoTendencia(){
    return razaoTendencia;
}

uint Estadual::getObitosAcumulados(){
    return obitosAcumulados;
}

void Estadual::getSerieHistorica (array <uint, comprimentoDaSerie> &_buffer) {
    _buffer = serieHistorica;
}

// calcularMediaMovel()
// Simples implementação do algoritmo passado no roteiro.
// O método recebe como argumento o intervalo em dias do qual sera calculada a média, respeitando os limites
// maximo e minimo estabelecidos no roteiro. 
// Por simplicidade, no construtor estou sempre calculcando a média móvel para 7 dias (o máximo).

double Estadual::calcularMediaMovel(uint intervaloEmDias, bool diaAnterior)
{
    double mediaMovel = 0;
 
    if (intervaloEmDias < 3){
        cout << "O limite minimo de calculo da media movel eh de 3 dias." << endl;
        cout<< "Calculando para esse valor." << endl;
        intervaloEmDias = 3;
    }


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

// calcularTendencia()
// Calcula a razão entre média móvel do estado para o dia atual e para o dia anterior, salvando-o como atributo do objeto.
// retorna um inteiro que simboliza sua tendencia.

int Estadual::calcularTendencia()
{
    razaoTendencia = getMediaMovel(false)/getMediaMovel(true);

    if (razaoTendencia > 1.1)
        return CRESCENTE;
    if (razaoTendencia < 0.9)
        return DECRESCENTE;
    else
        return ESTAVEL;
}

// calcularObitosAcumulados()
// Percorre a serie histórica somando todos seus elementos a uma variável, depois a retorna.

uint Estadual::calcularObitosAcumulados()
{
    uint obitosAcumulados = 0;

    for (int contador = 0; contador < comprimentoDaSerie; contador++)
        obitosAcumulados += serieHistorica[contador];

    return obitosAcumulados;
}

