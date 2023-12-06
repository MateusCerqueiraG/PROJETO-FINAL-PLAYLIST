#include <stdio.h>
#include <string.h>
#define MAX_MUSICAS 100

struct Musica {
    char nome[50];
    char artista[50];
    int favorita;
};

struct Playlist {
    char nome[50];
    struct Musica musicas[MAX_MUSICAS];
    int totalMusicas;
};

void adicionarMusica(struct Playlist *playlist, const char *nome, const char *artista) {
    if (playlist->totalMusicas < MAX_MUSICAS) {
        struct Musica novaMusica;
        strcpy(novaMusica.nome, nome);
        strcpy(novaMusica.artista, artista);
        novaMusica.favorita = 0; // Inicialmente, a música não é favorita

        playlist->musicas[playlist->totalMusicas] = novaMusica;
        playlist->totalMusicas++;
        printf("Música '%s' adicionada à playlist '%s'.\n", nome, playlist->nome);
    } else {
        printf("A playlist atingiu o número máximo de músicas.\n");
    }
}

void favoritarMusica(struct Playlist *playlist, int indice) {
	if(indice >= 0 && indice < playlist ->totalMusicas){
		playlist->musicas[indice].favorita = 1;
		
		printf("Música '%s' favoritada na playlist '%s'.\n", playlist->musicas[indice].nome, playlist->nome);
	}else{
		printf("Música não encontrada na playlist.\n");
	}
}

int main() {
    struct Playlist minhaPlaylist;
    strcpy(minhaPlaylist.nome, "Minha Playlist");
    minhaPlaylist.totalMusicas = 0;

    adicionarMusica(&minhaPlaylist, "Musica1", "Artista1");
    adicionarMusica(&minhaPlaylist, "Musica2", "Artista2");

    favoritarMusica(&minhaPlaylist, 0);
    favoritarMusica(&minhaPlaylist, 1);

    return 0;
}
