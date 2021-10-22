#include "../headers/Grafo.hpp"
int main( int argc, char *argv[ ], char *envp[ ] ){
    Grafo g;
    std::cout << "Grafo criado com sucesso" << std::endl;

    g.addVertice();

    std::cout << "Vertices adicionada com sucesso" << std::endl;

    g.addVertice();
    g.addAresta(1,2);

    std::cout << "Aresta adicionada com sucesso" << std::endl;

    g.addVertice();
    g.addVertice();
    g.addVertice();
    g.addVertice();
    g.addAresta(1,3);
    g.addAresta(2,4);

    std::cout << "Vertices e arestas adicionadas com sucesso" << std::endl;

    std::cout << g.toSting() << std::endl;

    //g.rmVertice(2);
    //TODO: arestas não estao aparecendo em seus segundos vértices

    std::cout << g.toSting() << std::endl;

    return 0 ;
}