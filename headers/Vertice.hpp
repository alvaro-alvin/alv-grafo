#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED

#include <vector>
#include "Aresta.hpp"
#include <string>
#include <sstream>

class Aresta;

class Vertice {

    public:
        unsigned int id;
        // vetor com referencia para todas as atestas adjacentes ao vertice
        std::vector<Aresta*> aresta;

        Vertice(unsigned int id);

};




#endif