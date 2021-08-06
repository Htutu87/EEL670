// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

// TIVE UM PROBLEMAO COM O FATO DA CLASSE ESTADUAL NAO TER UM CONSTRUTOR DEFAULT.

#include "nacional.h"

// Construtor
// Ao criar um objeto Nacional, o construtor inicializa um objeto para cada estado brasileiro,
// definindo seu nome e a tendencia da sua série histórica.

Nacional::Nacional()
{
    // Instanciação dos objetos da classe Estadual.

    Estadual AC("Acre", CRESCENTE);
    Estadual AL("Alagoas", CRESCENTE);
    Estadual AP("Amapa", CRESCENTE);
    Estadual AM("Amazonas", CRESCENTE);
    Estadual BA("Bahia", CRESCENTE);
    Estadual CE("Ceara", CRESCENTE);
    Estadual ES("Espirito Santo", CRESCENTE);
    Estadual GO("Goias", CRESCENTE);
    Estadual MA("Maranhao", CRESCENTE);
    Estadual MT("Mato Grosso", DECRESCENTE);
    Estadual MS("Mato Grosso do Sul", DECRESCENTE);
    Estadual MG("Minas Gerais", DECRESCENTE);
    Estadual PA("Para", DECRESCENTE);
    Estadual PB("Paraiba", DECRESCENTE);
    Estadual PR("Parana", DECRESCENTE);
    Estadual PE("Pernambuco", DECRESCENTE);
    Estadual PI("Piaui", DECRESCENTE);
    Estadual RJ("Rio de Janeiro", DECRESCENTE);
    Estadual RN("Rio Grande do Norte", ESTAVEL);
    Estadual RS("Rio Grande do Sul", ESTAVEL);
    Estadual RO("Rondonia", ESTAVEL);
    Estadual RR("Roraima", ESTAVEL);
    Estadual SC("Santa Catarina", ESTAVEL);
    Estadual SP("Sao Paulo", ESTAVEL);
    Estadual SE("Sergipe", ESTAVEL);    
    Estadual TO("Tocantins", ESTAVEL);
    Estadual DF("Brasilia", ESTAVEL);

    // Inicialização do array que contem os objetos de cada estado.

    estados[indiceEstados::AC] = AC;
    estados[indiceEstados::AL] = AL;
    estados[indiceEstados::AP] = AP;
    estados[indiceEstados::AM] = AM;
    estados[indiceEstados::BA] = BA;
    estados[indiceEstados::CE] = CE;
    estados[indiceEstados::ES] = ES;
    estados[indiceEstados::GO] = GO;
    estados[indiceEstados::MA] = MA;
    estados[indiceEstados::MT] = MT;
    estados[indiceEstados::MS] = MS;
    estados[indiceEstados::MG] = MG;
    estados[indiceEstados::PA] = PA;
    estados[indiceEstados::PB] = PB;
    estados[indiceEstados::PR] = PR;
    estados[indiceEstados::PE] = PE;
    estados[indiceEstados::PI] = PI;
    estados[indiceEstados::RJ] = RJ;
    estados[indiceEstados::RN] = RN;
    estados[indiceEstados::RS] = RS;
    estados[indiceEstados::RO] = RO;
    estados[indiceEstados::RR] = RR;
    estados[indiceEstados::SC] = SC;
    estados[indiceEstados::SP] = SP;
    estados[indiceEstados::SE] = SE;
    estados[indiceEstados::TO] = TO;
    estados[indiceEstados::DF] = DF;

    // Inicialização de atributos gerais do país.

    computarSerieHistoricaNacional();
    mediaMovel = calcularMediaMovel(7,false);
    tendencia = calcularTendencia();
    obitosAcumulados = calcularObitosAcumulados();

}

// computarSerieHistoricaNacional()
// Este método percorre a série histórica de cada estado, somando o valor de cada dia à respectiva posição na
// série histórica do objeto Nacional, salvando como atributo da classe Nacional;

