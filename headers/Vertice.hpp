#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED

#include <vector>
#include <list>
#include "Aresta.hpp"
#include <string>
#include <sstream>

class Aresta;

class Vertice {

    public:
        unsigned int id;
        // vetor com referencia para todas as atestas adjacentes ao vertice
        std::list<Aresta*> aresta;

        // status: 0 = branco, 1 = cinza, 2 = preto
        short int status = 0;
        // tempo em que foi aberto
        int aberto;
        // tempo em que foi fechado
        int fechado;
        // custo para chegar até ele
        int custo;
        // custo para chegar até ele
        int pai;

        Vertice(unsigned int id);

};




#endif