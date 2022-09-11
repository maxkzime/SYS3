#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


/*
 * 2- Utiliser l’appel système open() pour ouvrir un fichier qui sera spécifié sur la ligne de commande.
 * Lire les 10 premiers octets du fichier avec l’appel système read(),
 * puis les afficher sur la sortie standard en utilisant write().
 * Rappel : 0=stdin, 1=stdout, 2=stderr.
 */


int main(int argc, char* argv[])
{
    int df = open(argv[1], O_RDONLY);

    int returnValue = 0;

	if(df != -1)
	{
		char* buf[256];

        int lu = read(df, buf, 10);

		write(1, buf, lu);
		
		close(df);
	}
    else
    {
        returnValue = 1;
    }


    return(returnValue);
}
