#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

#include <vector>
#include "Vertice.hpp"
#include <list>
#include <string>
#include <sstream>

class Vertice;

class Aresta {

    public:
        unsigned int id;
        int custo;
        unsigned int vertice[2];
        // referencia para os dois vertices conectados pela aresta
        Aresta(unsigned int v1, unsigned int v2);

        Aresta(unsigned int v1, unsigned int v2, int custo);
        //retorna uma representacao da aresta em string
        std::string toString();

};

#endif