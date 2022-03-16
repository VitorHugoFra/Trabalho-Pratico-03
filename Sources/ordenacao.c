#include "../Libs/ordenacao.h"

// Algoritmo QuickSort Recursivo
void QuickSort_Recursivo(Dados *dados, int N){
    Ordenacao_Recursivo(dados, 0, N - 1);
}

void Ordenacao_Recursivo(Dados *dados, int Esq, int Dir){ 
    int i, j;
    Particao_Recursivo(dados , Esq, Dir, &i, &j);
    if (Esq < j){
        Ordenacao_Recursivo(dados, Esq, j);
    }
    if (i < Dir){
        Ordenacao_Recursivo(dados, i, Dir);
    }
}

void Particao_Recursivo(Dados *dados, int Esq, int Dir,int *i, int *j){
    int pivo, aux;
    *i = Esq;
    *j = Dir;
    pivo = dados->vetor[(*i + *j)/2]; /* obtem o pivo  */
    do{ 
        while (pivo > dados->vetor[*i]){
            (*i)++;
        }
        while (pivo < dados->vetor[*j]){
            (*j)--;
        }
        if (*i <= *j){ 
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}

//Algoritmo QuickSort Mediana(k)
void QuickSort_Mediana(Dados *dados, int N, int k){
    Ordenacao_Mediana(dados, 0, N - 1, k);
}

void Ordenacao_Mediana(Dados *dados, int Esq, int Dir, int k){ 
    int i, j;
    Particao_Mediana(dados , Esq, Dir, &i, &j, k);
    if (Esq < j){
        Ordenacao_Mediana(dados, Esq, j, k);
    }
    if (i < Dir){
        Ordenacao_Mediana(dados, i, Dir, k);
    }
}

void Particao_Mediana(Dados *dados, int Esq, int Dir,int *i, int *j, int k){
    int pivo, aux;
    *i = Esq;
    *j = Dir;
    if(k == 3){
        pivo_mediana3(dados, Esq, Dir, &pivo, k);
    }
    else if(k == 5){
        pivo_mediana5(dados, Esq, Dir, &pivo, k);
    }
    //pivo = dados->vetor[(*i + *j)/2]; /* obtem o pivo  */
    do{ 
        while (pivo > dados->vetor[*i]){
            (*i)++;
        }
        while (pivo < dados->vetor[*j]){
            (*j)--;
        }
        if (*i <= *j){ 
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}

void pivo_mediana3(Dados *dados, int Esq, int Dir, int *pivo, int k){
    int a, b, c;
    a = Esq + (rand() % (Dir - Esq +1));
    b = Esq + (rand() % (Dir - Esq +1));
    c = Esq + (rand() % (Dir - Esq +1));
    if(a < b) {
        if (b < c){
            (*pivo) = b;
        }
        else {
            if(a < c) {
                (*pivo) = c;
            }
            else{
                (*pivo) = a;
            }
        }
    }
    else{
        if(c < b) {
            (*pivo) = b;
        }
        else{
            if(c < a) {
                (*pivo) = c;
            }
            else {
                (*pivo) = a;
            }
        }
    }
}
void pivo_mediana5(Dados *dados, int Esq, int Dir, int *pivo, int k){
    
}

