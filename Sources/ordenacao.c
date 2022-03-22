#include "../Libs/ordenacao.h"

// Algoritmo QuickSort Recursivo
void QuickSort_Recursivo(Dados *dados, int N){
    Ordenacao_Recursivo(dados, 0, N - 1);
}

void Ordenacao_Recursivo(Dados *dados, int Esq, int Dir){ 
    int i, j;
    Particao_Recursivo(dados , Esq, Dir, &i, &j);
    dados->comparacoes ++;
    if (Esq < j){
        Ordenacao_Recursivo(dados, Esq, j);
    }
    dados->comparacoes ++;
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
        dados->comparacoes++;
        while (pivo > dados->vetor[*i]){
            dados->comparacoes++;
            (*i)++;
        }
        dados->comparacoes++;
        while (pivo < dados->vetor[*j]){
            dados->comparacoes++;
            (*j)--;
        }
        dados->comparacoes++;
        if (*i <= *j){ 
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            dados->movimentacoes++;
            (*i)++; 
            (*j)--;
        }
        dados->comparacoes++;
    } while (*i <= *j);
}

//Algoritmo QuickSort Mediana
void QuickSort_Mediana(Dados *dados, int N, int k){
    Ordenacao_Mediana(dados, 0, N - 1, k);
}

void Ordenacao_Mediana(Dados *dados, int Esq, int Dir, int k){ 
    int i, j;
    Particao_Mediana(dados , Esq, Dir, &i, &j, k);
    dados->comparacoes++;
    if (Esq < j){
        Ordenacao_Mediana(dados, Esq, j, k);
    }
    dados->comparacoes++;
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
        dados->comparacoes++;
        while (pivo > dados->vetor[*i]){
            (*i)++;
            dados->comparacoes++;
        }
        dados->comparacoes++;
        while (pivo < dados->vetor[*j]){
            (*j)--;
            dados->comparacoes++;
        }
        dados->comparacoes++;
        if (*i <= *j){ 
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            dados->movimentacoes++;
            (*i)++; 
            (*j)--;
        }
        dados->comparacoes++;
    } while (*i <= *j);
}


