#include <stdio.h>
#include <fcntl.h>

/*
 * 1- Ecrire un programme qui ouvre des fichiers sans jamais les fermer.
 * Combien de fichiers pouvez-vous ouvrir ?
 */


int main(int argc, char* argv[])
{

    int dfa,df = 0;

    while(df != -1)
    {
        dfa = df;
        df =  open("./EX1Q1.txt", O_WRONLY | O_CREAT, 0600);
    }

    dfa++;


    printf("%d\n\n\n", dfa);

    // Found : 1024 on linux and 2048 on windows.

    return(0);

}
