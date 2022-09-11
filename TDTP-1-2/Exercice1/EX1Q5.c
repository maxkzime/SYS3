#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * 5- Ecrire un programme qui ouvre un fichier ./res.data en lecture,
 * et qui lit 10 caractères à partir du 30ème caractère,
 * puis les affichent sur la sortie standard (c’est à dire l’écran, fd = 1).
 */


int main(int argc, char* argv[])
{
    // Valeur de retour.
    int returnValue = 0;


    // Ouverture du fichier à lire.
    int df = open("./res.data", O_RDONLY);

    if(df != -1)
    {
        lseek(df, 30, SEEK_SET);

        int charRead = 0;

        char buf[1];
        int lu = 1;

        while(lu != 0 && charRead < 10)
        {
            lu = read(df, buf, 1);
            write(1, buf, lu);

            charRead++;
        }

        close(df);
    }
    else
    {
        returnValue = 1;
    }

    return(returnValue);
}
