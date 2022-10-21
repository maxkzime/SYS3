/*
1- Utilisation de fork(), getpid() getppid() :
écrire un programme en C qui créé deux fils.
Tous les processus (le père et les fils) devront indiquer chacun leurs numéros de processus,
le numéro de leur père et la valeur renvoyée par la primitive de création de processus.
Exécuter le programme plusieurs fois.
Les valeurs affichées et l'ordre d'affichage sont-ils toujours les mêmes ?

 */



#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


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
        }
    }

    return (0);
}



/*

Retour console:

 Je suis le père, ppid = 9613, pid = 12126, primitive = 12128  

 Je suis le premier fils, ppid = 12126, pid = 12127, primitive = 0  

 Je suis le deuxième fils, ppid = 12126, pid = 12128, primitive = 0  

Les valeurs retournées ne sont pas toujours les mêmes.

*/