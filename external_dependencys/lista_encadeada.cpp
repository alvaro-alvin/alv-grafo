#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

namespace alv{

    template <typename T>
    class Lista {
        public:

        //estrutura do nó
        typedef struct Temp
        {
            T info;
            struct Temp *prox;
        }NO;

        NO *inicio;

        int tam;

        //inicia uma lista vazia
        Lista();

        //adiciona um dado ao inicio da lisata (0 = erro, 1=sucesso)
        int adiciona_inicio(T dado);

        //remove o primiero elemento da lista
        int remove_inicio();

        //adiciona no final da lista
        int adiciona_final(T dado);

        //adiciona no final da lista
        int remove_final();

        //adiciona em uma posicao
        int adiciona_meio(int pos, T dado);

        //remove em uma posicao
        int remove_meio(int pos);

        //adiciona um numero em sua devia posição na lista
        int adiciona_ordem(T dado);

        //imprime a lista
        void imprime();

        std::string to_string();
    };

    template <typename T>
    Lista<T>::Lista(){
        inicio = NULL;
        tam = 0;
    }

    template <typename T>
    int Lista<T>::adiciona_inicio(T dado){
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
        //se ja houver um nó inicial, ele virara o segundo e o novo será o inicial
        else{
            novo->prox = inicio;
            inicio = novo;

        }
        tam++;
        return 1;
    }
    template <typename T>
    int Lista<T>::remove_inicio(){
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

    template <typename T>
    int Lista<T>::adiciona_final(T dado){
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

    template <typename T>
    int Lista<T>::remove_final(){
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

    template <typename T>
    int Lista<T>::adiciona_meio(int pos, T dado){
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

    template <typename T>
    int Lista<T>::remove_meio(int pos){
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

    template <typename T>
    int Lista<T>::adiciona_ordem(T dado){
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

    template <typename T>
    std::string Lista<T>::to_string(){
        NO *ptr;
        std::ostringstream resultado;
        //caso a lista esteja vazia
        if(inicio == NULL){
            resultado << "nothing"
            return;
        }
        //caso não
        ptr = inicio;
        while(ptr != NULL){
            resultado << "[" << ptr->info << "] ";
            ptr = ptr->prox;
        }
        return resultado;
    }
}

// Class test
/*
int main(){
    alv::Lista<float>* lista_e_1 = new alv::Lista<float>();

    
    lista_e_1->adiciona_final(1.6);
    lista_e_1->adiciona_final(4.6);
    lista_e_1->adiciona_final(8.5);
    printf("LISTA ENCADEADA SIMPLES:\n");
    printf("lista encadeada criada:\n");
    lista_e_1->imprime();
    
    lista_e_1->adiciona_final(10.1);
    printf("adicionado o valor 10 ao final da lista:\n");
    lista_e_1->imprime();
    lista_e_1->adiciona_inicio(0.0);
    printf("adicionado o valor 0 ao inicio da lista:\n");
    lista_e_1->imprime();
    lista_e_1->adiciona_meio(2, 3.5);
    printf("adicionado o valor 3 na posição 2 (0, 1, 2, ..., (tamanho -1)) da lista:\n");
    lista_e_1->imprime();
    lista_e_1->adiciona_ordem(6.2);
    printf("adicionado o valor 6 em seu devido lugar em oredem crescente:\n");
    lista_e_1->imprime();
    
    return 0;
    }
    */
