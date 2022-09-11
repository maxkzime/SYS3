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

    if(argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            /*** Ajout par rapport à la commande cat -n ***/
            // Réinitialisation pour chaque fichier du nombre de lignes.
            lNb = 0;

            printf("\n\n");
            /*** ^^^ Ajouts par rapport à la commande cat -n ^^^ ***/

            // Ouverture du fichier à lire.
            int df = open(argv[i], O_RDONLY);

            if(df != -1)
            {
                IncrementLine();
                printf("%s", lineNb);

                char buf[1];

                int lu = read(df, buf, 1);

                write(1, buf, lu);

                while(lu != 0)
                {
                    lu = read(df, buf, 1);

                    write(1, buf, lu);

                    if(buf[0] == '\n')
                    {
                        IncrementLine();
                        printf("%s", lineNb);
                    }
                }

                close(df);
            }
            else
            {
                //cat: error.txt: No such file or directory
                printf("Impossible d'ouvrir le fichier : %s\n", argv[i]);
                returnValue = 1;
            }
        }

    }
    else if(argc == 1)
    {
        char charBuf[1];
        charBuf[0] = '\0';

        char wordBuf[256];
        int letterVal = 0;

        int lu;
        int octSize = 0;

        while(1)
        {
            lu = read(0, charBuf, 1);

            if(charBuf[0] != '\0')
            {
                if(charBuf[0] == '\n')
                {
                    IncrementLine();
                    printf("%s", lineNb);

                    write(1, wordBuf, octSize);
                    printf("\n");

                    letterVal = 0;

                    memset(wordBuf, 0, 255);
                }
                else
                {
                    octSize += lu;

                    wordBuf[letterVal] = charBuf[0];
                    letterVal++;
                }
            }
        }
    }


    return(returnValue);
}
