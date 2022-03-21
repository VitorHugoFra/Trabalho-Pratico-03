#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include "Libs/ordenacao.h"

int main(){
    Dados dados;
    int N, i;
    N = 20;
    srand(time(NULL));
    cria_vetor(&dados, N);
    //for(i = 0; i< N; i++){
        //printf("%d ", dados.vetor[i]);
    //}
    //printf("\n");

    /*
    //Algoritmo QuickSort Recursivo
    preenche_vetor(&dados, N);
    inicializa_metricas(&dados);
    QuickSort_Recursivo(&dados, N);
    //Algoritmo QuickSort Mediana
    int k = 3;
    for(i = 0; i < 2; (i++)){
        preenche_vetor(&dados, N);
        inicializa_metricas(&dados);
        QuickSort_Mediana(&dados, N, k);
        k = 5;
    }
    // Algoritmo QuickSort  Insercao
    int m = 10;
    for(i = 0; i < 2; (i++)){
        preenche_vetor(&dados, N);
        inicializa_metricas(&dados);
        QuickSort_Insercao(&dados, N, m);
        m = 100;
    }
    
   //Algoritmo QuickSort Empilha Inteligente
    preenche_vetor(&dados, N);
    inicializa_metricas(&dados);
    QuickSort_EmpilhaInteligente(&dados, N);
    for(i = 0; i< N; i++){
        printf("%d ", dados.vetor[i]);
    }
    printf("\n");*/

    //Algoritmo QuickSort Iterativo
    preenche_vetor(&dados, N);
    for(i = 0; i< N; i++){
        printf("%d ", dados.vetor[i]);
    }
    printf("\n");
    inicializa_metricas(&dados);
    QuickSort_Iterativo(&dados, N);
    for(i = 0; i< N; i++){
        printf("%d ", dados.vetor[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}