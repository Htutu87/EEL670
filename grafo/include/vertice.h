// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 02
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "dependencias.h"

class Vertice{

    public:
        Vertice();
        Vertice(string);
        string getNome();
        void setNome(string);        
        void setCentralidadeDeGrau(unsigned);
        unsigned getCentralidadeDeGrau();
                
    private:
        string nome;
        unsigned centralidadeDeGrau;

};
