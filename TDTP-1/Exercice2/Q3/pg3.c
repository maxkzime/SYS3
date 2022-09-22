//#include "q3.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void lire();

/* 
 * 3- Placer la fonction lire() dans un fichier lire.c puis la compiler avec la commande cc -c lire.c -o lire.o.
 * On peut utiliser la fonction lire.c depuis un programme pg3.c relié au premier par la commande cc pg3.c lire.o -o pg3.
 * Ici aussi il ne faut pas modifier le programme de la fonction lire().
 * Pareillement à la question précédente, pg3.c devra lire à partir d’un fichier ./test.data et devra écrire le résultat dans le fichier ./res.data
 * (sortie d’erreur et sortie standard). 
 */


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

    lire();

    return(0);
}