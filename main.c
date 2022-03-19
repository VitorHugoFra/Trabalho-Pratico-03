#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include "Libs/ordenacao.h"

int main(){
    Dados dados;
    int N, i, j;
    N = 30;
    srand(time(NULL));
    cria_vetor(&dados, N);
    //Algoritmo QuickSort Recursivo
    preenche_vetor(&dados, N);
    //for(j = 0; j < N; j++){
       // printf("%d ", dados.vetor[j]);
   // }
    printf("\n");
    inicializa_metricas(&dados);
    QuickSort_Recursivo(&dados, N);
    //Algoritmo QuickSort Mediana
    for(i = 3; i < 6; (i++)){
        preenche_vetor(&dados, N);
        inicializa_metricas(&dados);
        QuickSort_Mediana(&dados, N, i);
        i++;
    }
    // Algoritmo QuickSort  Insercao
    system("pause");
    return 0;
}