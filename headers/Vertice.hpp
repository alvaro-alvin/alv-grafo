#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED

#include <vector>
#include <list>
#include "Aresta.hpp"
#include <string>
#include <sstream>
#include "../external_dependencys/lista_encadeada.cpp"

class Aresta;

class Vertice {

    public:
        unsigned int id;
        // vetor com referencia para todas as atestas adjacentes ao vertice
        std::list<Aresta*> aresta;

        Vertice(unsigned int id);

};




#endif