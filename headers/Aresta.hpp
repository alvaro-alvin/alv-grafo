#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

#include <vector>
#include "Vertice.hpp"
#include <string>
#include <sstream>
#include "../external_dependencys/lista_encadeada.cpp"

class Vertice;

class Aresta {

    public:
        unsigned int id;
        Vertice* vertice[2];
        // referencia para os dois vertices conectados pela aresta
        Aresta(Vertice * v1, Vertice * v2);
        //retorna uma representacao da aresta em string
        std::string toString();

};

#endif