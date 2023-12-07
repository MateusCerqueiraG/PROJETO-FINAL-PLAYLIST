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
        
        printf("+----------------------------------------+\n");
        printf("|          Adicionar Nova Musica         |\n");
        printf("+----------------------------------------+\n\n");
        
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
        printf("+----------------------------------------+\n");
        printf("|             Minha Playlist             |\n");
        printf("+----------------------------------------+\n\n");
        for (int i = 0; i < totalMusicas; i++) {
            printf("%d. %s - %s", i + 1, playlist[i].titulo, playlist[i].artista);
            if (playlist[i].favoritada) {
                printf(" (Favorita)\n");
            } else {
                printf("\n");
            }
        }
        printf("+----------------------------------------+\n\n");
    }
}

void favoritarMusica(Playlist *playlist, int indice) {
    
    if (indice >= 0 && indice < playlist->tamanho) {
        playlist->musicas[indice].favoritada = 1;
        printf("\n* %s - %s \n        Favoritada com sucesso ;)\n", playlist->musicas[indice].titulo, playlist->musicas[indice].artista);
        printf("+----------------------------------------+\n");
    } else {
        printf("Musica nao encontrada na playlist.\n");
    }
}

int Musica_Aleatoria(Playlist *playlist) {
    if (playlist->tamanho > 0) {
        return rand() % playlist->tamanho;
    } else {
        return -1;
    }
}

void editarMusica(Playlist *playlist, int index) {
    printf("Editando:\n %s %s\n", playlist->musicas[index - 1].titulo, playlist->musicas[index - 1].artista);
    printf("Novo titulo da musica: ");
    fgets(playlist->musicas[index - 1].titulo, sizeof(playlist->musicas[0].titulo), stdin);
    printf("Novo nome do artista: ");
    fgets(playlist->musicas[index - 1].artista, sizeof(playlist->musicas[0].artista), stdin);

    printf("\nInformacoes da musica editadas com sucesso.\n");
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
    printf("+----------------------------------------+\n\n");
}

void Buscar_Artista(Playlist *playlist, char *busca){
    int resultado_busca = 0;
    printf("Resultado(s) da busca:\n\n");
    printf("Artista: %s", busca);
    printf("Musicas\n");
    for(int i = 0; i < playlist->tamanho; i++){
        if(strcmp(playlist->musicas[i].artista, busca) == 0){
            if (!resultado_busca) {
                resultado_busca = 1;
            }
            printf("%d. %s", i + 1, playlist->musicas[i].titulo);
        }
    }

    if(resultado_busca == 0){
        printf("      Nenhum artista encontrado :(\n");
    }
    printf("\n+----------------------------------------+\n\n");
}

