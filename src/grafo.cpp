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

bool Grafo::addVertice(int id){ // -------------------------------------- OK
    for(auto it= vertice.begin(); it!=vertice.end(); it++){
        if((*it)->id == id){
            std::cout << "id ja existente impissível adicionar vertice";
            return false;
        }
    }
    //estancia nova vertice com id recebido
    Vertice * v = new Vertice(id);
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

bool Grafo::addAresta(unsigned int v1, unsigned int v2, int custo){ //--------------------- OK
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
        Aresta * a = new Aresta(v1, v2, custo);
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
    //std::cout << "Aresta solicitada nao existe, retornando nulo" << std::endl;
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
            while (ita != (*it)->aresta.end()){
                // se o id ainda não foi listado adiciona o id a lista de ids e a aresta a lista de arestas
                    if(!(std::find(ids.begin(), ids.end(), (*ita)->id) != ids.end())){
                        ids.push_back((*ita)->id);
                        //std::cout << (*ita)->vertice[0] << "--" << (*ita)->vertice[1] << "  custo: " << (*ita)->custo << std::endl; 
                        lista_final.push_back(*ita);
                    }
                    ++ita;
            }
                
        }
            ++it;
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

std::vector<std::list<std::pair<unsigned int, unsigned int>>> Grafo::DFS(){
    std::vector<std::list<std::pair<unsigned int, unsigned int>>> v_r_total;
    unsigned int tempo = 0;
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
            std::list<std::pair<unsigned int, unsigned int>> v_r;
            DFS_VISIT(v_r, tempo, *(*it));
            v_r_total.push_back(v_r);
        }
        ++it;
    }
    return v_r_total;
}

void Grafo::DFS_VISIT(std::list<std::pair<unsigned int, unsigned int>> &v_r, unsigned int &tempo, Vertice &v){
    //std::cout << "abriu: " << v.id<< std::endl;
    v.status = 1;
    tempo++;
    v.aberto = tempo;

    std::list<Vertice*> adj_v = adj(&v);
    std::list<Vertice*>::iterator it = adj_v.begin();

    // percorre os vertices adjacentes
    while(it != adj_v.end()){
        //std::cout << "Status de " << (*it)->id << "=" << (*it)->status << std::endl ;
        if((*it)->status == 0){
            //std::cout << "A" << std::endl;
            std::pair<unsigned int, unsigned int> pai_filho;
            pai_filho.first = v.id;
            pai_filho.second = ((*it)->id);
            v_r.push_back(pai_filho);
            DFS_VISIT(v_r, tempo, *(*it));
        }
        ++it;
    }
    //std::cout << "fechou: " << v.id << std::endl;
    // fecha o vertice
    v.status = 2;
    tempo++;
    v.fechado = tempo;
}

