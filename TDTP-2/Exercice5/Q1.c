/*
1- Utilisation de pipe() et wait() :
modifier le processus de la question 1 de l’exercice 1 pour que le processus père puisse
maintenant permettre à l'utilisateur de rentrer des nombres.
Il transmet à l'aide d'un ou plusieurs tubes les nombres impairs au premier processus fils qu'il a créé et les
nombres pairs au second (on transmettra au choix soit la représentation binaire de chaque entier,
soit la suite de chiffres correspondante).
Quand l'utilisateur rentre la valeur 0, le père envoie également la valeur 0 à ses fils pour leur donner
l'ordre de se terminer, puis, attend qu'ils soient terminés tous les deux avant de se terminer.
Chaque processus laisse un message d'adieux avant sa terminiaison.

*/


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc , char * argv[])
{

    int file_pipe1[2], file_pipe2[2];
    pid_t fork_result , fork_result2; 


    char buf[BUFSIZ + 1];
    int lu = 0;

    if(pipe(file_pipe1) == 0)
    {
        fork_result = fork();

        if(fork_result == -1 )
        {
            fprintf(stderr, "fork failure");
            exit(EXIT_FAILURE);
        }
        else if(fork_result > 0)
        {
            pipe(file_pipe2);

            // Création du deuxième fils.
            fork_result2 = fork();

            // Tant que la valeur entrée n'est pas 0, on lit la valeur entrée et on la distribue au fils correspondant.
            do
            {
                lu = read(0, buf, BUFSIZ);

                if( atoi(buf) % 2 == 0)
                {
                    write(file_pipe1[1], buf, lu);
                }
                else
                {
                    write(file_pipe2[1], buf, lu);
                }            

            }while(atoi(buf) != 0);

            // 0 est impair, on affiche la valeur 0 avant de terminer les processus.
            write(file_pipe2[1], buf, lu);

            // Attend que les fils meurt.
            wait(0);
            wait(0);

            //printf("c'est fini %d" ,lu );
            printf("Je suis le père: %d, et je meurt.", getpid());

        }
        else
        {
            // Tant que la valeur entrée n'est pas 0, on lit puis affiche ce qui est envoyé dans le pipe.
            do
            {
                lu = read(file_pipe2[0], buf, BUFSIZ);

                printf("Je suis le fils: %d, et j'affiche: %s", getpid(), buf);
                //write(1, buf, lu);

            }while(atoi(buf) != 0);
        }      
    }
    else
    {
        // Tant que la valeur entrée n'est pas 0, on lit puis affiche ce qui est envoyé dans le pipe.
        do
        {
            lu = read(file_pipe1[0], buf, BUFSIZ);

            printf("Je suis le fils: %d, et j'affiche: %s", getpid(), buf);
            //write(1, buf, lu);

        }while(atoi(buf) != 0);
    }   

    return(0);
}