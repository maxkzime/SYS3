/*
2- Utilisation de wait() :
modifier le programme C précédent afin que le père attende la fin
d’exécution de ces deux fils avant de se terminer.
Il affichera un message d’adieu juste avant de se terminer.
 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc , char * argv[])
{
    // Création du premier fils.
    int n = fork();

    // Si l'on  est dans le fils.
    if(n == 0)
    {
        printf("\n Je suis le premier fils, ppid = %d, pid = %d, primitive = %d  \n",
            getppid(), getpid(), n);
    }
    // Sinon on est dans le père.
    else
    {
        // Création deuxième fils.
        n = fork();

        // Si l'on est dans le fils.
        if(n == 0)
        {
            printf("\n Je suis le deuxième fils, ppid = %d, pid = %d, primitive = %d  \n",
                getppid(), getpid(), n);
            
        }
        // Sinon on est dans le père.
        else
        {
            printf("\n Je suis le père, ppid = %d, pid = %d, primitive = %d  \n",
                getppid(), getpid(), n);


            int n1 = wait(0);
            printf("\n Mon premier fils %d est mort. \n", n1);

            int n2 = wait(0);
            printf("\n Mon second fils %d est mort. \n", n2);

            printf ("\n Adieu. \n");
        }
    }

    return (0);
}



/*

Retour console:

 Je suis le père, ppid = 9613, pid = 12757, primitive = 12759  

 Je suis le premier fils, ppid = 12757, pid = 12758, primitive = 0  

 Je suis le deuxième fils, ppid = 12757, pid = 12759, primitive = 0  

 Mon premier fils 12758 est mort. 

 Mon second fils 12759 est mort. 

 Adieu. 

*/