#include "../Libs/dados.h"

//Algoritmo QuickSort Recursivo
void QuickSort_Recursivo(Dados *dados, int N);
void Ordenacao_Recursivo(Dados *dados, int Esq, int Dir);
void Particao_Recursivo(Dados *dados, int Esq, int Dir,int *i, int *j);

//Algoritmo QuickSort Mediana
void QuickSort_Mediana(Dados *dados, int N, int k);
void Ordenacao_Mediana(Dados *dados, int Esq, int Dir, int k);
void Particao_Mediana(Dados *dados, int Esq, int Dir,int *i, int *j, int k);
int escolha_pivor(Dados *dados, int Esq, int Dir, int k);

// Algoritmo QuickSort  Insercao
void QuickSort_Insercao(Dados *dados, int N, int m);
void Ordenacao_Insercao(Dados *dados, int Esq, int Dir, int m);
void Particao_Insercao(Dados *dados, int Esq, int Dir,int *i, int *j, int m);

// Algoritmo QuickSort Empilha Inteligente
void QuickSort_EmpilhaInteligente(Dados *dados, int N);
void Ordenacao_EmpilhaInteligente(Dados *dados, int Esq, int Dir);
void Particao_EmpilhaInteligente(Dados *dados, int Esq, int Dir,int *i, int *j);

// Algoritmo QuickSort Iterativo
void QuickSort_Iterativo(Dados *dados, int N);
void Ordenacao_Iterativo(Dados *dados, int Esq, int Dir);
void Particao_Iterativo(Dados *dados, int Esq, int Dir,int *i, int *j);
