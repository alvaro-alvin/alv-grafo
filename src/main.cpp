#include "../headers/Grafo.hpp"

int main( int argc, char *argv[ ], char *envp[ ] ){
    Grafo g;
    g.addVertice();
    g.addVertice();
    g.addAresta(1,2);
    g.addVertice();
    g.addVertice();
    g.addVertice();
    g.addVertice();
    g.addAresta(1,3);
    g.addAresta(2,4);

    std::cout << g.toSting() << std::endl;

    g.rmVertice(2);

    std::cout << g.toSting() << std::endl;

    return 0 ;
}