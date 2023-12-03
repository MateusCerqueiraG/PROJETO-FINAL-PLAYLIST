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


void Remover_Musica(Playlist *playlist){
    int indice, opcao; 


    if(playlist->tamanho > 0){
        printf("Insira o numero da musica a ser removida: ");
        scanf("%d", &indice);


        if(indice > 0 && indice <= playlist->tamanho){
            printf("Deseja realmente remover a música %s - %s?\n", playlist->musicas[indice - 1].artista, playlist->musicas[indice - 1].titulo);
            printf("1 - Sim\n");
            printf("0 - Nao\n");
                scanf("%d", &opcao);


            switch(opcao){
                case 1:
                    printf("Removendo a musica: %s - %s\n", playlist->musicas[indice - 1].artista, playlist->musicas[indice - 1].titulo);
                    for(int i = indice - 1; i < playlist->tamanho - 1; i++){
                        playlist->musicas[i] = playlist->musicas[i + i];
                    }
                    playlist->tamanho--;
                    printf("Musica %s removida com sucesso!", playlist->musicas[indice - 1].titulo);
                    break;
                case 0: 
                    printf("Remocao cancelada\n");
                default:
                    printf("Opcao invalida\n");
                    break;
            }


        }

        
            else{
                printf("Numero da musica invalido");
            }      


    }


    else{
    printf("A playlist esta vazia. Nao ha musicas para remover.\n");
    }
      

}


int main(){
    Playlist minhaPlaylist;
    minhaPlaylist.tamanho = 0;


    Remover_Musica(&minhaPlaylist);


    return 0;
}