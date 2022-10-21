/*
2- Dans le père,
positionner le pointeur de lecture sur le 30ème caractère,
par appel de lseek() avant le fork(). 
Quelle est la position des caractères lus par le fils ensuite.
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc , char * argv[])
{
    int returnValue = 0;

    // Ouverture du fichier.
    int df = open("test.data" , O_RDONLY);

    lseek(df, 30, SEEK_SET);

    // Création du fils.
    int n = fork();
    
    if(df > 0 && n >= 0)
    {
        char buf [BUFSIZ];
 
        int lu = read(df, buf,10);

        printf("\n Je suis pid %d, mon texte: %s \n", getpid(), buf);
    }
    else{
        returnValue = -1; 
    }

    return(returnValue);
}



/*

Retour console:

 Je suis pid 15647, mon texte: 567890ABC 

 Je suis pid 15648, mon texte: DEFGHIJKLM

Le fils continue à lire là où le père s'est arrêté, contrairement au cas précédent.
*/