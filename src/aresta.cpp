#include "../headers/Aresta.hpp"

Aresta::Aresta(Vertice * v1, Vertice * v2){
    vertice[0] = v1;
    vertice[1] = v2;
}

std::string Aresta::toString(){
    std::ostringstream resultado;
    resultado << " (" << vertice[0]->id << ", " << vertice[1]->id << ") " << "id: " << id ;
    return resultado.str();
}