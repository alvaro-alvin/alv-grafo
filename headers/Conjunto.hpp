#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTI_H_INCLUDED

#include <iostream>
#include <stdlib.h>

template <typename T>
class Conjunto { 
    public:
        Conjunto(int tamanho);
        ~Conjunto();

        typedef struct Temp
        {
            T dado;
            T id;
            int rank;
        }Set;

        T encontra(T elemento);
        void novoSet(T dado);
        void unir(T dado_1, T dado_2);
        
    private:

    Set* c;
    int count = 0;

    void link(T dado_1, T dado_2);
    Set* getSet(T dado);
 
};

//#include "../headers/Conjunto.hpp"
template <typename T>
Conjunto<T>::Conjunto(int tamanho)
{   
    count = 0;
    c = (Set*) malloc(tamanho * sizeof(Set));
}

template <typename T>
Conjunto<T>::~Conjunto()
{
    free(c);
}

template <typename T>
void Conjunto<T>::novoSet(T dado)
{   
    Set novo_set = {dado, dado, 0};
    c[count] = novo_set;
    count++;
}

template <typename T>
typename Conjunto<T>::Set* Conjunto<T>::getSet(T dado){
    
    for(int i = 0; i<count; i++){
        if(dado == c[i].dado)
            return &c[i];
    }
        return nullptr;
}

template <typename T>
T Conjunto<T>::encontra(T elemento){
    Set* set = getSet(elemento);
    if(set->dado != set->id)
        set->id = encontra(set->id);
    return set->id;
    }

template <typename T>
void Conjunto<T>::link(T dado_1, T dado_2){
    Set* set1 = getSet(dado_1);
    Set* set2 = getSet(dado_2);
    if(set1->rank > set2->rank){
        set2->id = set1->dado;
    }
    else{
        set1->id = set2->dado;
            if(set1->rank == set2->rank){
                set2->rank++;
            }
    }
}

template <typename T>
void Conjunto<T>::unir(T dado_1, T dado_2){
    link(encontra(dado_1), encontra(dado_2));
}

#endif