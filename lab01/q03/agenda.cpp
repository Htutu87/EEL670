// EEL660 - Laboratório 01 - questão 03
// Artur Amaral - jul/2021

#include "agenda.h"

void Agenda::setNames(){
    
    string name;

    cout << "Insira o nome dos tres contatos." << endl;
    cout << "Primeiro contato: " << endl;
    cin >> name;
    names[0] = checkNames(name);
    cout << "Segundo contato: " << endl;
    cin >> name;
    names[1] = checkNames(name);
    cout << "Terceiro contato: " << endl;
    cin >> name;
    names[2] = checkNames(name);
}

void Agenda::getNames(){
    unsigned short i;
    cout << "CONTATOS: "<< endl;
    for (i=0; i<=2; i++)
        cout << names[i] << endl;
}

string Agenda::checkNames(string name){

    if (name.length() > 10){
        name = name.substr(0, 10);
        cout << "Invalid name." << endl;
    }

    return name;
}   