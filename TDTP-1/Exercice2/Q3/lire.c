#include <string.h>
#include <fcntl.h>
#include <stdio.h>

void lire()
{
    // Lecture des 100 caractères
    char buf[256];
    int lu = read(0, buf, 100);

    // Affichage nombre de caractères effectivement lu, sur la sortie erreur
    char s[4];
    sprintf(s,"%d", lu);
    write(2, s, strlen(s));

    printf("\n\n");

    // Affichage des caractères lus, sur la sortie standard
    write(1, buf, lu);
}