#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Libs/ordenacao.h"

/*
 * Trabalho Prático 03 - AEDS 1 
 * Professora Thais R. M. Braga Silva
 * Universidade Federal de Virçosa - Campus Florestal
 * @author Aymê Faustino dos Santos - Vitor Hugo França de Paula - Iury Martins Pereira
 * @version 0.1
 * @since 25 de mar
*/

int main(int argc, char *argv[]){
    Dados dados;
    clock_t tempo_execucao;
    int N, i, j, n;
    float tempo;
    int semente;
    char nome_arq_saida[100];
    int valores_n[7] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};

    if(argc < 3){
        printf("Nao foram passados todos os parametros");
        return 0;
    }
    semente = atoi(argv[1]);
    strcpy(nome_arq_saida, argv[2]);
    FILE *arquivo;
    arquivo = fopen(nome_arq_saida,"a");// Modo de gravação adicionando ao final de um arquivo ou criando
    
    //verificar se foi aberto
    if(!arquivo){
        printf("Erro na abertura do arquivo\n");
        return 0;
    }
    srand(semente);
    for(n = 0; n < 7; n++){
        N = valores_n[n];
        cria_vetor(&dados, N);
        fprintf( arquivo , "%d ", N );

        //Algoritmo QuickSort Recursivo
        preenche_vetor(&dados, N);
        inicializa_metricas(&dados);
        tempo_execucao = clock();
        QuickSort_Recursivo(&dados, N);
        tempo_execucao = clock() - tempo_execucao;
        tempo = (((float)tempo_execucao) / (float)CLOCKS_PER_SEC / 1000);
        fprintf( arquivo , "%f,%d,%d ", tempo, dados.comparacoes, dados.movimentacoes );

        // Algoritmo QuickSort Mediana
        int k = 3;
        for(i = 0; i < 2; (i++)){
            preenche_vetor(&dados, N);
            inicializa_metricas(&dados);
            tempo_execucao = clock();
            QuickSort_Mediana(&dados, N, k);
            tempo_execucao =  clock() - tempo_execucao;
            tempo = (((float)tempo_execucao) / (float)CLOCKS_PER_SEC / 1000);
            fprintf( arquivo , "%f,%d,%d ", tempo, dados.comparacoes, dados.movimentacoes );
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
            tempo = (((float)tempo_execucao) / (float)CLOCKS_PER_SEC / 1000);
            fprintf( arquivo , "%f,%d,%d ", tempo, dados.comparacoes, dados.movimentacoes );
            m = 100;

        }

        //Algoritmo QuickSort Empilha Inteligente
        preenche_vetor(&dados, N);
        inicializa_metricas(&dados);
        tempo_execucao = clock();
        QuickSort_EmpilhaInteligente(&dados, N);
        tempo_execucao =  clock() - tempo_execucao;
        tempo = (((float)tempo_execucao) / (float)CLOCKS_PER_SEC / 1000);
        fprintf( arquivo , "%f,%d,%d ", tempo, dados.comparacoes, dados.movimentacoes );


        //Algoritmo QuickSort Iterativo
        preenche_vetor(&dados, N);
        inicializa_metricas(&dados);
        tempo_execucao = clock();
        QuickSort_Iterativo(&dados, N);
        tempo_execucao =  clock() - tempo_execucao;
        printf("Tempo execucao = %f\n", (((float)tempo_execucao) / (float)CLOCKS_PER_SEC / 1000));
        tempo = (((float)tempo_execucao) / (float)CLOCKS_PER_SEC / 1000);
        fprintf( arquivo , "%f,%d,%d ", tempo, dados.comparacoes, dados.movimentacoes );

        fprintf( arquivo , "\n", N );
        free_vetor(&dados);

    }

    fclose(arquivo);
    system("pause");
    return 0;
}