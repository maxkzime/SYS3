#include <string.h>
#include <fcntl.h>
#include <stdio.h>

/*
 * 2- Ecrire un programme en C pg2.c qui utilisera la fonction lire() sans la modifier.
 * Ce programme devra lire à partir d’un fichier ./test.data et devra écrire le résultat dans le fichier
 * ./res.data (sortie d’erreur et sortie standard). 
 * Il est a rappelé que lors de l’ouverture d’un fichier,
 * son descripteur est mis dans la première case libre du tableau de descripteurs de fichiers.
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

int main(int argc, char * argv[])
{
    dup(0);
    dup(1);
    dup(2);

    close(0);
    close(1);

    int fdr = open("./test.data", O_RDONLY);
    int fdv = open("./res.data", O_WRONLY || O_TRUNC);

    dup2(fdv, 2);

    // On remarque que le printf est écrit après les deux write
    lire();

    return(0);
}