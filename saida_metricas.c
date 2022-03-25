#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo, *arq;
    int N[7] = {0, 0, 0, 0, 0, 0, 0};
    float **soma_tempo, aux_tem;
    int **soma_comparacoes, **soma_movimentacoes;
    int aux_com, aux_mov, total_arq, i, j;
    char *nome_arq;
    char **variacao_quicksort;
   
    variacao_quicksort = (char**)malloc(7 * sizeof(char*));
   

    soma_tempo = (float**)malloc(7 * sizeof(float*));
    soma_comparacoes = (int**)malloc(7 * sizeof(int*));
    soma_movimentacoes = (int**)malloc(7 * sizeof(int*));
    for(i = 0; i < 7; i++){
        soma_tempo[i] = (float*)calloc(7, sizeof(float));
        soma_comparacoes[i] = (int*)calloc(7, sizeof(int));
        soma_movimentacoes[i] = (int*)calloc(7, sizeof(int));
    }
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
    fclose(arquivo);

    
    for(i = 0; i < 7; i++){
        variacao_quicksort[i] = (char*)malloc(64 * sizeof(char));
    }
    variacao_quicksort[0] = "QuickSort Recursivo";
    variacao_quicksort[1] = "QuickSort Mediana 3";
    variacao_quicksort[2] = "QuickSort Mediana 5";
    variacao_quicksort[3] = "QuickSort Insercao 10";
    variacao_quicksort[4] = "QuickSort Insercao 100";
    variacao_quicksort[5] = "QuickSort Empilha Inteligente";
    variacao_quicksort[6] = "QuickSort Iterativo";

    for(i = 0; i < 7; i++){
        printf("----------- N = %d -----------\n", N[i]);
        for(j = 0; j < 7; j++){
            printf("--------- %s --------\n", variacao_quicksort[j]);
            printf("Media tempo execucao: %f\n", soma_tempo[i][j] / total_arq);
            printf("Media comparacoes: %d\n", soma_comparacoes[i][j] / total_arq);
            printf("Media movimentacoes: %d\n", soma_movimentacoes[i][j] / total_arq);
        }
        printf("\n");
    }
    for(i = 0; i < 7; i++){
        free(soma_tempo[i]);
        free(soma_comparacoes[i]);
        free(soma_movimentacoes[i]);
        //free(variacao_quicksort[i]);
    }
    free(variacao_quicksort);
    free(soma_tempo);
    free(soma_comparacoes);
    free(soma_movimentacoes);
    system("pause");
    return 0;
}