#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Lista_encadeada {
    public:

    //estrutura do nó
    typedef struct Temp
    {
        int info;
        struct Temp *prox;
    }NO;

    NO *inicio;

    int tam;

    //inicia uma lista vazia
    Lista_encadeada();

    //adiciona um dado ao inicio da lisata (0 = erro, 1=sucesso)
    int adiciona_inicio(int dado);

    //remove o primiero elemento da lista
    int remove_inicio();

    //adiciona no final da lista
    int adiciona_final(int dado);

    //adiciona no final da lista
    int remove_final();

    //adiciona em uma posicao
    int adiciona_meio(int pos, int dado);

    //remove em uma posicao
    int remove_meio(int pos);

    //adiciona um numero em sua devia posição na lista
    int adiciona_ordem(int dado);

    //imprime a lista
    void imprime();
};

Lista_encadeada::Lista_encadeada(){
    inicio = NULL;
    tam = 0;
}

int Lista_encadeada::adiciona_inicio(int dado){
    NO *novo;
    novo = (NO *) malloc(sizeof(NO));
    if (novo == NULL){
        printf("Erro na alocação de memória");
        return 0;
    }
    //se for o primeiro a ser adiconado apontará para NULL
    novo->info = dado;
    novo->prox = NULL;

    if (inicio == NULL){
        inicio = novo;
    }
    //se ja ouver um nó inicial, ele virara o segundo e o novo será o inicial
    else{
        novo->prox = inicio;
        inicio = novo;

    }
    tam++;
    return 1;
}

int Lista_encadeada::remove_inicio(){
    NO *ptr;
    if (inicio == NULL){
        return 0; //lista já vazia
    }
    // o segundo vira o inicial e então o antigo inicial é apagado
    else{
        ptr = inicio;
        inicio = inicio->prox;
        free(ptr);
        tam--;
        return 1;
    }
}

int Lista_encadeada::adiciona_final(int dado){
    NO *novo;
    novo = (NO *) malloc(sizeof(NO));
    if (novo == NULL){
        printf("Erro na alocação de memória");
        return 0;
    }

    novo->info = dado;
    novo->prox = NULL;

    //se estiver vazia adiciona no inicio
    if(inicio == NULL){
        inicio = novo;
    }
    //se não, percorre até o final e entao adiciona
    else{
        NO *ptr;
        ptr = inicio;
        while(ptr->prox != NULL){
            ptr = ptr->prox;
        }
        ptr->prox = novo;
    }
    tam++;
    return 1;
}

int Lista_encadeada::remove_final(){
    NO *ptr;
    if (inicio == NULL){
        return 0; //lista já vazia
    }
    // o segundo vira o inicial e então o antigo inicial é apagado
    else{
        NO *ptr_ante;
        ptr = inicio;
        //percorre a lista até o final gaurdado o Nó anterior
        while(ptr->prox !=NULL){
            ptr_ante = ptr;
            ptr = ptr->prox;            
        }

        ptr_ante->prox = NULL;
        free(ptr);
        tam--;
        return 1;
    }
}

int Lista_encadeada::adiciona_meio(int pos, int dado){
    if(pos == 0){
        adiciona_inicio(dado);
        return 1;
    }
    if(pos > tam){
        printf("posicao inexistente, erro ao adicionar!\n");
        return 0;
    }
    if(pos == tam){
        adiciona_final(dado);
        return 1;
    }
    NO *novo;
    NO *ptr;
    int i;
    novo = (NO *) malloc(sizeof(NO));
    if (novo == NULL){
        printf("Erro na alocação de memória");
        return 0;
    }

    novo->info = dado;
    novo->prox = NULL;

    if(inicio == NULL){
        inicio = novo;
    }
    else{
        ptr = inicio;
        NO *ptr_ante;
        for(i = 0; i < pos; i++){
            if(ptr == NULL){
                printf("erro ao adicionar, posicao inexistente! Numero de nos: %d\n", i);
                return 0;
            }
            ptr_ante = ptr;
            ptr = ptr->prox;
            
        }
        ptr_ante->prox = novo;
        novo->prox = ptr;
        
    }
    tam++;
    return 1;
}

