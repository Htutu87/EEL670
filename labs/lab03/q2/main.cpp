// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 02 
// Autor: Artur Amaral

#include "agenda.h"

int main (){
  
    Agenda a;
    int i;
    string nomeRecebido;


    while (i < 4)
    {
        cout << "Insira um nome na agenda: ";
        cin >> nomeRecebido;
        a.insereNomes(nomeRecebido);
        i ++;
    }

    a.mostraNomes();

    return 0;
}