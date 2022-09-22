#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


/* 
 * 1- Ecrire en C un programme qui commence par un appel de fork() pour dupliquer le processus
 * initial, le père, pour obtenir un fils.
 * Le père et le fils ont ensuite le même comportement.
 * Ils ouvrent le fichier "./test.data" puis y lisent 10 caractères et les affichent sur la sortie standard
 * (écran) après avoir affiché leur identité. 
 * Sortie :
    PID : 15652 : Test pour 
    DPID : 15653 : Test pour 

 * Effectuer ensuite le fork() juste avant la lecture. 
 * Sortie : 
    PID : 15746 : Test pour 
    DPID : 15747 : l'exercice


 * Répéter l'exécution plusieurs fois et déterminer quels sont les caractères lus par le processus père et le processus fils.
 */


 int main(int argc, char * argv[])
 {
    //fork();

    int fdr = open("./test.data", O_RDONLY);

    if(fdr != -1)
    {
        fork();

        char s[12];
        sprintf(s,"%d", getpid());

        write(1, "PID : ", strlen("PID : "));
        write(1, s, strlen(s));
        write(1, " : ", strlen(" : "));

        char buf[80];
        int lu = read(fdr, buf, 10);

        write(1, buf, lu);
        write(1, "\n", '\n');
    }
 }