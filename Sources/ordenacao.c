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

void QuickSort_Insercao(Dados *dados, int N, int m){
    Ordenacao_Insercao(dados, 0, N - 1, m);
}

void Ordenacao_Insercao(Dados *dados, int Esq, int Dir, int m){
    int i, j;
    if(Dir - Esq <= m){
        int l, r, aux;
        for(l = Esq; l <= Dir; l++){
            aux = dados->vetor[l];
            r = l - 1;
            while ((r >= 0) && (aux < dados->vetor[r])){
                dados->vetor[r + 1] = dados->vetor[r];
                r--;
            }
            dados->vetor[r+1] = aux;
        }
    }
    else{
        Particao_Insercao(dados , Esq, Dir, &i, &j, m);
        if (Esq < j){
            Ordenacao_Insercao(dados, Esq, j, m);
        }
        if (i < Dir){
            Ordenacao_Insercao(dados, i, Dir, m);
        }
    }
}

void Particao_Insercao(Dados *dados, int Esq, int Dir,int *i, int *j, int m){
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

//Algoritmo Quicksort Empilha Inteligente
void QuickSort_EmpilhaInteligente(Dados *dados, int N){
    Ordenacao_EmpilhaInteligente(dados, 0, N - 1);
}

void Ordenacao_EmpilhaInteligente(Dados *dados, int Esq, int Dir){
    int i, j;
    Particao_EmpilhaInteligente(dados , Esq, Dir, &i, &j);
    if((j - Esq + 1) <= ( Dir - j + 1)){
        if(Esq < j){
            Ordenacao_EmpilhaInteligente(dados, Esq, j);
        }
        if(i < Dir){
            Ordenacao_EmpilhaInteligente(dados, i, Dir);
        }
    }
    else{
        if(i < Dir){
            Ordenacao_EmpilhaInteligente(dados, i, Dir);
        }
        if(Esq < j){
            Ordenacao_EmpilhaInteligente(dados, Esq, j);
        }
    }
}

void Particao_EmpilhaInteligente(Dados *dados, int Esq, int Dir,int *i, int *j){
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

//Algoritmo Quicksort Iterativo