void Nacional::computarSerieHistoricaNacional()
{

    array <uint, comprimentoDaSerie> buffer;

    for (int i = 0; i < comprimentoDaSerie; i++)
        serieHistoricaNacional[i] = 0;

    for (auto estado: estados)
    {
        estado.getSerieHistorica(buffer);
        for (int i = 0; i < comprimentoDaSerie; i++)
            serieHistoricaNacional[i] += buffer[i];
    }
}

// Os próximos métodos (à exceção dos dois últimos) são implementações quase identicas dos métodos
// já comentados no arquivo estadual.h, por isso não os comentarei aqui.

double Nacional::calcularMediaMovel(uint intervaloEmDias, bool diaAnterior)
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
        mediaMovel += serieHistoricaNacional[comprimentoDaSerie-1-diaAnterior-i];
        //cout << serieHistorica[comprimentoSerie-1-i] << endl;
    }
    
    mediaMovel /= intervaloEmDias;

    return mediaMovel;

}

void Nacional::getSerieHistoricaNacional (array <uint, comprimentoDaSerie> &_buffer) {
    _buffer = serieHistoricaNacional;
}

void Nacional::getListaDeEstados (Estadual _estados[], uint _quantidadeEstados) {
    for (int i = 0; i<_quantidadeEstados;i++)
        _estados[i] = estados[i]; 
}

double Nacional::getMediaMovel(bool diaAnterior){
    mediaMovel = calcularMediaMovel(comprimentoDaSerie-1, diaAnterior);
    return mediaMovel;
}
int Nacional::getTendencia(){
    return tendencia;
}
uint Nacional::getObitosAcumulados(){
    return obitosAcumulados;
}

uint Nacional::getQuantidadeEstados(){
    return quantidadeEstados;
}

uint Nacional::getComprimentoDaSerie(){
    return comprimentoDaSerie;
}

int Nacional::calcularTendencia()
{
    double razao = getMediaMovel(false)/getMediaMovel(true);
    
    if (razao > 1.1)
        return CRESCENTE;
    if (razao < 0.9)
        return DECRESCENTE;
    else
        return ESTAVEL;
}

uint Nacional::calcularObitosAcumulados()
{
    uint obitosAcumulados = 0;

    for (int contador = 0; contador < comprimentoDaSerie; contador++)
        obitosAcumulados += serieHistoricaNacional[contador];

    return obitosAcumulados;
}

// getEstadoComMaiorAlta() e getEstadoComMenorBaixa()
// Esses métodos obtem a razao da tendencia de cada estado e aplicam simples
// algoritmos de máximo e minimo para determinar os respectivos extremos.
// Como optei por inicialzar as séries históricas idênticas para cada tendência, o
// resultado prático destes métodos é indicar o primeiro estado em que ele encotra um extremo. 
// O método retorna um inteiro que permite à quem o chama indexar o estado por fora desta função.

uint Nacional::getEstadoComMaiorAlta()
{
    uint indiceMaiorAlta;
    double maiorAlta = 0;
    double razaoTendencia;

    for (int i = 0; i < quantidadeEstados; i++)
    {
        razaoTendencia = estados[i].getRazaoTendencia();
        if (razaoTendencia > maiorAlta){
            maiorAlta = razaoTendencia;
            indiceMaiorAlta =  i;
        }
            
    }
    
    return indiceMaiorAlta;
}

uint Nacional::getEstadoComMenorBaixa()
{
    uint indiceMenorBaixa;
    double menorBaixa = 10000;
    double _razaoTendencia;

    for (int i = 0; i < quantidadeEstados; i++)
    {

        // cout<< estados[i].getNome()<<endl;
        _razaoTendencia = estados[i].getRazaoTendencia();
        if (_razaoTendencia < menorBaixa){
            menorBaixa = _razaoTendencia;
            indiceMenorBaixa =  i;
        }
            
    }
    return indiceMenorBaixa;
}
