// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 03 - Exercício avaliado 01
// Autor: Artur Amaral

#include "nacional.h"

void printaMenu()
{

    cout << "\nPAINEL INTERATIVO:\n\tDados de obito causadas pela COVID-19 no Brasil." << setw(4) << endl << endl;

    cout << "------------- MENU -------------------------------------------------" << endl << endl;
    cout << "Operacoes disponiveis:" << endl << endl;
    cout << "1 - Exibir a media movel de obitos no Brasil e seus estados." << endl;
    cout << "2 - Exibir a tendencia do numero de obitos em cada estado" << endl;
    cout << "3 - Exibir a tendencia do numero de obitos no pais" << endl;
    cout << "4 - Exibir estados com maior alta e menor baixa, segundo a media movel." << endl;
    cout << "5 - Exibir dados acumulados de numero de obitos no Brasil e seus estados" << endl << endl;

    cout << "0 - Sair" << endl << endl;

    cout << "Insira uma opcao: ";
}


int main () 
{

    string stringEntrada;
    char operacaoEscolhida;
    bool executarPrograma = true;

    // Instanciação do objeto que reprensenta o país. Automaticamente ele já inicializa um objeto para cada estado brasileiro (Ver seu construtor).
    Nacional BR;

    // Abaixo tem-se variáveis gerais para facilitar a manipulação dos objetos.
    const uint maximoComprimentoSerie = 8;
    const uint quantidadeEstadosBrasileiros = 26+1;
    uint quantidadeEstados = BR.getQuantidadeEstados();

    // Arrays buffer -> Copiam momentaneamente o conteúdo de arrays internos aos objetos, para manipulá-los na main().
    array <uint, maximoComprimentoSerie> bufferSerieNacional;
    Estadual bufferEstados[quantidadeEstadosBrasileiros];

    BR.getSerieHistoricaNacional(bufferSerieNacional);
    BR.getListaDeEstados(bufferEstados, quantidadeEstadosBrasileiros);

    // Loop principal.

    while(executarPrograma)
    {
        printaMenu();

        getline(cin, stringEntrada);

        // A operação abaixo serve para transformar a string obtida no getline() em um char, de modo que
        // eu possa avaliar a opção através de um switch (Código fica mais organizado).
        if (stringEntrada.length() == 1)
            operacaoEscolhida = stringEntrada[0];
        
        cout << endl << "--------------------------------------------------------------------" << endl;

        switch (operacaoEscolhida)
        {
        
        case '0':
            executarPrograma = false;

            break;
        
        case '1':
            
            cout << endl << "MEDIA MOVEL DO PAIS E ESTADOS" << endl << endl;

            cout << "Brasil: " << BR.getMediaMovel() << endl << endl;

            for (int indice = 0; indice < quantidadeEstados; indice++)
            {
                cout << bufferEstados[indice].getNome() << ": ";
                cout << bufferEstados[indice].getMediaMovel() << endl;
            } 
            
            cout << endl;

            break;
        
        case '2':
            
            cout << "TENDENCIA DOS ESTADOS:" << endl;

            cout << "---" << endl << "Estados em ALTA:" << endl << endl;

            for (int indice = 0; indice < quantidadeEstados; indice++)
            {
                if (bufferEstados[indice].getTendencia() == CRESCENTE)
                    cout << bufferEstados[indice].getNome() << endl;
            }

            cout << endl;

            cout << "---" << endl <<  "Estados em BAIXA:" << endl << endl;

            for (int indice = 0; indice < quantidadeEstados; indice++)
            {
                if (bufferEstados[indice].getTendencia() == DECRESCENTE)
                    cout << bufferEstados[indice].getNome() << endl;
            }

            cout << endl;

            cout << "---" << endl <<  "Estados ESTAVEIS:" << endl << endl;

            for (int indice = 0; indice < quantidadeEstados; indice++)
            {
                if (bufferEstados[indice].getTendencia() == ESTAVEL)
                    cout << bufferEstados[indice].getNome() << endl;
            }

            cout << endl;

            break;

        case '3':

            if (BR.getTendencia() == CRESCENTE)
                cout << "Tendencia do Pais: CRESCENTE." << endl << endl;
            else if (BR.getTendencia() == DECRESCENTE)
                cout << "Tendencia do Pais: DECRESCENTE." << endl << endl;
            else if (BR.getTendencia() == ESTAVEL)
                cout << "Tendencia do Pais: ESTAVEL." << endl << endl;
            
            break;

        case '4':

            cout << "MAIOR ALTA: " << bufferEstados[BR.getEstadoComMaiorAlta()].getNome() << endl; 
            cout << "MENOR BAIXA: " << bufferEstados[BR.getEstadoComMenorBaixa()].getNome() << endl<<endl;
            
            break;

        case '5':
            
            cout << endl << "OBITOS ACUMULADOS: Desde o início da serie historica" << endl << endl;

            cout << "Brasil: " << BR.getObitosAcumulados() << endl << endl;

            for (int indice = 0; indice < quantidadeEstados; indice++)
            {
                cout << bufferEstados[indice].getNome() << ": ";
                cout << bufferEstados[indice].getObitosAcumulados() << endl;
            } cout << endl;

            break;

        default:

            cout << "Opcao invalida." << endl;

            break;

        }

        if(executarPrograma)
        {
            // A atribuição abaixo não tem relevância, serve apenas para travar o código antes de printar o menu novamente.
            cout << "Aperte [ENTER] para prosseguir: ";
            getline(cin, stringEntrada);
        }

    }

    return 0;
}