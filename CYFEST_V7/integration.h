#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LINE_LENGTH 1024
#define NOMBRE_LIGNES 6 
#define NOMBRE_LIGNES_C 8


typedef struct Salle {
  char* nom;
  char* nomtxt;
  int nombresiegeA;
  int nombresiegeB;
  int nombresiegeC;
  bool statut;
  bool fosse;
} Salle;

typedef struct Concert {
  char* nom;
  char* artiste;
  char* salle;
  int hdebut;
  int hfin;
  int prixA;
  int prixB;
  int prixC;
} Concert;
    
  
Concert integrerconcert(char* fichiertxt) {
  /*Fonction qui permet d'integrer dans le code les information d'un concert, elle renvoie en structure de données Concert les informations lu dans le fichier texte mis en argument*/
  char ligne[MAX_LINE_LENGTH];
  char *ligne1, *ligne2, *ligne3, *ligne4, *ligne5, *ligne6, *ligne7, *ligne8; 
  // Allocation de mémoire pour les variables lignes
  ligne1 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne1 == NULL) {
    printf("Erreur d'allocation mémoire\n");
  }
  ligne2 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne2 == NULL) {
    free(ligne1);
    printf("Erreur d'allocation mémoire\n");
  }
  ligne3 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne3 == NULL) {
    free(ligne1);
    free(ligne2);
    printf("Erreur d'allocation mémoire\n");
  }
  ligne4 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne4 == NULL) {
    free(ligne1);
    free(ligne2);
    free(ligne3);
    printf("Erreur d'allocation mémoire\n");
  }
  ligne5 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne5 == NULL) {
    free(ligne1);
    free(ligne2);
    free(ligne3);
    free(ligne4);
    printf("Erreur d'allocation mémoire\n");
  }
    ligne6 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne6 == NULL) {
    free(ligne1);
    free(ligne2);
    free(ligne3);
    free(ligne4);
    free(ligne5);
    printf("Erreur d'allocation mémoire\n");
  }
  ligne7 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne6 == NULL) {
    free(ligne1);
    free(ligne2);
    free(ligne3);
    free(ligne4);
    free(ligne5);
    free(ligne6);
    printf("Erreur d'allocation mémoire\n");
  }
    ligne8 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne6 == NULL) {
    free(ligne1);
    free(ligne2);
    free(ligne3);
    free(ligne4);
    free(ligne5);
    free(ligne6);
    free(ligne7);
    printf("Erreur d'allocation mémoire\n");
  }

  // Ouverture du fichier en mode lecture
  FILE *fichier = fopen(fichiertxt, "r");
  if (fichier == NULL) {
    printf("Erreur d'ouverture du fichier\n");
  }

  // Lecture du fichier et remplissage des variables
  int numeroLigne = 0;
  while (fgets(ligne, MAX_LINE_LENGTH, fichier) != NULL) {
    if (numeroLigne < NOMBRE_LIGNES_C) {
      switch (numeroLigne) {
        case 0:
          strcpy(ligne1, ligne);
          break;
        case 1:
          strcpy(ligne2, ligne);
          break;
        case 2:
          strcpy(ligne3, ligne);
          break;
       case 3:
          strcpy(ligne4, ligne);
          break;
        case 4:
          strcpy(ligne5, ligne);
          break;
        case 5:
          strcpy(ligne6, ligne);
          break;
         case 6:
          strcpy(ligne7, ligne);
          break;
         case 7:
          strcpy(ligne8, ligne);
          break;
      }
      numeroLigne++;
    } else {
      printf("Trop de lignes dans le fichier (dépassement de la limite de %d)\n", NOMBRE_LIGNES_C);
      break;
    }
  }
  // Fermeture du fichier
  fclose(fichier);
  //convertion des variables
  char ligne1a = atoi(ligne1);
  int ligne2a = atoi(ligne2);
  int ligne3a = atoi(ligne3);
  int ligne4a = atoi(ligne4);
  int ligne5a = atoi(ligne5);
  int ligne6a = atoi(ligne6);
  int ligne7a = atoi(ligne7);
  int ligne8a = atoi(ligne8);
  char fichiertxta = atoi(fichiertxt);
  Concert result = {ligne1,ligne2,ligne3,ligne4a,ligne5a,ligne6a,ligne7a,ligne8a};
  return result;
}

Salle integrersalle(char* fichiertxt) {
  /*Fonction qui permet d'integrer dans le code les information d'un salle, elle renvoie en structure de données Salle les informations lu dans le fichier texte mis en argument*/
  char ligne[MAX_LINE_LENGTH];
  char *ligne1, *ligne2, *ligne3, *ligne4, *ligne5, *ligne6; 
  // Allocation de mémoire pour les variables lignes
  ligne1 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne1 == NULL) {
    printf("Erreur d'allocation mémoire\n");
  }
  ligne2 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne2 == NULL) {
    free(ligne1);
    printf("Erreur d'allocation mémoire\n");
  }
  ligne3 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne3 == NULL) {
    free(ligne1);
    free(ligne2);
    printf("Erreur d'allocation mémoire\n");
  }
  ligne4 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne4 == NULL) {
    free(ligne1);
    free(ligne2);
    free(ligne3);
    printf("Erreur d'allocation mémoire\n");
  }
  ligne5 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne5 == NULL) {
    free(ligne1);
    free(ligne2);
    free(ligne3);
    free(ligne4);
    printf("Erreur d'allocation mémoire\n");
  }
    ligne6 = malloc(MAX_LINE_LENGTH + 1);
  if (ligne6 == NULL) {
    free(ligne1);
    free(ligne2);
    free(ligne3);
    free(ligne4);
    free(ligne5);
    printf("Erreur d'allocation mémoire\n");
  }
  // Ouverture du fichier en mode lecture
  FILE *fichier = fopen(fichiertxt, "r");
  if (fichier == NULL) {
    printf("Erreur d'ouverture du fichier\n");
  }

  // Lecture du fichier et remplissage des variables
  int numeroLigne = 0;
  while (fgets(ligne, MAX_LINE_LENGTH, fichier) != NULL) {
    if (numeroLigne < NOMBRE_LIGNES) {
      switch (numeroLigne) {
        case 0:
          strcpy(ligne1, ligne);
          break;
        case 1:
          strcpy(ligne2, ligne);
          break;
        case 2:
          strcpy(ligne3, ligne);
          break;
       case 3:
          strcpy(ligne4, ligne);
          break;
        case 4:
          strcpy(ligne5, ligne);
          break;
        case 5:
          strcpy(ligne6, ligne);
          break;
      }
      numeroLigne++;
    } else {
      printf("Trop de lignes dans le fichier (dépassement de la limite de %d)\n", NOMBRE_LIGNES);
      break;
    }
  }
  // Fermeture du fichier
  fclose(fichier);
  //convertion des variables
  char ligne1a = atoi(ligne1);
  int ligne2a = atoi(ligne2);
  int ligne3a = atoi(ligne3);
  int ligne4a = atoi(ligne4);
  int ligne5a = atoi(ligne5);
  int ligne6a = atoi(ligne6);
  char fichiertxta = atoi(fichiertxt);
  Salle result = {ligne1,fichiertxt,ligne2a,ligne3a,ligne4a,ligne5a,ligne6a};
  return result;
}