int Lista_encadeada::remove_meio(int pos){
    if(pos == 0){
        remove_inicio();
        return 1;
    }
    if(pos >= tam){
        printf("posicao inexistente, falha ao adicionar!\n");
        return 0;
    }
    NO *ptr;
    int i;

    if(inicio == NULL){
        printf("lista ja vazia!\n");
        return 0;
    }
    else{
        ptr = inicio;
        NO *ptr_ante;
        for(i = 0; i < pos; i++){
            if(ptr == NULL){
                printf("erro ao remover, posicao inexistente! Numero de nos: %d\n", i);
                return 0;
            }
            ptr_ante = ptr;
            ptr = ptr->prox;
            
        }

        ptr_ante->prox = ptr->prox;
        free(ptr);
    }
    tam--;
    return 1;
}

int Lista_encadeada::adiciona_ordem(int dado){
    if((inicio == NULL) || (dado <= inicio->info)){
        adiciona_inicio(dado);
        return 1;
    }

    NO *novo;
    NO *ptr;
    int i;

    novo = (NO *) malloc(sizeof(NO));
    if (novo == NULL){
        printf("Erro na alocação de memória");
        return 0;
    }

    novo->info = dado;
    novo->prox = NULL;

    ptr = inicio;
    NO *ptr_ante;
    //percorre a lista até que ache um numero maior que o novo;
    for(i = 0; i < tam && dado > ptr->info; i++){
        //se chegar ao final da lista adicona ao final
        if(i == tam -1){
            ptr->prox = novo;
                tam++;
                return 1;
        }
        ptr_ante = ptr;
        ptr = ptr->prox;
        
    }
    ptr_ante->prox = novo;
    novo->prox = ptr;
    tam++;
    return 1; 
}

void Lista_encadeada::imprime(){
    NO *ptr;

    //caso a lista esteja vazia
    if(inicio == NULL){
        printf("Lista vazia!\n");
        return;
    }
    //caso não
    ptr = inicio;
    while(ptr != NULL){
        printf("[%d]->", ptr->info);
        ptr = ptr->prox;
    }
    printf("NULL\n");

}



class Lista_duplamente_encadeada {
    public:

    //estrutura do nó
    typedef struct Temp
    {
        int info;
        struct Temp *prox;
        struct Temp *ante;
    }NO;

    NO *inicio;

    int tam;

    //inicia uma lista vazia
    Lista_duplamente_encadeada();

    //adiciona um dado ao inicio da lisata (0 = erro, 1=sucesso)
    int adiciona_inicio(int dado);

    //remove o primiero elemento da lista
    int remove_inicio();

    //adiciona no final da lista
    int adiciona_final(int dado);

    //remove no final da lista
    int remove_final();

    //adiciona em uma posicao 
    int adiciona_meio(int pos, int dado);

    //remove o nó de uma posição
    int remove_meio(int pos);

    //adiciona um numero em sua devia posição na lista
    int adiciona_ordem(int dado);

    //imprime a lista
    void imprime();

    //imprime a lista com todas as relações separadas
    void imprime_mais();

};

Lista_duplamente_encadeada::Lista_duplamente_encadeada(){
    inicio = NULL;
    tam = 0;
}

int Lista_duplamente_encadeada::adiciona_inicio(int dado){
    NO *novo;
    novo = (NO *) malloc(sizeof(NO));
    if (novo == NULL){
        printf("Erro na alocação de memória");
        return 0;
    }
    //se for o primeiro a ser adiconado apontará para NULL
    novo->info = dado;
    novo->prox = NULL;
    novo->ante = NULL;

    if (inicio == NULL){
        inicio = novo;
    }
    //se ja ouver um nó inicial, ele virara o segundo e o novo seráo inicial e seu anterior sera o novo
    else{

        novo->prox = inicio;
        inicio->ante = novo;
        inicio = novo;

    }
    tam++;
    return 1;
}

