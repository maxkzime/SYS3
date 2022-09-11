#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


/*
 * 3- Réécrire un programme cp simple (copie d’un fichier vers un autre).
 * Pour créer le fichier "cible", n’oubliez pas d’utiliser les flags O_CREAT, O_TRUNC,
 * et le troisième paramètre de open(),
 * pour positionner correctement les droits du fichier nouvellement créé
 * (regardez ce qui se passe si vous ne mettez pas cet argument).
 */


// Ressource qui m'a aidé : https://linux.die.net/man/2/read

int main(int argc, char* argv[])
{
    // Valeur de retour.
    int returnVal = 0;

    // Ouverture du fichier à copier.
	int df = open(argv[1], O_RDONLY);


	if(df != -1)
	{
        // Ouverture du fichier résultat ou création.
        int newF = open(argv[2], O_WRONLY | O_CREAT, 0600);

        char* buf[1];

        int lu = read(df, buf, 1);

        write(newF, buf, lu);

        while(lu != 0)
        {
            lu = read(df, buf, 1);
            write(newF, buf, lu);
        }
		
		close(df);
		close(newF);
	}
	else
	{
        returnVal = 1;
	}

    return(returnVal);
}
