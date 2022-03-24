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
        num = rand() % 100;
        dados->vetor[i] = num;
    }
}

void inicializa_metricas(Dados *dados){
    dados->comparacoes = 0;
    dados->movimentacoes = 0;
    //dados->tempo = 0.0;
}

/*
void escreve_arquivo(Dados *dados, int N){
    FILE *arquivo;
    arquivo = fopen(dados->arq,"a");// Modo de gravação adicionando ao final de um arquivo ou criando
    
    //verificar se foi aberto
    if(!arquivo){
        printf("Erro na abertura do arquivo\n");
    }
    //else{
    //    printf("Arquivo aberto com sucesso\n");
    //}


    fprintf( arquivo , "%d\n", N );
    fprintf ( arquivo , "%f,%d,%d \n", dados->tempo, dados->comparacoes, dados->movimentacoes );

    fclose(arquivo);
}
*/

void ler_arquivo( char *argv){
    FILE *arquivo;
    int N[Tam_Valores_N] = {0, 0, 0, 0, 0, 0, 0};
    float tempo[Tam_Valores_N];
    int comparacoes[Tam_Valores_N], movimentacoes[Tam_Valores_N], aux = 0;

    arquivo = fopen(argv,"r");
    
    //Verificar se foi aberto o arquivo
    if(!arquivo){
        printf("Erro na abertura do arquivo\n");
    }
    
    while(!feof(arquivo)){

        if(fscanf(arquivo,"%d,", &N[aux]) != EOF){
        
            printf("N= %d\n", N[aux] );

            for(int i = 0; i < Tam_Valores_N; i++){
                fscanf(arquivo,"(%f,%d,%d)", &tempo[i], &comparacoes[i], &movimentacoes[i]);
                printf("(%f,%d,%d)", tempo[i], comparacoes[i], movimentacoes[i]);
                
                if(feof(arquivo) == 1){
                    exit(1);
                }
            }
            
            printf("\n");
        }

    }

    fclose(arquivo);

}