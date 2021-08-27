// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 02
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/grafo.h"

Grafo::Grafo(){

    vector<string> parsedCSV;
    string caminhoParaArquivo = "data/grafo-descrito.csv";
    ifstream arquivo;
    string linhaArquivo;
    string getLineContent;
    Vertice verticeOrigemTmp;
    Vertice verticeDestinoTmp;


    string nomeVerticeOrigem;
    string nomeVerticeDestino;
    string custoStr;

    double custo;
    string tmp;

    arquivo.open(caminhoParaArquivo);
    if (!arquivo)
        cout << "Impedido de abrir arquivo." << endl; 
    
    while(true)
    {
        arquivo >> linhaArquivo;
        if (arquivo.eof()) break; // Esta declaração trata o comportamento de não repetir a última linha do arquivo.
        //cout << linhaArquivo;
        //getline(cin, tmp);

        nomeVerticeOrigem = linhaArquivo.substr(0, linhaArquivo.find(','));
        linhaArquivo = linhaArquivo.erase(0,linhaArquivo.find(',') + 1/*COMPRIMENTO DELIMMITADOR*/);
        nomeVerticeDestino = linhaArquivo.substr(0, linhaArquivo.find(','));
        custoStr = linhaArquivo.substr(linhaArquivo.find(',')+1, linhaArquivo.find('\n'));
        custo = stod(custoStr);

        /* PARA DEPURAÇÃO
        cout << "nomeVerticeOrigem: " << nomeVerticeOrigem << endl;
        cout << "nomeVerticeDestino: " << nomeVerticeDestino << endl;
        cout << "Custo: " << custo +1.5 << endl << endl;
        */

        Aresta aresta(nomeVerticeOrigem, nomeVerticeDestino, custo);
        inserirAresta(aresta);
        if (!verificarExistenciaDoVertice(aresta.getVerticeOrigem()))
            registrarVertice(aresta.getVerticeOrigem());
        if (!verificarExistenciaDoVertice(aresta.getVerticeDestino()))
            registrarVertice(aresta.getVerticeDestino());
    }
    arquivo.close();

    cout << "\nArquivo lido com sucesso.\nNumero de arestas inicializadas: " << arestas.size() << endl;

}

void Grafo::inserirAresta(Aresta _aresta){
    arestas.push_back(_aresta);
    /*cout << "Aresta inserida com sucesso (" << _aresta.getVerticeOrigem().getNome()
        << "--" << _aresta.getCusto() << "-->"
        << _aresta.getVerticeDestino().getNome() << ")" <<endl;*/
}

void Grafo::registrarVertice(Vertice _vertice){
    vertices.push_back(_vertice);
}

unsigned Grafo::verificarExistenciaDoVertice(Vertice verticeAvaliado){

    unsigned verticeExiste = 0;

    //cout << "Verificando a existencia do vertice: " << verticeAvaliado.getNome() << endl;

    for (Aresta aresta:arestas)
        for (Vertice verticeNaLista:vertices)
            if( verticeAvaliado.getNome() == verticeNaLista.getNome())
                verticeExiste = 1; 
    
    return verticeExiste;
}

void Grafo::printarVertices(){
    for (Vertice vertice:vertices)
        cout << vertice.getNome() << " ";
    cout << endl; 
}

void Grafo::printarArestas(){
    for (Aresta aresta:arestas)
        aresta.exibirNaTela();
}


unsigned Grafo::getQuantidadeVertices(){
    return vertices.size();
}

unsigned Grafo::getQuantidadeArestas(){
    return arestas.size();
}

void Grafo::mostrarMaiorCentralidadeDeGrau(){
}
