#include <stdio.h>
#include <stdbool.h>

#define MAX_MUSICAS 100

typedef struct {
    char titulo[50];
    char artista[50];
    bool favoritada;
} Musica;

void mostrarPlaylist(Musica playlist[], int totalMusicas) {
    if (totalMusicas == 0) {
        printf("Playlist vazia.\n");
    } else {
        printf("\n=== Playlist ===\n");
        for (int i = 0; i < totalMusicas; i++) {
            printf("%d. %s - %s", i + 1, playlist[i].artista, playlist[i].titulo);
            if (playlist[i].favoritada) {
                printf(" (Favorita)\n");
            } else {
                printf("\n");
            }
        }
        printf("================\n");
    }
}

int main() {
    Musica playlist[MAX_MUSICAS];
    int totalMusicas = 0;

    strcpy(playlist[totalMusicas].titulo, "Música 1");
    strcpy(playlist[totalMusicas].artista, "Artista 1");
    playlist[totalMusicas].favoritada = true;
    totalMusicas++;

    strcpy(playlist[totalMusicas].titulo, "Música 2");
    strcpy(playlist[totalMusicas].artista, "Artista 2");
    playlist[totalMusicas].favoritada = false;
    totalMusicas++;

    mostrarPlaylist(playlist, totalMusicas);

    return 0;
}