// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Agenda{
    public:
        Agenda(unsigned);
        void insereNomes(string);
        void mostraNomes();

    private:
        vector <string> nomes;
        unsigned quantidadeNomes;   
};


