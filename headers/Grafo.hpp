#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include "Vertice.hpp"
//#include "../external_dependencys/lista_encadeada.cpp"

class Grafo {
    private:
        unsigned int ordem = 0;
        unsigned int tamanho = 0;
        std::list<Vertice*> vertice;

    public:
        unsigned int id;
        
        
        //std::list<Aresta*> aresta;

        // construtor 
        Grafo();
        // destrutor
        ~Grafo();

        // adiciona um vertice com id gerado pelo grafo
        bool addVertice();
        // adiciona aresta que conecta dois vertices
        bool addAresta(unsigned int v1, unsigned int v2);
        // remove um vertice por id
        //bool rmVertice(unsigned int id);
        // remove uam aresta por id
        //bool rmAresta(unsigned int id);
        // remove uma aresta por vertices conectados 
        //TODO: bool rmAresta(unsigned int v1, unsigned int v2);

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
};




#endif