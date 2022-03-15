#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *vetor;
    //int comparacoes;
    //int movimentacoes;
    //float tempo;
}Dados;

void cria_vetor(Dados *dados, int N);
void free_vetor(Dados *dados);

void preenche_vetor(Dados *dados, int N);