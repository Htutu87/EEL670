/*

O lance desse exercicio é que agora o numero máximo de nomes na agenda vai ser dado por um atributo
constante e estático da classe, não mais passado pelo usuário.

Outro detalhe também é que como o array já possui um tamanho pré-definido, algumas implementações mudam.
Adicionar um nome tem que ser feito por indexação, não mais por um método que empilha ao final do vector.
A contagem é feita por um atributo estático da classe, que sabe qual indice ele deve atribuir o nome inserido.

*/

// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#include "agenda.h"

unsigned Agenda::numeroNomes = 0;

Agenda::Agenda(){}

void Agenda::insereNomes(string nomeRecebido){

    if (numeroNomes >= maxNomes){ 
        cout << "Erro: A agenda ja possui o limite maximo de nomes. (" << maxNomes << " nomes)." << endl;
    } 
    else {
        if (nomeRecebido.length() > 10) 
            {
                nomeRecebido = nomeRecebido.substr(0,10);
                cout << "O nome inserido possui mais do que o limite de 10 caracteres." << endl;
                cout << "Nome truncado inserido: " << nomeRecebido << endl;
            }

        nomes[numeroNomes] = nomeRecebido;

        numeroNomes++; // Atributo estático que fica contando quantas vezes um nome foi adicionado, para conseguir indexar o próximo nome a ser inserido.
                       // Lembre-se: O array não possui o método de empilhar um nome ao final da lista, tudo deve ser indexado.
    } 
}

void Agenda::mostraNomes(){
    for (auto nome: nomes)
        if (nome.length() > 0)
            cout << nome << endl;
}

