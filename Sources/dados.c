#include "../Libs/dados.h"

void cria_vetor(Dados *dados, int N){
    dados->vetor = (int*)malloc(N * sizeof(int));
}
void free_vetor(Dados *dados){
    free(dados->vetor);
}

void preenche_vetor(Dados *dados, int N){
    int i, num;
    for(i = 0; i < N; i++){
        num = rand() % 1000000;
        dados->vetor[i] = num;
    }
}

void inicializa_metricas(Dados *dados){
    dados->comparacoes = 0;
    dados->movimentacoes = 0;
    dados->tempo = 0.0;
}