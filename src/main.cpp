#include "../headers/Grafo.hpp"
int main( int argc, char *argv[ ], char *envp[ ] ){
    Grafo g;
    std::cout << "Grafo instanciado com sucesso!" << std::endl;

    std::cout << "Adicionando vertices..." << std::endl;
    
    g.addVertice();
    g.addVertice();
    g.addVertice();
    g.addVertice();
    g.addVertice();
    g.addVertice();

    std::cout << "Vertices adicionada com sucesso!" << std::endl;

    std::cout << "Adicionando arestas..." << std::endl;

    g.addAresta(1,2);
    g.addAresta(1,3);
    g.addAresta(2,4);

    std::cout << "Arestas adicionadas com sucesso" << std::endl << std::endl;

    std::cout << "Ordem do grafo: " << g.getOrdem() << std::endl;

    std::cout << "Tamanho do grafo: " << g.getTamanho() << std::endl << std::endl;

    std::cout << "Grafo: "<< std::endl;

    std::cout << g.toSting() << std::endl;

    std::cout << "Aresta que conecta vertices 1 e 3: " << g.getAresta(1,3)->id << std::endl;

    std::cout << "Aresta oposta ao vertice 1 pela aresta 2: " << 
      g.oposto(g.getVertice(1), g.getAresta(2))->id << std::endl;

    std::cout << "Grau do vertice 1: " << g.grau(g.getVertice(1)) << std::endl;






    

    return 0 ;
}