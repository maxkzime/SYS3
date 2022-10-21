/*
3- Utilisation de sleep() :
modifier le programme C précédent afin que chacun des fils attende 5 
secondes avant de se terminer.
Chacun affichera un message avant et après l’attente.
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
        pid_t pid = getpid();

        printf("\n Je suis le premier fils, ppid = %d, pid = %d, primitive = %d  \n",
            getppid(), pid, n);


        printf("\n Je suis le premier fils, pid = %d. Et je vais commencer à attendre. \n ",
            pid);

        sleep(5);

        printf("\n Je suis le premier fils, pid = %d. Et j'ai fini d'attendre. \n ",
            pid);
    }
    // Sinon on est dans le père.
    else
    {
        // Création deuxième fils.
        n = fork();

        // Si l'on est dans le fils.
        if(n == 0)
        {
            pid_t pid = getpid();

            printf("\n Je suis le deuxième fils, ppid = %d, pid = %d, primitive = %d  \n",
                getppid(), pid, n);
            

            printf("\n Je suis le second fils, pid = %d. Et je vais commencer à attendre. \n ",
                pid);

            sleep(5);

            printf("\n Je suis le second fils, pid = %d. Et j'ai fini d'attendre. \n ",
                pid);
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

    return(0);
}



/*

Retour console:


 Je suis le père, ppid = 9613, pid = 13204, primitive = 13206  

 Je suis le premier fils, ppid = 13204, pid = 13205, primitive = 0  

 Je suis le premier fils, pid = 13205. Et je vais commencer à attendre. 

 Je suis le deuxième fils, ppid = 13204, pid = 13206, primitive = 0  

 Je suis le second fils, pid = 13206. Et je vais commencer à attendre. 
 
 
 Je suis le premier fils, pid = 13205. Et j'ai fini d'attendre. 
 Je suis le second fils, pid = 13206. Et j'ai fini d'attendre. 
  
 Mon premier fils 13205 est mort. 

 Mon second fils 13206 est mort. 

 Adieu. 
 
*/