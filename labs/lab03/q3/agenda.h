// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#include <iostream>
#include <string>
#include <array>

using namespace std;

class Agenda{
    public:
        Agenda();
        void insereCadastro(Cadastro);
        void mostraCadastros();

    private:
        const static unsigned maxCadastros = 10;
        array <Cadastro, maxCadastros> cadastros;
        static unsigned numeroCadastros;
};

class Cadastro {
    public:
        void            setNome(string);
        void            setProfissao(string);
        void            setIdade(unsigned short);
        string          getNome();
        string          getProfissao();
        unsigned short  getIdade();

    private: 
        string nome;
        string profissao;
        unsigned short idade;


};


