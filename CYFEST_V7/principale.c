#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "connexion.c"
#include "integration.h"
Salle liste_salle[100]; // Déclaration d'un tableau de 100 structures Salle
Concert liste_concert[100]; //Declaration d'un tableau de 100 structure de Concert
#include "enregistrement.c"
#include "methode.c"
#include "modemanager.h"
#include "modefestivalier.h"

int intergrerfichiersalle() {
  /*Fonction permettant d'integrer dans le programme tout les fichier d'un dossier en l'occurence le fichier des salles*/
  const char *dossier = "FichierTexte";
  DIR *dir;
  struct dirent *ent;
  char fichier[256]; 
  dir = opendir(dossier);
  if (dir == NULL) {
    perror("Impossible d'ouvrir le dossier");
    return 1;
  }

  // Parcourir les fichiers et exécuter le code
  int i = 0;
  while ((ent = readdir(dir)) != NULL) {
    if (ent->d_type == DT_REG) {
      snprintf(fichier, sizeof(fichier), "%s/%s", dossier, ent->d_name);
       liste_salle[i] = integrersalle(fichier);
      i++;
    }
  }
  closedir(dir);
  return 0;
}

int intergrerfichierconcert() {
  /*Fonction permettant d'integrer dans le programme tout les fichier d'un dossier en l'occurence le fichier des concert*/
  const char *dossier = "FichierTexteConcert";
  DIR *dir;
  struct dirent *ent;
  char fichier[256]; 
  dir = opendir(dossier);
  if (dir == NULL) {
    perror("Impossible d'ouvrir le dossier");
    return 1;
  }

  // Parcourir les fichiers et exécuter le code
  int i = 0;
  while ((ent = readdir(dir)) != NULL) {
    if (ent->d_type == DT_REG) {
      snprintf(fichier, sizeof(fichier), "%s/%s", dossier, ent->d_name);
       liste_concert[i] = integrerconcert(fichier);
      i++;
    }
  }
  closedir(dir);
  return 0;
}


void menu(){
  /*Fonction princiaple permettant l'affichage principale et la redirection*/
  int demandemode;
  printf("\n\n\n\n\n\n\n\n\n\n\n\n1. Mode manager \n2. Mode Festivalier\n3. Quitter\n\nChoisissez le mode voulu (1,2)  :\n");
  scanf("%d", &demandemode);
  if (demandemode==1){
    if (connexion()==0){
         ModeManager();
         menu();
    }
    else{
      menu();
    }
  }
  else if (demandemode==2){
    ModeFestivalier();
    menu();
  }
  else if (demandemode==3){
    exit(0);
  }
  else{
    printf("\n\n\n\n\nEntrée non reconnu\n\n\n\n\n\n\n");
    sleep(2);
    menu();
  }
}

int main() {
//initialise les nom des structure Salle en "Rien"
for (int i = 0; i < 100; i++) {liste_salle[i].nom = "Rien";};
for (int i = 0; i < 100; i++) {liste_concert[i].nom = "Rien";};
  intergrerfichiersalle();
  intergrerfichierconcert();
  printf("Cy-fest\n");
  sleep(3);
  menu();
  return 0;
}


