#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Music {
    char title[50];
    int favorite;
} Music;

void addMusic(Music *music, int index);
void listMusic(Music *music, int total);
void removeMusic(Music *music, int index, int total);

int main() {
    Music music[50];
    int total = 0;
    int option;

    do {
        printf("\nMenu de Musicas:\n");
        printf("1. Adicionar musica\n");
        printf("2. Listar musicas\n");
        printf("3. Remover musica\n");
        printf("4. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addMusic(music, total);
                total++;
                break;
            case 2:
                listMusic(music, total);
                break;
            case 3:
                removeMusic(music, total - 1, total);
                total--;
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (option != 4);

    return 0;
}
