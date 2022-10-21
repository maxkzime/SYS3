/*
3- Modifier le programme pour que le fork() ait lieu avant l'ouverture du fichier.
Comparer les résultats.
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc , char * argv[])
{
    int returnValue = 0;

    // Création du fils.
    int n = fork();

    // Ouverture du fichier.
    int df = open("test.data" , O_RDONLY);

    lseek(df, 30, SEEK_SET);

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

 Je suis pid 15948, mon texte: 567890ABC 

 Je suis pid 15949, mon texte: 567890ABC 

Les deux processus ont le même offset dans le fichier.
*/