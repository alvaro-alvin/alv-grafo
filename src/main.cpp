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
  g.addVertice();

  std::cout << "Vertices adicionada com sucesso!" << std::endl;

  std::cout << "Adicionando arestas..." << std::endl;


  // vertice 1, vertice 2, custo
  g.addAresta(1,2,4);
  g.addAresta(2,3,8);
  g.addAresta(3,4,7);
  g.addAresta(4,5,9);
  g.addAresta(5,6,10);
  g.addAresta(6,7,2);
  g.addAresta(7,8,1);
  g.addAresta(8,9,7);
  g.addAresta(8,1,8);
  g.addAresta(8,2,11);
  g.addAresta(9,3,2);
  g.addAresta(7,9,6);
  g.addAresta(6,3,4);
  g.addAresta(6,4,14);
  std::cout << "Arestas adicionadas com sucesso" << std::endl << std::endl;

  std::cout << "Ordem do grafo: " << g.getOrdem() << std::endl;

  std::cout << "Tamanho do grafo: " << g.getTamanho() << std::endl << std::endl;

  std::cout << "Grafo: "<< std::endl;

  std::cout << g.toSting() << std::endl;

  std::list<Aresta*> a = g.arestas();
  std::list<Aresta*>::iterator it_a = a.begin();

    std::cout << "Lista de arestas: "<< std::endl;
  for(it_a = a.begin(); it_a!=a.end(); ++it_a){
      std::cout << (*it_a)->id << " " << std::endl;
  }

  
  

  std::cout << "Aresta que conecta vertices 1 e 3: " << g.getAresta(1,2)->id << std::endl;


  /*
  std::cout << "Aresta oposta ao vertice 1 pela aresta 2: " << 
    g.oposto(g.getVertice(1), g.getAresta(2))->id << std::endl;
  */
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

  std::cout << "Executando algorítimo de Floyd para encontar a matriz de custo mínimo:"<< std::endl;


  int **matriz = g.Floyd();

  std::cout << "Mtriz de custo mínimo:"<< std::endl;

  for(int i = 0; i<((int) (sizeof(matriz))); i++){
    std::cout << "|";
        for(int j = 0; j<((int) (sizeof(matriz))); j++){
          if( matriz[i][j] >= INT8_MAX)
            std::cout << " n ";            
          else
            std::cout << " " << matriz[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
  
  std::cout << "Vetor de roteamento da busca em largura:"<< std::endl;

  std::list<std::pair<unsigned int, unsigned int>> v_r_BFS;

  v_r_BFS = g.BFS(1);

  std::list<std::pair<unsigned int, unsigned int>>::iterator itt;
  itt = v_r_BFS.begin();
  for(itt=v_r_BFS.begin(); itt!=v_r_BFS.end(); ++itt){
    std::cout << itt->first << " é pai de " << itt->second << std::endl;
  }
  std::cout << "=========================" << std::endl;



  std::cout << "Arestas do grafo(arvore) mínimo - Kruskal:"<< std::endl;
Grafo g_kruskal;
g_kruskal = g.kruskal();
std::cout << "somente arestas:" << std::endl;
std::list<Aresta*> aa = g_kruskal.arestas();
for(auto it = aa.begin(); it!=aa.end(); it++){
  std::cout << (*it)->toString() << std::endl;
}

  std::cout << "Arestas do grafo(arvore) mínimo - Prim:"<< std::endl;
Grafo g_prim;
g_prim = g.prim(1);
std::cout << "somente arestas:" << std::endl;
aa = g_prim.arestas();
for(auto it = aa.begin(); it!=aa.end(); it++){
  std::cout << (*it)->toString() << std::endl;
}

    return 0 ;
}