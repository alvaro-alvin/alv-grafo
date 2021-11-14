#include "../headers/Grafo.hpp"

Grafo::Grafo(){

}

Grafo::~Grafo(){

}

bool Grafo::addVertice(){ // -------------------------------------- OK
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

bool Grafo::addAresta(unsigned int v1, unsigned int v2){ //--------------------- OK
    // valida a existencia dos vertices requeridos pela nova aresta 
    bool existe_v1 = false;
    bool existe_v2 = false;
    bool existe = false;
    std::list<Vertice*>::iterator it = vertice.begin();
    // percorre os vertices para validar a existencia 
    while (it != vertice.end()){
        if ((*it)->id == v1 && existe_v1 == false){
            existe_v1 = true;
            ++it;
        }
        else if((*it)->id == v2 && existe_v2 == false){
            existe_v2 = true;
            ++it;
        }
        else
        {
            ++it;
        }
    }
    existe = existe_v1 && existe_v2;

    if(existe){
        // apos validar os vertices a nova aresta é criada
        Aresta * a = new Aresta(v1, v2);
        // seu id padrao é o tamanho + 1
        a->id = tamanho + 1;
        // percorre os vertices e adiciona as aresta a ambos
        it = vertice.begin();
        while (it != vertice.end()){
            if ((*it)->id == v1){
                (*it)->aresta.push_back(a);
                ++it;
            }
            else if((*it)->id == v2){
                (*it)->aresta.push_back(a);
                ++it;
            }
            else
            {
                ++it;
            }
        }
        tamanho++;
        return true;
    }
    else{
        std::cout << "Um ou ambos os vertices não existem" << std::endl;
        return false;
    }

}

std::string Grafo::toSting(){ // ----------------------------------------- OK
    std::ostringstream resultado;
    //percorre os vertices
    std::list<Vertice*>::iterator it = vertice.begin();
    while (it != vertice.end()){
            
        resultado << "V:" << (*it)->id << " - ";
        for(auto const &i: (*it)->aresta){
            resultado << i->toString();
        }
        resultado << std::endl;
        ++it;
    }   
    return resultado.str();

}

//ATUALEMNTE NAO FUNCIONA, VOLTAR AQUI DEPOIS
/*
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
            
            //    TODO: isso vai ter que ser feito de outra maneira, apagar
            //    em ambos os vertices somente (como a cima)?
            
            free(aresta[i]);
            aresta.erase(aresta.begin() + i);
            return true;
            tamanho--;
        }
    }
    std::cerr << "Nao foi possivel remover a aresta: nao existe!" << std::endl;
    return false;
}
*/

// ----------------------------------------------------- TODO:

Vertice* Grafo::getVertice(unsigned int id){
    std::list<Vertice*>::iterator it = vertice.begin();
    // percorre os vertices ate encontrar por id
    while (it != vertice.end()){
        if ((*it)->id == id){
            return *it;
        }
        else
        {
            ++it;
        }
    }
    std::cerr << "[ERRO] - Vertice solicitado não existe" << std::endl;
    return nullptr;
}

// ------------------------------------------------------- TODO:

Aresta* Grafo::getAresta(unsigned int id_v1, unsigned int id_v2){
    // pega o primeiro vertice da aresta
    Vertice* v = getVertice(id_v1);
    std::list<Aresta*>::iterator it = v->aresta.begin();
    // percorre os vertices 
    while (it != v->aresta.end()){
        /* 
         caso nas arestas do primeiro vertice seja encontrada uma
         referencia para o segundo vertice essa aresta é retornada 
        */
        if ((*it)->vertice[0] == id_v2 || (*it)->vertice[1] == id_v2){
            return *it;
        }
        else
        {
            ++it;
        }
    }
    std::cerr << "[ERRO] - Aresta solicitada não existe!" << std::endl;
    return nullptr;
}

Aresta* Grafo::getAresta(unsigned int id){  
    std::list<Vertice*>::iterator it = vertice.begin();
    // percorre a lista de vertices
    while (it != vertice.end()){
        if (!(*it)->aresta.empty()){
            std::list<Aresta*>::iterator ita = (*it)->aresta.begin();
            //percorre as arestas de cada vertice
            while (it != vertice.end()){
                // se o id ainda não foi listado adiciona o id a lista de ids e a aresta a lista de arestas
                if((*ita)->id == id){
                    return *ita;
                }
                ++ita;
            }
            ++it;
        }
        else
        {
            ++it;
        }
    }
    std::cerr << "[ERRO] - Aresta solicitada não existe!" << std::endl;
    return nullptr;
}

unsigned int Grafo::getOrdem(){
    return ordem;
}
unsigned int Grafo::getTamanho(){
    return tamanho;
}

std::list<Vertice*> Grafo::vertices(){
    return vertice;
}
std::list<Aresta*> Grafo::arestas(){
    // instancia uma lista que armazenara as referencias para as arestas do grafo
    std::list<Aresta*> lista_final;
    // instancia um vector para armazenar os id de arestas ja vsitadas
    std::vector<unsigned int> ids;     
    std::list<Vertice*>::iterator it = vertice.begin();
    // percorre a lista de vertices
    while (it != vertice.end()){
        if (!(*it)->aresta.empty()){
            std::list<Aresta*>::iterator ita = (*it)->aresta.begin();
            //percorre as arestas de cada vertice
            while (it != vertice.end()){
                // se o id ainda não foi listado adiciona o id a lista de ids e a aresta a lista de arestas
                if(!(std::find(ids.begin(), ids.end(), (*ita)->id) != ids.end())){
                    ids.push_back((*ita)->id);
                    lista_final.push_back(*ita);
                }
                ++ita;
            }
            ++it;
        }
        else
        {
            ++it;
        }
    }
    return lista_final;
}

std::list<Vertice*> Grafo::adj(Vertice* v){
    // instancia a lista dos vertices adjacentes
    std::list<Vertice*> lista_final;
    std::list<Aresta*>::iterator it = v->aresta.begin();
    // percorre as arestas dos do vertice
    while (it != v->aresta.end()){
        /* 
         caso o vertice adjacente seja o primero da aresta ele
         é retornado, se não for então deve ser o segundo
        */
        if((*it)->vertice[0] != v->id){
            lista_final.push_back(getVertice((*it)->vertice[0]));
            ++it;
        }
        else{
            lista_final.push_back(getVertice((*it)->vertice[1]));
            ++it;
        }
    }
    return lista_final;
}

unsigned int Grafo::grau(Vertice* v){
    return v->aresta.size();
}

std::list<Aresta*> Grafo::arestas(Vertice * v){
    return v->aresta;
}

Vertice* Grafo::oposto(Vertice* v, Aresta* a){
    if(a->vertice[0] == v->id){
        return getVertice(a->vertice[1]);
    }
    else if(a->vertice[1] == v->id){
        return getVertice(a->vertice[0]);
    }
    else{
        std::cerr << "[ERRO] - Aresta solicidatada não incide no vertice selecionado" << std::endl;
        return nullptr;
    }
}

unsigned int* Grafo::verticesA(Aresta * a){
    return a->vertice;
}

tree<unsigned int> Grafo::DFS(){
    //see : https://github.com/kpeeters/tree.hh/blob/master/src/tree_example.cc
    tree<unsigned int> av;
    tree<unsigned int>::iterator root, atual;
    unsigned int tempo = 0;
    root = av.begin();
    std::list<Vertice*>::iterator it = vertice.begin();
    // percorre a lista de vertices e as defini como brancas
    while (it != vertice.end()){
        (*it)->status = 0;
        ++it;
    }
    // percorre novamente aplicando o DFS_VISIT
    it = vertice.begin();
    while (it != vertice.end()){
        if((*it)->status == 0){
            std::cout << "A" << std::endl;
            atual = av.insert(root, (*it)->id);
            DFS_VISIT(av, tempo, *(*it), atual);
        }
        ++it;
    }
    return av;
}

void Grafo::DFS_VISIT(tree<unsigned int> &t, unsigned int &tempo, Vertice &v, tree<unsigned int>::iterator pai){
    std::cout << "abriu" << v.id<< std::endl;
    tree<unsigned int>::iterator atual;
    v.status = 1;
    tempo++;
    v.aberto = tempo;

    std::list<Vertice*> adj_v = adj(&v);
    std::list<Vertice*>::iterator it = adj_v.begin();

    // percorre os vertices adjacentes
    while(it != adj_v.end()){
        std::cout << "Status de " << (*it)->id << "=" << (*it)->status << std::endl;
        if((*it)->status == 0){
            std::cout << "A" << std::endl;
            atual=t.append_child(pai, (*it)->id);
            DFS_VISIT(t, tempo, *(*it), atual);
        }
        ++it;
    }
    std::cout << "fechou" << v.id << std::endl;
    // fecha o vertice
    v.status = 2;
    tempo++;
    v.fechado = tempo;
}