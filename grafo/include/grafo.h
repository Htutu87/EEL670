// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 02
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "aresta.h"

class Grafo{

    public:
        Grafo();  
        void printarVertices();
        void printarArestas();
        unsigned getQuantidadeVertices();
        unsigned getQuantidadeArestas();
        void mostrarMaiorCentralidadeDeGrau();

    private:
        vector<Aresta> arestas;
        vector<Vertice> vertices;
        
        void inserirAresta(Aresta);
        void registrarVertice(Vertice); 
        unsigned verificarExistenciaDoVertice(Vertice);
};

