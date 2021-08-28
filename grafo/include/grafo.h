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
        //void menorCaminhoEntre(Vertice, Vertice);
        void mostrarMaiorCentralidadeDeGrau();
        void dijkstra(Vertice, Vertice);


    private:
        vector<Aresta> arestas;
        vector<Vertice> vertices;
        
        void inserirAresta(Aresta);
        void registrarVertice(Vertice); 
        unsigned verificarExistenciaDoVertice(Vertice);
};

namespace dijkstra{
    class dijkstraInfo
    {
        public:
            dijkstraInfo(Vertice _vAtual, Vertice _vAnt,double _c)
            {
                custoDesdeOrigem = _c;
                verticeAnterior = _vAnt;
                verticeAtual = _vAtual;
            }
            double custoDesdeOrigem;
            Vertice verticeAnterior;
            Vertice verticeAtual;
            string nomeVerticeAtual;
    };
}
