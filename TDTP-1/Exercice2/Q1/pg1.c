#include <string.h>
#include <stdio.h>
#include <fcntl.h>

/*
 * 1- Ecrire un programme en C appelé pg1.c, utilisant la primitive read, dans lequel une fonction 
 * lire() tente de lire en une seule fois 100 caractères sur l’entrée standard (c’est à dire le clavier, 
 * fd = 0). Elle affichera sur la sortie d’erreur standard (c’est à dire l’écran, fd = 2) le nombre de 
 * caractères effectivement lu, puis les affichera sur la sortie standard (c’est à dire l’écran, fd = 1). 
 */


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


int main(int agrc, char * argv[])
{
    lire();

    return(0);
}
