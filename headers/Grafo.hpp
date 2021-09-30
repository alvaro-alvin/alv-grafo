#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <vector>
#include <iostream>
#include "Vertice.hpp"

class Grafo {
    private:
        unsigned int ordem = 0;
        unsigned int tamanho = 0;

    public:
        unsigned int id;
        std::vector<Vertice*> vertice;
        std::vector<Aresta*> aresta;

        // construtor 
        Grafo();
        // destrutor
        ~Grafo();

        // adiciona um vertice com id gerado pelo grafo
        bool addVertice();
        // adiciona aresta que conecta dois vertices
        bool addAresta(unsigned int v1, unsigned int v2);
        // remove um vertice por id
        bool rmVertice(unsigned int id);
        // remove uam aresta por id
        bool rmAresta(unsigned int id);
        //remo uma aresta por vertices conectados 
        //TODO: bool rmAresta(unsigned int v1, unsigned int v2);

        // retorna se existir um vertice por id
        Vertice * getVertice(unsigned int id);
        // retorna se existir uma aresta por id
        Aresta * getAresta(unsigned int id);

        // retorna a representacao do grafo em uma string
        std::string toSting();
};




#endif