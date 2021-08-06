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
        void insereNomes(string);
        void mostraNomes();

    private:
        const static unsigned maxNomes = 10;
        array <string, maxNomes> nomes;
        static unsigned numeroNomes;
};


