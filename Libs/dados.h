#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define Tam_Valores_N 7


typedef struct{
    int *vetor;
    int comparacoes;
    int movimentacoes;
    float tempo;
    char *arq;
}Dados;

void cria_vetor(Dados *dados, int N);
void free_vetor(Dados *dados);
void preenche_vetor(Dados *dados, int N);
void inicializa_metricas(Dados *dados);

