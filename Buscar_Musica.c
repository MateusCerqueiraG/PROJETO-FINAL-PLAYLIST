#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAX_TITULO 100
#define MAX_ARTISTA 100

typedef struct {
    char titulo[MAX_TITULO];
    char artista[MAX_ARTISTA];
    int favoritada;
} Musica;

typedef struct {
    Musica musicas[MAX];
    int tamanho;
} Playlist;

void Inserir_Musica(Playlist *playlist) {
    if (playlist->tamanho < MAX) {
        printf("Adicione a musica na playlist:\n");

        printf("Titulo da musica: ");
        fgets(playlist->musicas[playlist->tamanho].titulo, sizeof(playlist->musicas[0].titulo), stdin);

        printf("Nome do artista: ");
        fgets(playlist->musicas[playlist->tamanho].artista, sizeof(playlist->musicas[0].artista), stdin);

        playlist->tamanho++;
    } else {
        printf("Playlist cheia. Nao eh possivel adicionar mais musicas.\n");
    }
}


void listarMusicas(Playlist *playlist) {
    printf("----- Musicas na Playlist -----\n");
    for (int i = 0; i < playlist->tamanho; ++i) {
        printf("%d. %s - %s\n", i + 1, playlist->musicas[i].titulo, playlist->musicas[i].artista);
    }
    printf("-------------------------------\n");
}

void editarMusica(Playlist *playlist, int index) {
    printf("Editando:\n %s %s\n", playlist->musicas[index - 1].titulo, playlist->musicas[index - 1].artista);
    printf("Novo titulo da musica: ");
    fgets(playlist->musicas[index - 1].titulo, sizeof(playlist->musicas[0].titulo), stdin);
    printf("Novo nome do artista: ");
    fgets(playlist->musicas[index - 1].artista, sizeof(playlist->musicas[0].artista), stdin);

    printf("Informacoes da musica editadas com sucesso.\n");
}

void Buscar_Musica(Playlist *playlist, char *busca){
    int resultado_busca = 0; 
    printf("Resultado(s) da busca:\n");
    
    for(int i = 0; i < playlist->tamanho; i++){
        if(strstr(playlist->musicas[i].titulo, busca) != NULL) {
            printf("%d. %s - %s\n", i + 1, playlist->musicas[i].titulo,playlist->musicas[i].artista);
            resultado_busca = 1;
        }
    }

    if(resultado_busca == 0){
        printf("Nenhuma musica encontrada :(\n");
    }

}

int main() {
    Playlist minhaPlaylist;
    minhaPlaylist.tamanho = 0;
    int opcao = 0;

    printf("        --------------------------\n");
    printf("        |          MENU          |\n");
    printf("        --------------------------\n");

    while (opcao != 9) {
        printf("------------------------------------------\n");
        printf("|     1- Adicionar Nova Musica.          |\n");
        printf("|     2- Favoritar Musica.               |\n");
        printf("|     3- Escolher Musica Aleatoria.      |\n");
        printf("|     4- Remover Musica.                 |\n");
        printf("|     5- Mostrar Musicas Da Playlist.    |\n");
        printf("|     6- Editar Musica Da Playlist.      |\n");
        printf("|     7- Buscar Uma Musica.              |\n");
        printf("|     8- Baixar Playlist.                |\n");
        printf("|     9- Fechar Playlist.                |\n");
        printf("------------------------------------------\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                Inserir_Musica(&minhaPlaylist);
                break;
            case 5:
                listarMusicas(&minhaPlaylist);
                break;
            case 6: {
                listarMusicas(&minhaPlaylist);
                int escolha;
                printf("Escolha o numero da musica que deseja editar: ");
                scanf("%d", &escolha);
                getchar();

                if (escolha > 0 && escolha <= minhaPlaylist.tamanho) {
                    editarMusica(&minhaPlaylist, escolha);
                } else {
                    printf("Opcao invalida!\n");
                }
                break;
            }
            case 7: {
                char busca[MAX_TITULO];
                printf("O que deseja buscar? ");
                fgets(busca, sizeof(busca), stdin);
                busca[strcspn(busca, "\n")] = '\0';

                Buscar_Musica(&minhaPlaylist, busca);
                break;
            }
            case 9:
                printf("Playlist fechada com sucesso!\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    return 0;
}