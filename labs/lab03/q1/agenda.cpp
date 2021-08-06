/*

Classe Agenda


public:
    Agenda(N)
    insereNome(); -> Insere um nome por vez. Maximo de 10 caracteres por nome. Se for maior, truncar com substr e exibir msg de erro.
    mostraNomes(); -> Exibe todos os nomes inseridos, na tela

private:

    vector nomesDosContatos[N]; -> Os N nomes são inseridos pelo usuário, passado através do construtor
    unsigned N;

    // push_back() -> Insere elementos no vetor. 
    // size () -> retorna tamanho do vetor      -> Ambos métodos da classe vector.

*/

// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#include "agenda.h"

Agenda::Agenda(unsigned _quantidadeNomes){
    quantidadeNomes = _quantidadeNomes;
}

void Agenda::insereNomes(string nomeRecebido){

    if (nomes.size() >= quantidadeNomes){ 
        cout << "Erro: A agenda ja possui o limite maximo de nomes. (" << quantidadeNomes << " nomes)." << endl;
    } 
    else {
        if (nomeRecebido.length() > 10) 
            {
                nomeRecebido = nomeRecebido.substr(0,10);
                cout << "O nome inserido possui mais do que o limite de 10 caracteres." << endl;
                cout << "Nome truncado inserido: " << nomeRecebido << endl;
            }
        nomes.push_back(nomeRecebido);
    } 
}

void Agenda::mostraNomes(){
    for (auto nome: nomes)
        cout << nome << endl;
}

