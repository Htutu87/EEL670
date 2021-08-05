// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#include "agenda.h"

unsigned Agenda::numeroCadastros = 0;

Agenda::Agenda(){}

void Agenda::insereCadastro(Cadastro cadastroRecebido){

    if (numeroCadastros >= maxCadastros){ 
        cout << "Erro: A agenda ja possui o limite maximo de cadastros. (" << maxCadastros << " cadastros)." << endl;
    } 
    else {
        if (cadastroRecebido.getNome() > 10) 
            {
                cadastroRecebido.getNome() = cadastroRecebido.getNome().substr(0,10);
                cout << "O nome inserido possui mais do que o limite de 10 caracteres." << endl;
                cout << "Nome truncado inserido: " << cadastroRecebido.getNome() << endl;
            }

        cadastros[numeroCadastros] = cadastroRecebido;

        numeroCadastros++; // Atributo estático que fica contando quantas vezes um nome foi adicionado, para conseguir indexar o próximo nome a ser inserido.
                       // Lembre-se: O array não possui o método de empilhar um nome ao final da lista, tudo deve ser indexado.
    } 
}

void Agenda::mostraCadastros(){
    for (auto cadastro: cadastro)
        if (cadastros.length() > 0)
            cout << cadastros.getName() << endl;
}


void Cadastro::setNome(string _nome){
    nome = _nome;
}
void Cadastro::setProfissao(string _profissao){
    nome = _profissao;
}
void Cadastro::setIdade(unsigned short _idade){
    idade = _idade;
}
string Cadastro::getNome(){
    return nome;
}
string Cadastro::getProfissao(){
    return profissao;
}
unsigned short Cadastro::getIdade(){
    return idade;
}