void Remover_Musica(Playlist *playlist) {
    int indice, opcao;

    if (playlist->tamanho > 0) {
        mostrarPlaylist(playlist->musicas, playlist->tamanho);

        printf("Insira o numero da musica a ser removida: ");
        scanf("%d", &indice);

        if (indice > 0 && indice <= playlist->tamanho) {
            printf("\nDeseja realmente remover a musica\n\n %s - %s \n", playlist->musicas[indice - 1].titulo, playlist->musicas[indice - 1].artista);
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);
            system("clear||cls");
            switch (opcao) {
                case 1:
                    printf("          Removendo a musica...\n\n%s - %s\n", playlist->musicas[indice - 1].artista, playlist->musicas[indice - 1].titulo);
                    printf("       Musica removida com sucesso!\n", playlist->musicas[indice - 1].titulo);
                    for (int i = indice - 1; i < playlist->tamanho - 1; i++) {
                        playlist->musicas[i] = playlist->musicas[i + 1];
                    }
                    playlist->tamanho--;
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
    for (int i = 0; i < playlist->tamanho; ++i) {
        printf("%d. %s - %s", i + 1, playlist->musicas[i].titulo, playlist->musicas[i].artista);
        if (playlist->musicas[i].favoritada) {
            printf(" (Favorita)\n\n");
        } else {
            printf("\n");
        }
    }
    printf("+----------------------------------------+\n\n");
}

void Baixar_Playlist(Playlist *playlist) {
    FILE *file = fopen("Playlist.txt", "w");
    if (file == NULL) {
        printf("Erro ao baixar a playlist!! :(\n");
        return;
    }

    fprintf(file, "----------- Playlist -----------\n");
    for (int i = 0; i < playlist->tamanho; ++i) {
        fprintf(file, "%d. %s - %s", i + 1, playlist->musicas[i].artista, playlist->musicas[i].titulo);
        if (playlist->musicas[i].favoritada) {
            fprintf(file, " (Favorita)\n\n");
        } else {
            fprintf(file, "\n");
        }
    }
    fprintf(file, "--------------------------------\n");

    fclose(file);
    printf("      Playlist baixada com sucesso!\n");
    printf("+----------------------------------------+\n");
}


int main() {
    Playlist minhaPlaylist;
    minhaPlaylist.tamanho = 0;
    int opcao = 0;

    printf("==========================================\n");
    printf("Bem-vindo ao seu Gerenciador de Playlists!\n");
    printf("==========================================\n");
    printf("Gostaria de criar uma nova playlist?\n");
    printf("[1] Sim\n");
    printf("[2] Nao\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1) {
        system("clear || cls");
        do{
            printf("        +------------------------+\n");
            printf("        |          MENU          |\n");
            printf("        +------------------------+\n");
        
            printf("+----------------------------------------+\n");
            printf("|     1- Adicionar Musica                |\n");
            printf("|     2- Mostrar Playlist                |\n");
            printf("|     3- Favoritar Musica                |\n");
            printf("|     4- Escolher Musica Aleatoria       |\n");
            printf("|     5- Editar Musica                   |\n");
            printf("|     6- Realizar Busca                  |\n");
            printf("|     7- Remover Musica                  |\n");
            printf("|     8- Baixar Playlist                 |\n");
            printf("|     9- Fechar Playlist                 |\n");
            printf("+----------------------------------------+\n");

            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);
            getchar();

            switch (opcao) {
                case 1:
                    system("clear || cls");
                    Inserir_Musica(&minhaPlaylist);
                    printf("\n     Musica adiconada com sucesso! ;)\n");
                    printf("+----------------------------------------+\n");
                    break;
                case 2: 
                    system("clear || cls");
                    printf("+----------------------------------------+\n");
                    printf("|             Minha Playlist             |\n");
                    printf("+----------------------------------------+\n\n");
                    listarMusicas(&minhaPlaylist);
                    break;
                case 3: {
                    system("clear || cls");
                    printf("*---*-------*------*-----------*------*--*\n");
                    printf("|           Favoritar Musica             |\n");
                    printf("*-----*-----*-------------*--------*-----*\n\n");
                    listarMusicas(&minhaPlaylist);
                    int escolha;
                    printf("Escolha o numero da musica que deseja favoritar: ");
                    scanf("%d", &escolha);
                    getchar();

                    if (escolha > 0 && escolha <= minhaPlaylist.tamanho) {
                        favoritarMusica(&minhaPlaylist, escolha - 1);
                    } else {
                        printf("Opcao invalida!\n");
                    }
                    break;
                }
                case 4: {
                    system("clear || cls");
                    printf("+----------------------------------------+\n");
                    printf("|           Musica Aleatoria             |\n");
                    printf("+----------------------------------------+\n\n");
                    int indice_aleatorio = Musica_Aleatoria(&minhaPlaylist);
                    if (indice_aleatorio != -1) {
                        printf("A Musica da vez eh:\n\n%d. %s - %s\n", indice_aleatorio + 1, minhaPlaylist.musicas[indice_aleatorio].titulo, minhaPlaylist.musicas[indice_aleatorio].artista);
                    } else {
                        printf("Nao ha musicas na playlist.\n");
                    }
                    printf("+----------------------------------------+\n\n");
                    break;
                }
                case 5: {
                    system("clear || cls");
                    printf("+-------<----------<------------<--------+\n");
                    printf("|            Editar Musica               |\n");
                    printf("+-->---------->-------------->------->---+\n\n");
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

                    printf("+----------------------------------------+\n\n");

                    break;
                }
                case 6: {
                    system("clear || cls");
                    printf("+----------------------------------------+\n");
                    printf("|                 Busca                  |\n");
                    printf("+----------------------------------------+\n\n");
                    char opcao_busca;
                    printf("1- Buscar por Musica\n");
                    printf("2- Buscar por Artista\n\n");
                    printf("Escolha uma opcao: ");
                    scanf("%c", &opcao_busca);
                    getchar();
                    printf("+----------------------------------------+\n\n");

                    system("clear || cls");
                    
                    printf("+----------------------------------------+\n");
                    printf("|                 Busca                  |\n");
                    printf("+----------------------------------------+\n\n");
                    
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
                case 7:
                    system("clear || cls");

                    printf("XX--------X--------X-----------X--------XX\n");
                    printf("X            Remover Musica              X\n");
                    printf("XX--------X--------X-----------X--------XX\n\n");

                    Remover_Musica(&minhaPlaylist);

                    printf("+----------------------------------------+\n");

                    break;
                
                case 8:
                    system("clear || cls");
                    Baixar_Playlist(&minhaPlaylist);
                    break;
                case 9:
                    system("clear || cls");
                    printf("Playlist fechada com sucesso!\n");
                    break;
                case 100:
                    system("clear || cls");
                    printf("VOCE DESCOBRIU A CASE 100 :D, CURIOSO DEMAIS '-'\nTente executar o codigo denovo e nao volte aqui!!\n");
                    return 0;
                default:
                    printf("Opcao invalida!\n");
                    break;
            }
        } while (opcao != 9);

    } else if (opcao == 2) {
        printf("Playlist nao criada.\n");
    } else {
        printf("Opcao invalida, programa fechado.\n");
    }

    return 0;
}