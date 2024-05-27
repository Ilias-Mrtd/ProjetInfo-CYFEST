#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>



void methodeattributionconcert(){
  //methode permettant de recuperer les information pour l'attribution d'un concert
  char* demandesalleattribution[20],demandeartiste[20],demandenomconcert[20];
  int demandehdebut, demandehfin,demandeprixA,demandeprixB,demandeprixC = 0;
  printf("Quelle salle voulait vous utiliser pour votre concert : \n");
  while (getchar() != '\n');
  scanf("%s",&demandesalleattribution);
  printf("Quelle est le nom du concert  :  \n");
  while (getchar() != '\n');
  scanf("%s",&demandenomconcert);
  printf("Quelle est le nom de l'artiste : \n");
  while (getchar() != '\n');
  scanf("%s",&demandeartiste);
  printf("Quelle est l'heure du debut (heure sans minutes): \n");
  while (getchar() != '\n');
  scanf("%d",&demandehdebut);
  printf("Quelle est l'heure de fin (heure sans minutes): \n");
  while (getchar() != '\n');
  scanf("%d",&demandehfin);
  printf("Quelle Prix pour la zone A : \n");
  while (getchar() != '\n');
  scanf("%d",&demandeprixA);
  printf("Quelle prix pour la zone B : \n");
  while (getchar() != '\n');
  scanf("%d",&demandeprixB);
  printf("Quelle prix pour la zone C : \n");
  while (getchar() != '\n');
  scanf("%d",&demandeprixC);
  //verification de la bonne attribution 
  for (int i = 0; i <= 99; i++) {
    if (strcmp(demandesalleattribution , liste_salle[i].nom) == 0 && liste_salle[i].statut == 0){
      liste_salle[i].statut = 1;
      char* sallesanstxt[20];
      strcpy(sallesanstxt, demandesalleattribution);
      enregistrersalle(sallesanstxt,strcat(demandesalleattribution, ".txt"),liste_salle[i].nombresiegeA,liste_salle[i].nombresiegeB,liste_salle[i].nombresiegeC,1,liste_salle[i].fosse);
      enregistreconcert(demandenomconcert,demandeartiste,demandesalleattribution,demandehdebut,demandehfin,demandeprixA,demandeprixB,demandeprixC);
      printf("\n\n\nLe concert est bien attribuer");
      sleep(2);
      return;
    }
  }
    printf("Probleme lors de l'attribution\n\n\n");
    sleep(2);
}

void methodecreationsalle(){
  //methode permettant de recuperer les information necessaire a la creation d'une salle
  char* nom[20], nomtxt[20];
  int demandenombresiegeA =0, demandenombresiegeB=0, demandenombresiegeC=0, demandenombresiegetotal = 0;
  bool demandefosse;
  printf("Entrer le nom de la salle \n");
  scanf("%s",&nom);
  printf("Entrer le nombre de places total dans la salle : (les rangée sont de 15 personnes)\n");
  while (getchar() != '\n');
  scanf("%d",&demandenombresiegetotal);
  printf("Y a t-il une fosse dans votre salle ? (1 pour oui, 0 pour non) \n");
  while (getchar() != '\n');
  scanf("%d",&demandefosse);
  if (demandefosse == 1){
    printf("Combien y a t-il de personne debout dans la fosse :  \n");
    while (getchar() != '\n');
      scanf("%d",&demandenombresiegeA);
  }
  else{
       printf("Combien y a t-il de personne assise dans la zone A  :  \n");
      while (getchar() != '\n');
      scanf("%d",&demandenombresiegeA);
  }
  printf("Combien y a t-il de personne assise dans la zone B :  \n");
  scanf("%d",&demandenombresiegeB);
  while (getchar() != '\n');
  //calcule nombre siege zone C
  int difference = demandenombresiegetotal - (demandenombresiegeA + demandenombresiegeB);
  demandenombresiegeC = -(demandenombresiegetotal + difference);
  //verification correcte rengée et siege
  if (demandenombresiegeA % 15 != 0 || demandenombresiegeB % 15 != 0 || demandenombresiegeC % 15 != 0 ){
    printf("Erreur lors de la creation de la salle");
  }
  else{
    printf("\n\n\nLa salle a bien été crée\n\n\n");
    sleep(2);
    char* nomSalle[30];
    strcpy(nomSalle, nom);
    enregistrersalle(nomSalle,strcat(nom, ".txt"),demandenombresiegeA,demandenombresiegeB,demandenombresiegeC,0,demandefosse);
  }
}

void methodesupprimersalle() {
  //methode permettant des receuillir les information pour supprimer une salle
  char demandesallesupprimer[256];
  printf("Entrez le nom de la salle à supprimer : \n");

  // Utiliser getchar() pour vider le buffer avant de lire l'entrée
  while (getchar() != '\n');
 
  // Lire l'entrée de l'utilisateur
  scanf("%255s", demandesallesupprimer); // Limiter la lecture à 255 caractères
  printf("Salle à supprimer : %s\n", demandesallesupprimer);
 
  for (int i = 0; i < 100; i++) {
    if (strcmp(demandesallesupprimer, liste_salle[i].nom) == 0) {
      char fichierNom[256];
     
      // Construire le nom de fichier en utilisant snprintf
      snprintf(fichierNom, sizeof(fichierNom), "FichierTexte/%s.txt", liste_salle[i].nomtxt);
     
      // Vérification avant la suppression
      printf("Suppression du fichier : %s\n", fichierNom);
     
      // Appeler la fonction supprimersalle
      supprimersalle(fichierNom);
     
      printf("Salle %s supprimée avec succès.\n", demandesallesupprimer);
      return; // Sortir de la fonction après suppression
    }
  }
 
  printf("Salle %s non trouvée.\n", demandesallesupprimer);
}