#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


void supprimersalle(const char *nomfichier) {
  // Fonction pour supprimer un fichier
  if (remove(nomfichier) == 0) {
    printf("Fichier %s supprimé avec succès.\n", nomfichier);
  } else {
    perror("Erreur lors de la suppression du fichier");
  }
}

void enregistreconcert(char* nom, char* artiste, char* salle, int hdebut, int hfin, int prixA, int prixB, int prixC){
  /*Permet de enregistrer/crée un fichier texte avec les arguments mis en fonction*/
  char chemin[1024];
  char nomconcert[20];
  strcpy(nomconcert, nom);
  snprintf(chemin, sizeof(chemin), "FichierTexteConcert/%s", strcat(nom, ".txt"));
 
  FILE *fichier = fopen(chemin, "w");
  if (fichier == NULL) {
      perror("Erreur lors de l'ouverture du fichier");
      return;
  }
 
  fprintf(fichier, "%s\n", nomconcert);
  fprintf(fichier, "%s\n", artiste);
  fprintf(fichier, "%s\n", salle);
  fprintf(fichier, "%d\n", hdebut);
  fprintf(fichier, "%d\n", hfin);
  fprintf(fichier, "%d\n", prixA);
  fprintf(fichier, "%d\n", prixB);
  fprintf(fichier, "%d\n", prixC);
  fclose(fichier);
}

void enregistrersalle(char* nom, char* nomtxt, int A, int B, int C, bool statut, bool fosse){
  /*Permet de enregistrer/crée un fichier texte avec les arguments mis en fonction*/
  char chemin[1024];
  snprintf(chemin, sizeof(chemin), "FichierTexte/%s", nomtxt);
 
  FILE *fichier = fopen(chemin, "w");
  if (fichier == NULL) {
      perror("Erreur lors de l'ouverture du fichier");
      return;
  }
 
  fprintf(fichier, "%s\n", nom);
  fprintf(fichier, "%d\n", A);
  fprintf(fichier, "%d\n", B);
  fprintf(fichier, "%d\n", C);
  fprintf(fichier, "%d\n", statut);
  fprintf(fichier, "%d\n", fosse);
  fclose(fichier);
}

