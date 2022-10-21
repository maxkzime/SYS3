/*
1- Ecrire en C un programme qui commence par un appel de fork()
pour dupliquer le processus initial, le père, pour obtenir un fils.
Le père et le fils ont ensuite le même comportement.
Ils ouvrent le fichier "./test.data" puis y lisent 10 caractères et les affichent
sur la sortie standard (écran) après avoir affiché leur identité.
Effectuer ensuite le fork() juste avant la lecture.
Répéter l'exécution plusieurs fois et déterminer quels sont les caractères lus
par le processus père et le processus fils.
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

    if(df > 0 && n >= 0)
    {
        char buf [BUFSIZ];
 
        int lu = read(df, buf,10);

        printf("\n Je suis pid %d, mon texte: %s \n", getpid(), buf);
        //write(1, buf, lu);
    }
    else{
        returnValue = -1; 
    }


    return(returnValue);
}



/*

Retour console:
 Je suis pid 14862, mon texte: ABCDEFGHIJ 

 Je suis pid 14863, mon texte: ABCDEFGHIJ 

*/