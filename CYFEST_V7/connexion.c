#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>




int connexion() {
  /*Fonction qui permet la connexion avec un retrun 0 pour validée et 1 pour refusé*/
  char demandeuti[50],demandemdp[50],nomUtilisateurFichier[50],motDePasseFichier[50];
  printf("\n\n\n\n\n\n\n\nNom d'utilisateur :  \n");
  scanf("%s", demandeuti);
  printf("Mot de passe :  \n");
  scanf("%s", demandemdp);
  sleep(2);
  //recuperation des deux ligne du fichier "fichiermdp.txt"
  FILE *fichier = fopen("fichiermdp.txt","r");
  fgets(nomUtilisateurFichier, sizeof(nomUtilisateurFichier), fichier);
  nomUtilisateurFichier[strlen(nomUtilisateurFichier) - 1] = '\0';
  fgets(motDePasseFichier, sizeof(motDePasseFichier), fichier);
  motDePasseFichier[strlen(motDePasseFichier) - 1] = '\0';
  fclose(fichier);
  //comparaison des mdp saisi et recuperer
  if (strcmp(demandeuti, nomUtilisateurFichier) == 0 && strcmp(demandemdp, motDePasseFichier) == 0){
    printf("\n\n\n\n\nAcces accepté ...\n");
    sleep(2);
    return 0;
  }
  else{
    printf("\n\n\n\n\nAcces refusé ...\n");
    sleep(2);
    return 1;
  }
}

