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

//Algoritmo QuickSort Mediana
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

void Particao_Mediana(Dados *dados, int Esq, int Dir, int *i, int *j, int k){
    int pivo, aux;
    *i = Esq;
    *j = Dir;
    pivo = escolha_pivor(dados, Esq, Dir, k);
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

int escolha_pivor(Dados *dados, int Esq, int Dir, int k){
    int vetor_aux[k];
    int i, j, aux;
    for(i = 0; i < k; i++){
        aux =  Esq + (rand() % (Dir - Esq + 1));
        vetor_aux[i] = dados->vetor[aux];
        printf("%d ", aux);
    }
    printf("\n");
    for(i = 1; i < k; i++){
        aux = vetor_aux[i];
        j = i - 1;
        while ((j >= 0) && (aux < vetor_aux[j])){
            vetor_aux[j + 1] = vetor_aux[j];
            j--;
        }
        vetor_aux[j+1] = aux;
    }
    return (vetor_aux[k / 2]);
}

//Algoritmo QuickSort Insercao