int Lista_duplamente_encadeada::remove_inicio(){
    NO *ptr;
    if (inicio == NULL){
        return 0; //lista já vazia
    }
    // o segundo vira o inicial e então o antigo inicial é apagado
    else{
        ptr = inicio;
        inicio = inicio->prox;
        inicio->ante = NULL;
        free(ptr);
        tam--;
        return 1;
    }
}

int Lista_duplamente_encadeada::adiciona_final(int dado){
    NO *novo;
    novo = (NO *) malloc(sizeof(NO));
    if (novo == NULL){
        printf("Erro na alocação de memória");
        return 0;
    }

    novo->info = dado;
    novo->prox = NULL;
    

    //se estiver vazia adiciona no inicio
    if(inicio == NULL){
        novo->ante = NULL;
        inicio = novo;
    }
    //se não, percorre até o final e entao adiciona
    else{
        NO *ptr;
        ptr = inicio;
        while(ptr->prox != NULL){
            ptr = ptr->prox;
        }
        ptr->prox = novo;
        novo->ante = ptr;
    }
    tam++;
    return 1;
}

int Lista_duplamente_encadeada::remove_final(){
    NO *ptr;
    if (inicio == NULL){
        return 0; //lista já vazia
    }
    // o segundo vira o inicial e então o antigo inicial é apagado
    else{
        ptr = inicio;
        //percorre a lista até o final
        while(ptr->prox !=NULL){
            ptr = ptr->prox;            
        }
        //altera o no anteriror e exclui o ultimo
        ptr->ante->prox = NULL;
        free(ptr);
        tam--;
        return 1;
    }
}

int Lista_duplamente_encadeada::adiciona_meio(int pos, int dado){
    if(pos == 0){
        adiciona_inicio(dado);
        return 1;
    }
    if(pos > tam){
        printf("posicao inexistente, erro ao adicionar!\n");
        return 0;
    }
    if(pos == tam ){
        adiciona_final(dado);
        return 1;
    }

    NO *novo;
    NO *ptr;
    int i;

    novo = (NO *) malloc(sizeof(NO));
    if (novo == NULL){
        printf("Erro na alocação de memória");
        return 0;
    }

    novo->info = dado;
    novo->prox = NULL;

    if(inicio == NULL){
        novo->ante = NULL;
        inicio = novo;
    }
    else{
        ptr = inicio;
        for(i = 0; i < pos; i++){
            ptr = ptr->prox;
            
        }
        ptr->ante->prox = novo;
        novo->ante = ptr->ante;
        novo->prox = ptr;
        ptr->ante = novo;
    }
    tam++;
    return 1;
}

int Lista_duplamente_encadeada::remove_meio(int pos){
    if(pos == 0){
        remove_inicio();
        return 1;
    }
    if(pos >= tam){
        printf("posicao inexistente, falha ao adicionar!\n");
        return 0;
    }
    NO *ptr;
    int i;

    if(inicio == NULL){
        printf("lista ja vazia!\n");
        return 0;
    }
    else{
        ptr = inicio;
        for(i = 0; i < pos; i++){
            if(ptr == NULL){
                printf("erro ao remover, posicao inexistente! Numero de nos: %d\n", i);
                return 0;
            }
            ptr = ptr->prox;
            
        }
        ptr->ante->prox = ptr->prox;
        free(ptr);
    }
    tam--;
    return 1;
}

void Lista_duplamente_encadeada::imprime(){
    NO *ptr;

    //caso a lista esteja vazia
    if(inicio == NULL){
        printf("Lista vazia!\n");
        return;
    }
    //caso não
    ptr = inicio;
    printf("NULL");
    while(ptr != NULL){
        printf("<-[%d]->", ptr->info);
        ptr = ptr->prox;
    }
    printf("NULL\n");

}

