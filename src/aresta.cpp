#include "../headers/Aresta.hpp"

Aresta::Aresta(unsigned int v1, unsigned int v2){
    vertice[0] = v1;
    vertice[1] = v2;
    Aresta::custo = 1;
}

Aresta::Aresta(unsigned int v1, unsigned int v2, int custo){
    vertice[0] = v1;
    vertice[1] = v2;
    Aresta::custo = custo;
}

std::string Aresta::toString(){
    std::ostringstream resultado;
    resultado << "[" << "(" << vertice[0] << " - " << vertice[1] << "), " << "id: " << id << ", custo: " << custo << "] " ;
    return resultado.str();
}