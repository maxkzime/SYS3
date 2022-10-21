/**
 * Exercice 6 : utilisation d’execlp
 * Ecrire un programme en C qui propose à l'utilisateur le menu suivant jusqu'à ce que le choix "quitter"
 * soit sélectionné :
 * 1/ ls
 * 2/ ps -ef
 * 3/ find . -name data -print
 * 4/ quitter
 */


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char buf[BUFSIZ +1];

    int lu;

    do {
        printf("1 -> ls\n2 -> ps -ef\n3 -> find .-name date -print\n4 -> quitter \n");

        lu = read(0, buf, 256);

        int value = atoi(buf);
        switch(value){
            case 1: 
                system("ls");
                break;
            case 2:
                system("ps -ef");
                break;
            case 3:
                system("find .-name data -print");
                break;
            default:
                memset(buf, 0, sizeof buf);
                buf[0] = '4';
            }     
    } while (value != 4);
    
    printf("Fin du programme.\n");
    
    return 0;
}