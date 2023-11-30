#include <stdio.h>
#include <string.h>

#define MAX_TITULO 50
#define MAX_ARTISTA 50
#define MAX_ALBUM 50

struct Musica {
    char titulo[MAX_TITULO];
    char artista[MAX_ARTISTA];
    char album[MAX_ALBUM];
};

void editarMusica(struct Musica *musica) {
    printf("Editando %s - %s (%s):\n", musica->titulo, musica->artista, musica->album);
    printf("Novo título: ");
    scanf("%s", musica->titulo);
    printf("Novo artista: ");
    scanf("%s", musica->artista);
    printf("Novo álbum: ");
    scanf("%s", musica->album);

    printf("Informações da música editadas com sucesso.\n");
}

int main() {
    
    struct Musica exemploMusica = {"Musica", "Artista", "Album"};
    editarMusica(&exemploMusica);

  
    printf("Informações Atualizadas: %s - %s (%s)\n", exemploMusica.titulo, exemploMusica.artista, exemploMusica.album);

    return 0;
}
