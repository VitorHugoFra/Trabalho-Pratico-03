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
        if (*i <= *j){ 
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            dados->movimentacoes += 3;
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
        if (*i <= *j){ 
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            dados->movimentacoes += 3;
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
    }
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
    if(Dir - Esq + 1 <= m){
        int l, r, aux;
        for(l = Esq; l <= Dir; l++){
            aux = dados->vetor[l];
            dados->movimentacoes++;
            r = l - 1;
            dados->comparacoes++;
            while ((r >= 0) && (aux < dados->vetor[r])){
                dados->vetor[r + 1] = dados->vetor[r];
                dados->movimentacoes++;
                r--;
                dados->comparacoes++;
            }
            dados->movimentacoes++;
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
        if (*i <= *j){ 
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            dados->movimentacoes += 3;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}

//Algoritmo QuickSort Empilha Inteligente
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
            dados->movimentacoes += 3;
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
        // Na possi????o pilha_i[t][0] guarda os valores i para cada vez que o while roda
        // ?? em pilha_i[t][1] gurda um marcador para saber se aquele indice j?? foi usado como
        // Esq, 1 quando j?? foi usado ?? zero quando ainda n??o foi
        // O mesmo serve para a pilha_j
        pilha_i[t][0] = i;
        pilha_j[t][0] = j;
        if((pilha_j[t][1] == 0) && (Esq < pilha_j[t][0])){
            pilha_j[t][1] = 1;
            t++;
            pilha_Esq[t] = Esq;
            pilha_Dir[t] = j;
        }
        else{
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
        if (*i <= *j){
            aux = dados->vetor[*i];
            dados->vetor[*i] = dados->vetor[*j]; 
            dados->vetor[*j] = aux;
            dados->movimentacoes += 3;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}

