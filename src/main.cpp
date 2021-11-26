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
  g.addVertice();
  g.addVertice();

  std::cout << "Vertices adicionada com sucesso!" << std::endl;

  std::cout << "Adicionando arestas..." << std::endl;

  g.addAresta(1,2);
  g.addAresta(1,3);
  g.addAresta(2,4);
  g.addAresta(1,5);
  g.addAresta(3,6);
  g.addAresta(2,6);
  g.addAresta(7,8);

  std::cout << "Arestas adicionadas com sucesso" << std::endl << std::endl;

  std::cout << "Ordem do grafo: " << g.getOrdem() << std::endl;

  std::cout << "Tamanho do grafo: " << g.getTamanho() << std::endl << std::endl;

  std::cout << "Grafo: "<< std::endl;

  std::cout << g.toSting() << std::endl;

  std::cout << "Aresta que conecta vertices 1 e 3: " << g.getAresta(1,3)->id << std::endl;

  std::cout << "Aresta oposta ao vertice 1 pela aresta 2: " << 
    g.oposto(g.getVertice(1), g.getAresta(2))->id << std::endl;

  std::cout << "Grau do vertice 1: " << g.grau(g.getVertice(1)) << std::endl;

  std::cout << "Executando busca em profundiade:" << std::endl;

  std::vector<std::list<std::pair<unsigned int, unsigned int>>> v_r = g.DFS();

  std::cout << "vetor de resultados:" << std::endl;


  for(int i =0; i<v_r.size(); i++){
    std::list<std::pair<unsigned int, unsigned int>>::iterator it;
    it = v_r[i].begin();
    std::cout << "Vetor " << i+1 << std::endl;
    for(it=v_r[i].begin(); it!=v_r[i].end(); ++it){
      std::cout << it->first << " é pai de " << it->second << std::endl;
    }
    std::cout << "=========================" << std::endl;

  }

  std::cout << std::endl;






    

    return 0 ;
}