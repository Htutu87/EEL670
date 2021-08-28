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

void debugDijkstra(vector<Aresta>& ref01,
                                vector<Aresta>& ref02)
{
    cout << setw(20) << "Inexplorados" << setw(18) << "Explorados" /*<< setw(20) << "MenorCaminho" << endl */ << endl;

    for (long unsigned int i = 0 ; i < 33; i++)
    {
        if (i < ref01.size())
            cout << setw(20) << ref01[i].visual
             << "(" << ref01[i].custoDesdeOrigem << ")";
        else
            cout << setw(20);
        if (i < ref02.size())
        {
            cout << setw(18) << ref02[i].visual 
            << "(" << ref02[i].custoDesdeOrigem << ")";
            cout << ref02[i].passoAnterior.getNome();
        }
        cout << endl;
        /*
        else
            cout << setw(18);
        if (i < ref03.size())
            cout << setw(20) << ref03[i].visual << endl;
        else
            cout << setw(20) << endl;*/

    }
}
/*
void Grafo::menorCaminhoEntre(Vertice verticeOrigem, Vertice verticeDestino)
{
    vector <Aresta> inexplorado;
    vector <Aresta> explorado;
    Aresta& verticeAtual = inexplorado[0];
    double distanciaTmp;
    int tmp;
    double minimo;
    int minimoIndice;
        

    cout<< "debug" << endl;
    // Inicializa o custoDesdeOrigem para todos os vértices e os adiciona oo
    // conjunto dos inexplorados.
    //
    //
    for (Aresta aresta:arestas)
    {
        if(aresta.getVerticeOrigem().getNome() == verticeOrigem.getNome())
            aresta.custoDesdeOrigem = aresta.getCusto();
        else
            aresta.custoDesdeOrigem = INFINITO;
        inexplorado.push_back(aresta);
    }
   
    //Loop principal. Realiza a operação até que todos os vértices tenham sido
    //explorados.
    //
     
    while (inexplorado.size() != 0)
    {
        minimo = INFINITO;
        minimoIndice = 0;
       
        cout<< "debug" << endl;

        for (long unsigned int i = 0; i < inexplorado.size();i++)
        {
            if (inexplorado[i].custoDesdeOrigem <= minimo )
            {
                minimo = inexplorado[i].custoDesdeOrigem;
                minimoIndice = i;
            }
        }

        cout<< "sai do for" << endl;

        explorado.push_back(inexplorado[minimoIndice]);       
        //verticeAtual = inexplorado[minimoIndice];
        //inexplorado.erase(inexplorado.begin()+minimoIndice);     
    
       ///// TEM UM SEGFAULT AQUI DENTRO. 
        for (Aresta& vizinho:inexplorado)
        {
            cout << "Vizinho: " << vizinho.visual << endl; 
            distanciaTmp = inexplorado[minimoIndice].custoDesdeOrigem + vizinho.getCusto();
            cout << "inexplorado.custoDO: " << inexplorado[minimoIndice].custoDesdeOrigem << endl;
            cout << "vizinho.custo: " << vizinho.getCusto()<< endl;
     
            if (vizinho.custoDesdeOrigem > distanciaTmp)
            {
                cout << "Atualizando custoDesdeOrigem de: " << vizinho.visual << endl;
                vizinho.custoDesdeOrigem = distanciaTmp;
                vizinho.passoAnterior = inexplorado[minimoIndice].getVerticeOrigem(); 
            } 
        }

        inexplorado.erase(inexplorado.begin()+minimoIndice);     
        //----------------------------------
        //cin>>tmp; 
        debugDijkstra(inexplorado, explorado); 
    }

    debugDijkstra(inexplorado, explorado); 
    //cout << explorado.size() << endl;
    //cout << inexplorado.size() << endl;


    Aresta& passo = explorado[0];
    for (Aresta aresta:explorado)
    {
    
    
    
    }



 *  //------------------------------------------------------
    // Varre vizinhos e atualiza seus custocaminhos
    //
    //
    //
    //
    // .
    for (Aresta& arestaDaOrigem:explorado)
        for (Aresta& arestaDoVizinho:inexplorado)
            if (arestaDoVizinho.getVerticeOrigem().getNome() == arestaDaOrigem.getVerticeDestino().getNome())
            {
                // EXTRAIR MÍNIMO
                if (arestaDoVizinho.custoDesdeOrigem > arestaDaOrigem.custoDesdeOrigem + arestaDoVizinho.getCusto())
                { 
                   arestaDoVizinho.custoDesdeOrigem = arestaDaOrigem.custoDesdeOrigem + arestaDoVizinho.getCusto();
                }
            }
 *  //------------------------------------------------------

    //debugDijkstra(inexplorado, explorado); 
 }
 */

using namespace dijkstra;

void Grafo::dijkstra(Vertice verticeOrigem, Vertice verticeDestino)
{
    //vector<dijkstraInfo> vertices;
    vector<dijkstraInfo> inexplorados;
    double distanciaTmp;
    dijkstraInfo* verticeAtual;//(Vertice _tmp1, Vertice _tmp2, double tmp);
    dijkstraInfo* verticeVizinho;//(Vertice _tmp1, Vertice _tmp2, double tmp);
     
    for (Vertice verticeDoGrafo:vertices)
    {
        if (verticeDoGrafo.getNome() != verticeOrigem.getNome())
        {
            dijkstraInfo _v(verticeDoGrafo, verticeOrigem,INFINITO);
            inexplorados.push_back(_v);
        }
        else
        {
            dijkstraInfo _v(verticeDoGrafo, verticeOrigem,0);
            inexplorados.push_back(_v);
        }
    }

    while(inexplorados.size() != 0)
    {
        double custoMinimo = INFINITO;
        unsigned indiceCustoMinimo = 0;
        for (auto vertice:inexplorados)
        {
            if(vertice.custoDesdeOrigem < custoMinimo)
            {
                custoMinimo = vertice.custoDesdeOrigem;
                verticeAtual = &vertice;
            }
            inexplorados.erase(inexplorados.begin()+indiceCustoMinimo);
            indiceCustoMinimo++;
        }

        // Para cada vizinho
        for (Aresta arestaDoGrafo:arestas)
        {
            if (arestaDoGrafo.getVerticeOrigem().getNome() == (*verticeAtual).nome  )
            {
                verticeVizinho = &arestaDoGrafo.getVerticeDestino();

            }
        
            if (arestaDoGrafo.getVerticeDestino().getNome() == verticeAtual.nome)
            {
                (*verticeVizinho) = arestaDoGrafo.getVerticeOrigem();
            }
            distanciaTmp = (*verticeAtual).custoDesdeOrigem +  arestaDoGrafo.getCusto();

            if (distanciaTmp < verticeVizinho.distanciaDesdeOrigem)
            {
                verticeVizinho.distanciaDesdeOrigem = distanciaTmp;
                verticeVizinho.verticeAnterior = (*verticeAtual);       
            }
        }
    }


}

void Grafo::mostrarMaiorCentralidadeDeGrau(){
}
