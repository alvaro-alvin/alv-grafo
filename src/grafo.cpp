#include "../headers/Grafo.hpp"

Grafo::Grafo(){

}

Grafo::~Grafo(){

}

bool Grafo::addVertice(){
    //estancia nova vertice com id padrão sendo a ordem + 1
    Vertice * v = new Vertice(ordem + 1);
    if(v == nullptr){
        std::cerr << "Erro ao alocar vertice!" << std::endl;
        return false;
    }
    vertice.push_back(v);
    ordem++;
    return true;
}

bool Grafo::addAresta(unsigned int v1, unsigned int v2){
    bool existe = false;
    //percorre os vertices para saber se são válidos 
    for(int i = 0; i < vertice.size(); i++){
        if(vertice[i]->id == v1){
            //se primeiro for percorre de novo para encontrar o segundo
            //(possivelamente da para fazer tudo na primeira passagem)
            for(int j = 0; j < vertice.size(); j++){
                if(vertice[j]->id == v2){
                    existe = true;
                    // apos validar os vertices a nova aresta é criada
                    Aresta * a = new Aresta(vertice[i], vertice[j]);
                    // seu id padrao é o tamanho + 1
                    a->id = tamanho + 1;
                    // a primeira vertice guarda a aresta adjacente
                    vertice[i]->aresta.adiciona_final(a);
                    // se nao for um laço o outro vertice guarda também
                    if(i != j){
                        vertice[j]->aresta.adiciona_final(a);
                    }
                    // finalemnte a aresta é adicionada ao grafo
                    //TODO: tryng to remove edges from gafo
                    aresta.push_back(a);
                    tamanho++;
                    break;
                }
            }
        }
    }
    if(!existe){
        std::cout << "Um ou ambos os vertices não existem" << std::endl;
        return false;
    }
    else{
        return true;
    }
    
}

std::string Grafo::toSting(){
    
    std::cout << "Tentando remover vertice " << id << std::endl;
    bool success = false;
    std::list<Vertice*>::iterator it = vertice.begin();
    while (it != vertice.end()){
        if ((*it)->id == id){
            std::ostringstream resultado;
        for(int i = 0; i < vertice.size(); i++){
            resultado << "V:" << (*it)->id << " - ";
            for(auto const &i: (*it)->aresta){
                resultado << i->toString() << std::endl;
            }
            resultado << std::endl;
            }
            return resultado.str();
        }
        else
        {
            ++it;
        }
    }
    /* ANTIGO TO_STRING
    std::ostringstream resultado;
    for(int i = 0; i < vertice.size(); i++){
        resultado << "V:" << vertice[i]->id << " - ";
        
            resultado << vertice[i]->aresta.to_string();
            
        resultado << std::endl;
    }
    return resultado.str();
    */
}

//ATUALEMNTE NAO FUNCIONA, VOLTAR AQUI DEPOIS
bool Grafo::rmVertice(unsigned int id){
    //UTILIZANDO LISTA (NOVO)
    std::cout << "Tentando remover vertice " << id << std::endl;
    bool success = false;
    std::list<Vertice*>::iterator it = vertice.begin();
    while (it != vertice.end()){
        if ((*it)->id == id){
            std::list<Aresta*>::iterator it2 = (*it)->aresta.begin();
            //TODO TODO: aqui vou utilizar a funcao remove aresat para todas as arestas do vertice que sera removido
            vertice.erase(it++); //need to be that way
            success = true;
        }
        else
        {
            ++it;
        }
    }
    //UTILIZANDO VECTORS (VELHO)
    for(int i = 0; i < vertice.size(); i++){
        if(vertice[i]->id == id){
            Vertice* v = vertice[i];
            // remove todas as arestas conectadas
            int tamanho = v->aresta.tam;
            for(int j = 0; j < tamanho; j++){
                //TODO: é preciso criar amneira de acessar os dados da lista 
                rmAresta(v->aresta[j]->id);
            }
            // remove o vertice 
            free(v);
            vertice.erase(vertice.begin() + i);
            ordem--;
            return true;
        }
    }
    std::cerr << "Nao foi possivel remover o vertice: nao existe!" << std::endl;
    return false;
}
//ATUALEMNTE NAO FUNCIONA, VOLTAR AQUI DEPOIS
bool Grafo::rmAresta(unsigned int id){

    //TODO: deve ser reimplementado para econtrar em cada vertice
    std::cout << "Tentando remover aresta " << id << std::endl;
    std::list<Aresta*>::iterator it = aresta.begin();
    while (it != vertice.end()){
        if ((*it)->id == id){
            std::list<Aresta*>::iterator it2 = (*it)->aresta.begin();
            //TODO TODO: aqui vou utilizar a funcao remove aresat para todas as arestas do vertice que sera removido
            vertice.erase(it++); //need to be that way
            success = true;
        }
        else
        {
            ++it;
        }
    }

    // encontra a aresta
    for(int i = 0 ; i < aresta.size(); i++){
        if(aresta[i]->id == id){
            // apaga sua referencia no prrimeiro vertice
            Vertice * v = aresta[i]->vertice[0];
            for(int j = 0; j < v->aresta.size(); j++){
                if(v->aresta[j]-> id == id){
                    v->aresta.erase(v->aresta.begin() + j);
                }
            }
            // apaga sua referencia no segundo vertice
            v = aresta[i]->vertice[1];
            for(int j = 0; j < v->aresta.size(); j++){
                if(v->aresta[j]-> id == id){
                    v->aresta.erase(v->aresta.begin() + j);
                }
            }
            // é apagada 
            /*
                TODO: isso vai ter que ser feito de outra maneira, apagar
                em ambos os vertices somente (como a cima)?
            */
            free(aresta[i]);
            aresta.erase(aresta.begin() + i);
            return true;
            tamanho--;
        }
    }
    std::cerr << "Nao foi possivel remover a aresta: nao existe!" << std::endl;
    return false;
}


Vertice* Grafo::getVertice(unsigned int id){
    for(int i = 0; i < vertice.size(); i++){
        if(vertice[i]-> id == id){
            return vertice[i];
        }
    }
    std::cerr << "Vertice nao existe:" << id << std::endl;
    return nullptr;
}

Aresta* Grafo::getAresta(unsigned int id_v1, unsigned int id_v2){
    //TODO: reimplementar par buscar as arestas somente nos vertices
    for(int i = 0; i < aresta.size(); i++){
        if(aresta[i]-> id == id){
            return aresta[i];
        }
    }
    std::cerr << "Aresta nao existe:" << id << std::endl;
    return nullptr;
}