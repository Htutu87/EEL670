// EEL660 - Laboratório 01 - questão 03
// Artur Amaral - jul/2021

#include <iostream>
#include <string>

using namespace std;

class Agenda{
    public:
        void setNames(); // interage com o usuário.
        void getNames();
    private:
        string checkNames(string);
        string names[3];
};