#include "../headers/Conjunto.hpp"
template <typename T>
Conjunto<T>::Conjunto()
{
    c = (Set*) malloc(0 * sizeof(Set));
}

template <typename T>
Conjunto<T>::~Conjunto()
{
    free(c);
}

template <typename T>
void Conjunto<T>::novoSet(T dado)
{
    c = (Set*) realloc(c, sizeof(c)/sizeof(Set) + 1* sizeof(Set));
    Set novo_set = {dado, dado, 0};
    c[sizeof(c)/sizeof(Set) - 1] = novo_set;
}

template <typename T>
typename Conjunto<T>::Set* Conjunto<T>::getSet(T dado){
    
    for(int i = 0; i<sizeof(c)/sizeof(Set); i++){
        if(dado = c[i].dado)
            return c[i];
    }
        return nullptr;
}

template <typename T>
T Conjunto<T>::encontra(T elemento){
    Set* set = getSet(elemento);
    if(elemento != set.id)
        set.id = encontra(set.id);
    return set.id;
    }

template <typename T>
void Conjunto<T>::link(T dado_1, T dado_2){
    Set* set1 = getSet(dado_1);
    Set* set2 = getSet(dado_2);
    if(set1.rank > set2.rank){
        set2.id = set1.dado;
    }
    else{
        set1.id = set2.dado;
            if(set1.rank == set2.rank){
                set2.rank++;
            }
    }
}

template <typename T>
void Conjunto<T>::unir(T dado_1, T dado_2){
    link(findSet(dado_1), findSet(dado_2));
}