#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


typedef struct{
    char titulo[MAX];
    char artista[MAX];
    int favoritada;
} Musica;


typedef struct{
    Musica musicas[MAX];
    int tamanho;
} Playlist;


void Inserir_Musica(Playlist *playlist){
    if(playlist->tamanho < MAX){
        int opcao = -1;


        printf("Insira a musica na playlist:\n");


        printf("Nome da musica: ");
        fgets(playlist->musicas[playlist->tamanho].titulo, sizeof(playlist->musicas[0].titulo), stdin);


        printf("Nome do artista: ");
        fgets(playlist->musicas[playlist->tamanho].artista, sizeof(playlist->musicas[0].artista), stdin);


        playlist->tamanho++;


        /*printf("Deseja salvar a musica na playlist?\n");          // Nao funfou :(
        printf("1 - Sim\n");
        printf("0 - Nao\n");
        scanf("%d", &opcao);


        switch(opcao){
            case 1:
                printf("Musica inserida com sucesso!\n");
                break;
            case 0:
                printf("Cadastro cancelado\n");
            default:
                printf("Opcao invalida\n");
                break;
        }*/
    }


    else{
        printf("Playlist cheia. Nao eh possivel adicionar mais musicas.\n");
    }


}


int main() {
    Playlist minhaPlaylist;
    minhaPlaylist.tamanho = 0;


    Inserir_Musica(&minhaPlaylist);


    return 0;
}