int escolha_pivor(Dados *dados, int Esq, int Dir, int k){
    int vetor_aux[k];
    int i, j, aux;
    for(i = 0; i < k; i++){
        aux =  Esq + (rand() % (Dir - Esq + 1));
        vetor_aux[i] = dados->vetor[aux];
    }
    for(i = 1; i < k; i++){
        aux = vetor_aux[i];
        j = i - 1;
        dados->comparacoes++;
        while ((j >= 0) && (aux < vetor_aux[j])){
            dados->movimentacoes++;
            vetor_aux[j + 1] = vetor_aux[j];
            j--;
            dados->comparacoes++;
        }
        dados->movimentacoes++;
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
    dados->comparacoes++;
    if(Dir - Esq + 1 <= m){
        int l, r, aux;
        for(l = Esq; l <= Dir; l++){
            aux = dados->vetor[l];
            r = l - 1;
            dados->comparacoes++;
            while ((r >= 0) && (aux < dados->vetor[r])){
                dados->movimentacoes++;
                dados->vetor[r + 1] = dados->vetor[r];
                r--;
                dados->comparacoes++;
            }
            dados->movimentacoes++;
            dados->vetor[r+1] = aux;
        }
    }
    else{
        Particao_Insercao(dados , Esq, Dir, &i, &j, m);
        dados->comparacoes++;
        if (Esq < j){
            Ordenacao_Insercao(dados, Esq, j, m);
        }
        dados->comparacoes++;
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
        dados->comparacoes++;
        while (pivo > dados->vetor[*i]){
            (*i)++;
            dados->comparacoes++;
        }
        dados->comparacoes++;
        while (pivo < dados->vetor[*j]){
            (*j)--;
            dados->comparacoes++;
        }
        dados->comparacoes++;
        if (*i <= *j){ 
            dados->movimentacoes++;
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            (*i)++; 
            (*j)--;
        }
        dados->comparacoes++;
    } while (*i <= *j);
}

//Algoritmo QuickSort Empilha Inteligente
void QuickSort_EmpilhaInteligente(Dados *dados, int N){
    Ordenacao_EmpilhaInteligente(dados, 0, N - 1);
}

void Ordenacao_EmpilhaInteligente(Dados *dados, int Esq, int Dir){
    int i, j;
    Particao_EmpilhaInteligente(dados , Esq, Dir, &i, &j);
    dados->comparacoes++;
    if((j - Esq + 1) <= ( Dir - j + 1)){
        dados->comparacoes++;
        if(Esq < j){
            Ordenacao_EmpilhaInteligente(dados, Esq, j);
        }
        dados->comparacoes++;
        if(i < Dir){
            Ordenacao_EmpilhaInteligente(dados, i, Dir);
        }
    }
    else{
        dados->comparacoes++;
        if(i < Dir){
            Ordenacao_EmpilhaInteligente(dados, i, Dir);
        }
        dados->comparacoes++;
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
        dados->comparacoes++;
        while (pivo > dados->vetor[*i]){
            dados->comparacoes++;
            (*i)++;
        }
        dados->comparacoes++;
        while (pivo < dados->vetor[*j]){
            dados->comparacoes++;
            (*j)--;
        }
        dados->comparacoes++;
        if (*i <= *j){ 
            dados->movimentacoes++;
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            (*i)++; 
            (*j)--;
        }
        dados->comparacoes++;
    } while (*i <= *j);
}

//Algoritmo QuickSort Iterativo

void QuickSort_Iterativo(Dados *dados, int N){
    Ordenacao_Iterativo(dados, 0, N - 1);
}

void Ordenacao_Iterativo(Dados *dados, int Esq, int Dir){
    int i, j, *pilha_Esq, *pilha_Dir;
    int **pilha_i, **pilha_j;
    pilha_Esq = (int*)malloc((Dir + 1) * sizeof (int));
    pilha_Dir = (int*)malloc((Dir + 1) * sizeof (int));
    pilha_i = (int**)calloc((Dir + 1), sizeof (int*));
    pilha_j = (int**)calloc((Dir + 1), sizeof (int*));
    for(int k = 0; k <= Dir; k++){
        pilha_i[k] = (int*)calloc(2, sizeof (int));
        pilha_j[k] = (int*)calloc(2, sizeof (int)); 
    }
    pilha_Esq[0] = Esq;
    pilha_Dir[0] = Dir;
    int t = 0;
    do{
        Esq = pilha_Esq[t];
        Dir = pilha_Dir[t];
        Particao_Iterativo(dados, Esq, Dir, &i, &j);
        pilha_i[t][0] = i;
        pilha_j[t][0] = j;
        dados->comparacoes++;
        if((pilha_j[t][1] == 0) && (Esq < pilha_j[t][0])){
            pilha_j[t][1] = 1;
            t++;
            pilha_Esq[t] = Esq;
            pilha_Dir[t] = j;
        }
        else{
            dados->comparacoes++;
            if((pilha_i[t][1] == 0) && (pilha_i[t][0] < Dir)){
                pilha_i[t][1] = 1;
                t++;
                pilha_Esq[t] = i;
                pilha_Dir[t] = Dir;
            }
            else{
                pilha_i[t][1] = 0;
                pilha_j[t][1] = 0;
                t--;
            } 
        }
        dados->comparacoes++;
    } while(t >= 0);

    for(int k = 0; k <= pilha_Dir[0]; k++){
        free(pilha_i[k]);
        free(pilha_j[k]);
    }
    free(pilha_Dir);
    free(pilha_Esq);
}

void Particao_Iterativo(Dados *dados, int Esq, int Dir, int *i, int *j){
    int pivo, aux;
    *i = Esq;
    *j = Dir;
    pivo = dados->vetor[(*i + *j)/2]; /* obtem o pivo  */
    do{
        dados->comparacoes++;
        while (pivo > dados->vetor[*i]){
            dados->comparacoes++;
            (*i)++;
        }
        dados->comparacoes++;
        while (pivo < dados->vetor[*j]){
            dados->comparacoes++;
            (*j)--;
        }
        dados->comparacoes++;
        if (*i <= *j){
            dados->movimentacoes++;
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            (*i)++; 
            (*j)--;
        }
        dados->comparacoes++;
    } while (*i <= *j);
}