int** Grafo::Floyd(){
    //gerar matriz de adjacencia
    std::list<Vertice*>::iterator it_i;
    std::list<Vertice*>::iterator it_j;
    it_i = vertice.begin();
    // inicializa matriz de adjacencia
    int **m_adj;
    m_adj = (int**) malloc (ordem * sizeof (int *));
    for (int i=0; i<ordem; i++){
        m_adj[i] = (int*) malloc(ordem * sizeof(int));
    }

    // gera matriz de adjacencia
    for(int i = 0; i<ordem; i++){
        it_j = vertice.begin();
        for(int j = 0; j<ordem; j++){
            //std::cout << i + 1 << "-" << j + 1 << " ";
            if(i == j){
                m_adj[i][j] = 0;
                //std::cout << "0" << std::endl;
            }
            else{
                //std::cout << "confirmando:" << (*it_i)->id << "e" << (*it_j)->id << "  ";
                Aresta* a = getAresta((*it_i)->id, (*it_j)->id);
                
                if(a == nullptr){
                    m_adj[i][j] = INT16_MAX;
                    //std::cout << "nulo" << std::endl;
                }
                else{
                    m_adj[i][j] = a->custo;
                    //std::cout << "custo" << std::endl;
                }
            }
            it_j++;
        }
        it_i++;
    }
    //printa matriz de adjacencia
    std::cout << "Matriz de adjacencia:" << std:: endl;
    for(int i = 0; i<ordem; i++){
        std::cout << "|";
        for(int j = 0; j<ordem; j++){
            if( m_adj[i][j] == INT16_MAX)
                std::cout << " n ";            
            else
                std::cout << " " << m_adj[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }

    std::cout << std::endl << "===============================" << std::endl << std::endl;
    

    // inicializa matriz de floyd
    int *** m_f;
    m_f = (int***) malloc(ordem * sizeof(int**));
    for (int i=0; i<ordem; i++){
        m_f[i] = (int**) malloc(ordem * sizeof(int*));
        for(int j = 0; j<ordem; j++)
            m_f[i][j] = (int*) malloc(ordem * sizeof(int));
    }

    // inicia o algoritimo de Floyd
    for(int i = 0; i<ordem; i++){
        for(int j = 0; j<ordem; j++){
            m_f[i][j][0] = m_adj[i][j]; 
        }
    }

    for(int k = 1; k<ordem; k++){
        for(int i = 0; i<ordem; i++){
            for(int j = 0; j<ordem; j++){
                if(m_f[i][j][k-1] <= (m_f[i][k][k-1] + m_f[k][j][k-1]))
                    m_f[i][j][k] = m_f[i][j][k-1];    
                else
                    m_f[i][j][k] = m_f[i][k][k-1] + m_f[k][j][k-1];
            }
        }
    }

    // sobrescreve a matriz de adjacencia com os custos mínimos para o retorno
    for(int i = 0; i<ordem; i++){
        for(int j = 0; j<ordem; j++){
            m_adj[i][j] = m_f[i][j][ordem-1];
        }
    }

    return m_adj;
}


std::list<std::pair<unsigned int, unsigned int>> Grafo::BFS(int inicial){
    std::list<std::pair<unsigned int, unsigned int>> v_r;
    unsigned int tempo = 0;
    // inicia o grafo.
    std::list<Vertice*>::iterator it = vertice.begin();
    // percorre a lista de vertices e as defini como brancas
    while (it != vertice.end()){
        (*it)->status = 0;
        ++it;
    }
    // fila de vertices
    std::queue<Vertice*> Q;
    Vertice* v_inicial = getVertice(inicial);
    Q.push(v_inicial);
    Vertice* v;
    v->aberto = tempo;
    v->status = 1;
    while (!Q.empty()){
        //std::cout << "nao esta vazio" << std::endl;

        v = Q.back();

        Q.pop();
        std::list<Vertice*> adj_v = adj(v);
        std::list<Vertice*>::iterator it = adj_v.begin();

        while(it != adj_v.end()){
            if((*it)->status == 0){
                //std::cout << "A" << std::endl;
                tempo++;
                std::pair<unsigned int, unsigned int> pai_filho;
                Q.push((*it));
                //std::cout << "adicionado " << (*it)->id << " a fila" << std::endl;
                (*it)->aberto = v->aberto + 1;
                (*it)->status = 1;
                pai_filho.first = v->id;
                pai_filho.second = ((*it)->id);
                v_r.push_back(pai_filho);
            }
            ++it;
        }

        v->status = 2;
        v->fechado = tempo;
    }
    return v_r;
}

bool Grafo::compareArestasCost(const Aresta* a1, const Aresta* a2){
    if(a1->custo< a2->custo)
        return true;
    else
        return false;
}

Grafo Grafo::kruskal(){
    //vetor de rotacao
    Grafo g;

    std::list<Vertice*>::iterator it = vertice.begin();
    // floresta
    Conjunto<int> c(ordem);
    //fila de arestas ordenadas 
    std::queue<Aresta*> q;
    // lista de arestas
    std::list<Aresta*> a = arestas();
    // percorre a lista de vertices e cria os conjuntos e o novo grafo
    while (it != vertice.end()){
        c.novoSet((*it)->id);
        g.addVertice((*it)->id);
        ++it;

    }
    //ordena de forma crescente (não decrescente) a lista de arestas
    a.sort(compareArestasCost);
    
    Aresta* aresta;
    while (!a.empty())
    {
        aresta = (*a.begin());
        a.pop_front();
        if(c.encontra(aresta->vertice[0]) != c.encontra(aresta->vertice[1])){
            g.addAresta(aresta->vertice[0], aresta->vertice[1], aresta->custo);
            c.unir(aresta->vertice[0], aresta->vertice[1]);
        }
    }
    return g;
}