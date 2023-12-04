#include <stdio.h>
#include <stdbool.h>
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
        printf("Playlist cheia. Nao e possivel adicionar mais musicas.\n");
    }
}

void mostrarPlaylist(Musica playlist[], int totalMusicas) {
    if (totalMusicas == 0) {
        printf("Playlist vazia.\n");
    } else {
        printf("\n------- Playlist -------\n");
        for (int i = 0; i < totalMusicas; i++) {
            printf("%d. %s - %s", i + 1, playlist[i].artista, playlist[i].titulo);
            if (playlist[i].favoritada) {
                printf(" (Favorita)\n");
            } else {
                printf("\n");
            }
        }
        printf("------------------------\n");
    }
}

void editarMusica(Playlist *playlist, int index) {
    printf("Editando:\n %s %s\n", playlist->musicas[index - 1].titulo, playlist->musicas[index - 1].artista);
    printf("Novo titulo da musica: ");
    fgets(playlist->musicas[index - 1].titulo, sizeof(playlist->musicas[0].titulo), stdin);
    printf("Novo nome do artista: ");
    fgets(playlist->musicas[index - 1].artista, sizeof(playlist->musicas[0].artista), stdin);

    printf("Informacoes da musica editadas com sucesso.\n");
}

void Remover_Musica(Playlist *playlist) {
    int indice, opcao;

    if (playlist->tamanho > 0) {
        mostrarPlaylist(playlist->musicas, playlist->tamanho);

        printf("Insira o numero da musica a ser removida: ");
        scanf("%d", &indice);

        if (indice > 0 && indice <= playlist->tamanho) {
            printf("Deseja realmente remover a musica de %s - %s ?\n", playlist->musicas[indice - 1].artista, playlist->musicas[indice - 1].titulo);
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    printf("Removendo a musica: %s - %s\n", playlist->musicas[indice - 1].artista, playlist->musicas[indice - 1].titulo);
                    for (int i = indice - 1; i < playlist->tamanho - 1; i++) {
                        playlist->musicas[i] = playlist->musicas[i + 1];
                    }
                    playlist->tamanho--;
                    printf("Musica %s removida com sucesso!\n", playlist->musicas[indice - 1].titulo);
                    break;
                case 2:
                    printf("Remocao cancelada.\n");
                    break;
                default:
                    printf("Opcao invalida.\n");
                    break;
            }
        } else {
            printf("Numero da musica invalido.\n");
        }
    } else {
        printf("A playlist esta vazia. Nao ha musicas para remover.\n");
    }
}

void listarMusicas(Playlist *playlist) {
    printf("----- Musicas na Playlist -----\n");
    for (int i = 0; i < playlist->tamanho; ++i) {
        printf("%d. %s - %s\n", i + 1, playlist->musicas[i].titulo, playlist->musicas[i].artista);
    }
    printf("-------------------------------\n");
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

void Buscar_Artista(Playlist *playlist, char *busca){
    int resultado_busca = 0;
    printf("Resultado(s) da busca:\n");
    printf("Artista: %s\n", busca);

    for(int i = 0; i < playlist->tamanho; i++){
        if (strcmp(playlist->musicas[i].artista, busca) == 0) {
            if (!resultado_busca) {
                resultado_busca = 1;
            }
            printf("%d. %s", i + 1, playlist->musicas[i].titulo);
        }
    }

    if(resultado_busca == 0){
        printf("Nenhum artista encontrado :(\n");
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
            case 4:
                Remover_Musica(&minhaPlaylist);
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
                char opcao_busca;
                printf("1. Buscar por musica.\n");
                printf("2. Buscar por artista.\n");
                scanf("%c", &opcao_busca);
                getchar();
                
                if(opcao_busca == '1'){
                    char busca_musica[MAX_TITULO];
                    printf("Digite o nome da musica que deseja encontrar:  ");
                    fgets(busca_musica, sizeof(busca_musica), stdin);
                    busca_musica[strcspn(busca_musica, "\n")] = '\0';

                    Buscar_Musica(&minhaPlaylist, busca_musica);   
                    break;
                }else if(opcao_busca == '2'){
                    char busca_artista[MAX_ARTISTA];
                    printf("Digite o nome do artista que deseja encontrar: ");
                    fgets(busca_artista, sizeof(busca_artista), stdin);
                    

                    Buscar_Artista(&minhaPlaylist, busca_artista);   
                    break;
                } 
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