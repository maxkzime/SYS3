#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


/* 
 * 1- Ecrire en C un programme qui commence par un appel de fork() pour dupliquer le processus
 * initial, le père, pour obtenir un fils.
 * Le père et le fils ont ensuite le même comportement.
 * Ils ouvrent le fichier "./test.data" puis y lisent 10 caractères et les affichent sur la sortie standard
 * (écran) après avoir affiché leur identité. 
 * Sortie :
    PID : 15652 : Test pour 
    DPID : 15653 : Test pour 

 * Effectuer ensuite le fork() juste avant la lecture. 
 * Sortie : 
    PID : 15746 : Test pour 
    DPID : 15747 : l'exercice


 * Répéter l'exécution plusieurs fois et déterminer quels sont les caractères lus par le processus père et le processus fils.
 
 PID : 10875 :  fait à 1
DPID : 10876 : 5:20. Je d

Le fils lit à partir du 30+10 caractère


fork avant l'ouverture du fichier :

PID : 11044 :  fait à 1
DPID : 11045 :  fait à 1

les deux processus applique le lseek
 */


 int main(int argc, char * argv[])
 {
    fork();

    int fdr = open("./test.data", O_RDONLY);

   if(fdr != -1)
   {
   	lseek(fdr, 30, SEEK_CUR);
      //fork();

      // Affichage PID
      char s[12];
      sprintf(s,"%d", getpid());

      write(1, "PID : ", strlen("PID : "));
      write(1, s, strlen(s));
      write(1, " : ", strlen(" : "));

      // Affichage 10 caractères du fichier "./test.data"
      char buf[80];
      int lu = read(fdr, buf, 10);

      write(1, buf, lu);
      write(1, "\n", '\n');
   }
   else{
   	return(1);
   	}
   
   return(0);
}
