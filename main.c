#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libs/ordenacao.h"

int main(){
    Dados dados;
    clock_t tempo_execucao;
    int N, i, j, n;
    int valores_n[7] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    //int valores_n[7] = {20, 20, 20, 20, 20, 20, 20};
    //printf("Comparacoes =    %d\n", dados.comparacoes);
    //printf("Movimentacoes =  %d\n", dados.movimentacoes);
    //printf("Tempo execucao = %f\n", (((float)tempo_execucao) / (float)CLOCKS_PER_SEC / 1000));
    srand(time(NULL));
    cria_vetor(&dados, N);

    for(n = 0; n < 7; n++){
        N = valores_n[n];

        //Algoritmo QuickSort Recursivo
        preenche_vetor(&dados, N);
        inicializa_metricas(&dados);
        tempo_execucao = clock();
        QuickSort_Recursivo(&dados, N);
        tempo_execucao =  clock() - tempo_execucao;


        // Algoritmo QuickSort Mediana
        int k = 3;
        for(i = 0; i < 2; (i++)){
            preenche_vetor(&dados, N);
            inicializa_metricas(&dados);
            tempo_execucao = clock();
            QuickSort_Mediana(&dados, N, k);
            tempo_execucao =  clock() - tempo_execucao;
            k = 5;

        }

        // Algoritmo QuickSort  Insercao
        int m = 10;
        for(i = 0; i < 2; (i++)){
            preenche_vetor(&dados, N);
            inicializa_metricas(&dados);
            tempo_execucao = clock();
            QuickSort_Insercao(&dados, N, m);
            tempo_execucao =  clock() - tempo_execucao;
            m = 100;

        }

        //Algoritmo QuickSort Empilha Inteligente
        preenche_vetor(&dados, N);
        inicializa_metricas(&dados);
        tempo_execucao = clock();
        QuickSort_EmpilhaInteligente(&dados, N);
        tempo_execucao =  clock() - tempo_execucao;


        //Algoritmo QuickSort Iterativo
        preenche_vetor(&dados, N);
        inicializa_metricas(&dados);
        tempo_execucao = clock();
        QuickSort_Iterativo(&dados, N);
        tempo_execucao =  clock() - tempo_execucao;

    }

    system("pause");
    return 0;
}