int Lista_duplamente_encadeada::adiciona_ordem(int dado){
    if((inicio == NULL) || (dado <= inicio->info)){
        adiciona_inicio(dado);
        return 1;
    }

    NO *novo;
    NO *ptr;
    int i;

    novo = (NO *) malloc(sizeof(NO));
    if (novo == NULL){
        printf("Erro na alocação de memória");
        return 0;
    }

    novo->info = dado;
    novo->prox = NULL;

    ptr = inicio;
    //percorre a lista até que ache um numero maior que o novo;
    for(i = 0; i < tam && dado > ptr->info; i++){
        //se chegar ao final da lista adicona ao final
        if(i == tam -1){
            ptr->prox = novo;
            novo->ante = ptr;
                tam++;
                return 1;
        }
        ptr = ptr->prox;        
    }
    ptr->ante->prox = novo;
    novo->prox = ptr;
    novo->ante = ptr->ante;
    ptr->ante = novo;
    tam++;
    return 1; 
}

void Lista_duplamente_encadeada::imprime_mais(){
    NO *ptr;

    //caso a lista esteja vazia
    if(inicio == NULL){
        printf("Lista vazia!\n");
        return;
    }
    //caso não
    ptr = inicio;
    printf("\n");
    while(ptr != NULL){
        if(ptr->ante == NULL){
            printf("NULL");
        }
        else{
            printf("[%d]", ptr->ante->info);
        }
        printf("<-[%d]->", ptr->info);
        if(ptr->prox == NULL){
            printf("NULL\n");
        }
        else{
            printf("[%d]\n", ptr->prox->info);
        }
        ptr = ptr->prox;
    }

}



int main(){
    Lista_encadeada* lista_e_1 = new Lista_encadeada();
    Lista_duplamente_encadeada* lista_de_1 = new Lista_duplamente_encadeada();

    
    lista_e_1->adiciona_final(1);
    lista_e_1->adiciona_final(4);
    lista_e_1->adiciona_final(8);
    printf("LISTA ENCADEADA SIMPLES:\n");
    printf("lista encadeada criada:\n");
    lista_e_1->imprime();
    
    lista_e_1->adiciona_final(10);
    printf("adicionado o valor 10 ao final da lista:\n");
    lista_e_1->imprime();
    lista_e_1->adiciona_inicio(0);
    printf("adicionado o valor 0 ao inicio da lista:\n");
    lista_e_1->imprime();
    lista_e_1->adiciona_meio(2, 3);
    printf("adicionado o valor 3 na posição 2 (0, 1, 2, ..., (tamanho -1)) da lista:\n");
    lista_e_1->imprime();
    lista_e_1->adiciona_ordem(6);
    printf("adicionado o valor 6 em seu devido lugar em oredem crescente:\n");
    lista_e_1->imprime();

    //--------------------------------------------------------------------------------------------------

    lista_de_1->adiciona_final(1);
    lista_de_1->adiciona_final(4);
    lista_de_1->adiciona_final(8);
    printf("\n\nLISTA DUPLAMENTE ENCADEADA:\n");
    printf("lista duplamente encadeada criada:\n");
    lista_de_1->imprime();
    
    lista_de_1->adiciona_final(10);
    printf("adicionado o valor 10 ao final da lista:\n");
    lista_de_1->imprime();
    lista_de_1->adiciona_inicio(0);
    printf("adicionado o valor 0 ao inicio da lista:\n");
    lista_de_1->imprime();
    lista_de_1->adiciona_meio(2, 3);
    printf("adicionado o valor 3 na posição 2 (0, 1, 2, ..., (tamanho -1)) da lista:\n");
    lista_de_1->imprime();
    lista_de_1->adiciona_ordem(6);
    printf("adicionado o valor 6 em seu devido lugar em oredem crescente:\n");
    lista_de_1->imprime();
    printf("\nVizualização de todas conexões:");
    lista_de_1->imprime_mais();

    lista_e_1->~Lista_encadeada();
    lista_de_1->~Lista_duplamente_encadeada();
    return 1;
}