#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

#include <vector>
#include "Vertice.hpp"
#include <list>
#include <string>
#include <sstream>
//#include "../external_dependencys/lista_encadeada.cpp"

class Vertice;

class Aresta {

    public:
        unsigned int id;
        unsigned int vertice[2];
        // referencia para os dois vertices conectados pela aresta
        Aresta(unsigned int v1, unsigned int v2);
        //retorna uma representacao da aresta em string
        std::string toString();

};

#endif