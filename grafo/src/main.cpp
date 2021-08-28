// EEL670 - Linguagens de programação
// Período 2021.1 - Laboratório 01 - Exercício avaliado 02
// Autor: Artur Amaral

#include "../include/grafo.h"

int main (int argc, char **argv) 
{
    Grafo grafo;
//grafo.printarArestas();
    Vertice A("A");
    Vertice B("D");
    grafo.dijkstra(A,B);

    /* CODIGO PRINCIPAL
    int op;
    if (argc != 2){
        cout << "Numero invalido de argumentos.\nInsira um inteiro de 1 a 6. " <<endl; 
        exit(1);
    }

    op = atoi(argv[1]);

    switch (op)
    {
        case 1:
            cout << "-------------------------------------------------------" << endl;
            cout << "Operacao 01: Imprimir quantidade de vertices e arestas.\n" << endl;
            cout << "No de vertices: " << grafo.getQuantidadeVertices() << endl; 
            cout << "No de arestas: " << grafo.getQuantidadeArestas() << endl; 
            cout << "-------------------------------------------------------" << endl;
            break;
        case 2:
            cout << "-------------------------------------------------------" << endl;
            cout << "Operacao 02: Listar vertices do grafo.\n" << endl;
            grafo.printarVertices();
            cout << "-------------------------------------------------------" << endl;
            //
            break;
        case 3:
            cout << "Dijkstra." << endl;
            //
            break;
        case 4:
            cout << "Diametro do grafo." << endl;
            //
            break;
        case 5:
            cout << "Vertice de maior centralidade de grau" << endl;
            //
            break;
        case 6:
            cout << "Vertice de maior centralidade de intermediacao." << endl;
            break;
        default:
            cout << "Nenhuma operacao escolhida" << endl;
            break;  
    
    }

fim do código principal
*/ 
    return 0;
}
