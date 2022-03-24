#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo, *arq;
    int N[7] = {0, 0, 0, 0, 0, 0, 0};
    float **soma_tempo, aux_tem;
    int **soma_comparacoes, **soma_movimentacoes;
    int aux_com, aux_mov, total_arq, i, j;
    char nome_arq[100];
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
    while(fgets(nome_arq, 100, arquivo) != NULL){
        arq = fopen(nome_arq, "r");
        total_arq++;
        if(arq == NULL){
            printf("Erro na abertura do arquivo\n");
            exit(0);
        }
        i = 0;
        while(!feof(arq)){
            fscanf(arquivo,"%d,", &N[i]);
            for(j = 0; j < 7; j++){
                fscanf(arquivo,"(%f,%d,%d)", &aux_tem, &aux_com, &aux_mov);
                soma_tempo[i][j] += aux_tem;
                soma_comparacoes[i][j] += aux_com;
                soma_movimentacoes[i][j] += aux_mov;
            }
            i++;
        }
        fclose(arq);
    }
    fclose(arquivo);

    char variacao_quicksort[7];
    

    for(i = 0; i < 7; i++){
        free(soma_tempo[i]);
        free(soma_comparacoes[i]);
        free(soma_movimentacoes[i]);
    }
    free(soma_tempo);
    free(soma_comparacoes);
    free(soma_movimentacoes);
    system("pause");
    return 0;
}