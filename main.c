#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libs/ordenacao.h"

int main(){
    Dados dados;
    int N, i;
    N = 1000;
    srand(time(NULL));
    cria_vetor(&dados, N);
    //Algoritmo QuickSort Recursivo
    preenche_vetor(&dados, N);
    inicializa_metricas(&dados);
    QuickSort_Recursivo(&dados, N);
    //Algoritmo QuickSort Mediana
    system("pause");
    return 0;
}