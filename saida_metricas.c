#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo, *arq;
    int N[7] = {0, 0, 0, 0, 0, 0, 0};
    int aux_com, aux_mov, total_arq, i, j;
    char *nome_arq;
    // Como foi dito na documentaçaõ se estiver usando um computador com sistema linux tem de 
    // usar essa parte do código para o programa funcionar
    //Linux
    char **variacao_quicksort;
    float **soma_tempo, aux_tem;
    int **soma_comparacoes, **soma_movimentacoes;
    soma_tempo = (float**)malloc(7 * sizeof(float*));
    soma_comparacoes = (int**)malloc(7 * sizeof(int*));
    soma_movimentacoes = (int**)malloc(7 * sizeof(int*));
    for(i = 0; i < 7; i++){
        variacao_quicksort[i] = (char*)malloc(64 * sizeof(char));
        soma_tempo[i] = (float*)calloc(7, sizeof(float));
        soma_movimentacoes[i] = (int*)calloc(7, sizeof(int));
        soma_comparacoes[i] = (int*)calloc(7, sizeof(int));
    }

    // Mas caso esteja usando um computador com sistema linux tem de usar essa parte do código
    // que esta comentada para o programa funcionar
    /*
    //Windows
    char **variacao_quicksort;
    float soma_tempo[7][7], aux_tem;
    int soma_comparacoes[7][7], soma_movimentacoes[7][7];
    variacao_quicksort = (char**)malloc(7 * sizeof(char*));
    for(i = 0; i < 7; i++){
        variacao_quicksort[i] = (char*)malloc(64 * sizeof(char));
        for(j = 0; j < 7; j++){
            soma_tempo[i][j] = 0.0;
            soma_comparacoes[i][j] = 0;
            soma_movimentacoes[i][j] = 0;
        }
    }
    */

    variacao_quicksort[0] = "QuickSort Recursivo";
    variacao_quicksort[1] = "QuickSort Mediana 3";
    variacao_quicksort[2] = "QuickSort Mediana 5";
    variacao_quicksort[3] = "QuickSort Insercao 10";
    variacao_quicksort[4] = "QuickSort Insercao 100";
    variacao_quicksort[5] = "QuickSort Empilha Inteligente";
    variacao_quicksort[6] = "QuickSort Iterativo";

    arquivo = fopen("nomes_arqs_saida.txt","r");
    
    //Verificar se foi aberto o arquivo
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(0);
    }
    total_arq = 0;


    while(fscanf(arquivo, "%s\n",nome_arq ) != -1){
        arq = fopen(nome_arq, "r");
        total_arq++;
        if(arq == NULL){
            printf("Erro na abertura do arquivo\n");
            exit(0);
        }
        i = 0;
        while(!feof(arq) && i < 7){
            fscanf(arq,"%d,", &N[i]);
            for(j = 0; j < 7; j++){
                fscanf(arq,"(%f,%d,%d)", &aux_tem, &aux_com, &aux_mov);
                soma_tempo[i][j] += aux_tem;
                soma_comparacoes[i][j] += aux_com;
                soma_movimentacoes[i][j] += aux_mov;
            }
            i++;
        }
        fclose(arq);
    }
    if (total_arq != 5){
        printf("Nao tem 5 arquivos");
        exit(1);
    }
    
    fclose(arquivo);
    for(i = 0; i < 7; i++){
        printf("--------------> N = %d\n", N[i]);
  
        for(j = 0; j < 7; j++){
            printf("--------------> %s\n", variacao_quicksort[j]);
            printf("Media tempo execucao: %f\n", soma_tempo[i][j] / total_arq);
            printf("Media comparacoes: %d\n", soma_comparacoes[i][j] / total_arq);
            printf("Media movimentacoes: %d\n", soma_movimentacoes[i][j] / total_arq);
        }
        printf("\n");
    }

    for(i = 0; i < 7; i++){
        free(variacao_quicksort[i]);
    }
    free(variacao_quicksort);

    system("pause");
    return 0;
}
