#include "../Libs/dados.h"

//Algoritmo QuickSort Recursivo
void QuickSort_Recursivo(Dados *dados, int N);
void Ordenacao_Recursivo(Dados *dados, int Esq, int Dir);
void Particao_Recursivo(Dados *dados, int Esq, int Dir,int *i, int *j);

//Algoritmo QuickSort Mediana
void QuickSort_Mediana(Dados *dados, int N, int k);
void Ordenacao_Mediana(Dados *dados, int Esq, int Dir, int k);
void Particao_Mediana(Dados *dados, int Esq, int Dir,int *i, int *j, int k);
void escolha_pivor(Dados *dados, int Esq, int Dir, int *pivor, int k);

//Algoritmo QuickSort  Insercao
