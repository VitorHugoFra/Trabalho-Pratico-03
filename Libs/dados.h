#include <stdio.h>
#include <stdlib.h>

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

//métodos relacionados à arquivos
//void escreve_arquivo(Dados *dados, int N);
void ler_arquivo(Dados *dados);
