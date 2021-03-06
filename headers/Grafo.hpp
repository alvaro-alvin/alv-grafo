#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include "Vertice.hpp"
#include "Conjunto.hpp"

class Grafo {
    private:
        unsigned int ordem = 0;
        unsigned int tamanho = 0;
        std::list<Vertice*> vertice;

        //called in DFS
        void DFS_VISIT(std::list<std::pair<unsigned int, unsigned int>> &v_r, unsigned int &tempo, Vertice &v);

        static bool compareArestasCost(const Aresta* a1, const Aresta* a2);
        static bool compareVerticesCost(const Vertice* v1, const Vertice* v2);

    public:
        unsigned int id;
        
        

        // construtor 
        Grafo();
        // destrutor
        ~Grafo();

        // adiciona um vertice com id gerado pelo grafo
        bool addVertice();
        bool addVertice(int id);
        // adiciona aresta que conecta dois vertices
        bool addAresta(unsigned int v1, unsigned int v2);
        bool addAresta(unsigned int v1, unsigned int v2, int custo);
        // remove um vertice por id
        //bool rmVertice(unsigned int id);
        // remove uam aresta por id
        //bool rmAresta(unsigned int id);
        // remove uma aresta por vertices conectados 
        //bool rmAresta(unsigned int v1, unsigned int v2);

        // retorna se existir um vertice por id
        Vertice * getVertice(unsigned int id);
        // retorna se existir uma aresta por id
        Aresta* getAresta(unsigned int id_v1, unsigned int id_v2);
        Aresta* getAresta(unsigned int id);

        unsigned int getOrdem();
        unsigned int getTamanho();

        std::list<Vertice*> vertices();
        std::list<Aresta*> arestas();

        std::list<Vertice*> adj(Vertice* v);

        unsigned int grau(Vertice* v);

        std::list<Aresta*> arestas(Vertice * v);

        Vertice* oposto(Vertice* v, Aresta* a);

        unsigned int* verticesA(Aresta * a); 


        // retorna a representacao do grafo em uma string
        std::string toSting();

        // busca em profundidade 
        std::vector<std::list<std::pair<unsigned int, unsigned int>>> DFS();

        std::list<std::pair<unsigned int, unsigned int>> BFS(int inicial);

        int** Floyd();

        Grafo kruskal();

        Grafo prim(int id_vertice_inicial);
};




#endif