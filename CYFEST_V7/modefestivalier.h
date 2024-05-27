#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>



void ModeFestivalier(){
  /*Fonction principale du mode festivalier permettant d'afficher le menu de selection*/
   int ecart = 0;
        //affichage des salle
        printf("\033[31m\n\n\n\n\n\n   Nom         Artiste         hdebut    hfin        Salle  \n\033[0m");
        for (int i = 0; i <= 100; i++) {
          if (liste_concert[i].nom != "Rien"){
            printf("%d  %s",i+1,strtok(liste_concert[i].nom, "\n"));
            int longueur = strlen(liste_concert[i].nom);
            for (int j = 0;j <= 12-longueur; j++){printf(" ");}

            printf("%s",strtok(liste_concert[i].artiste, "\n"));
            int longueur_ = strlen(liste_concert[i].artiste);
            for (int j = 0;j <= 12-longueur_; j++){printf(" ");}

             printf("     %dh       %dh       %s\n",liste_concert[i].hdebut,liste_concert[i].hfin,liste_concert[i].salle);
          }
          else{
            ecart++;
            if (ecart == 1){break;}
          }
        };
    int demandeconcert;
    printf("\n\n0. Menu\n");
    while (getchar() != '\n');
    scanf("%d", &demandeconcert);
    if (demandeconcert == 0) {
      return;
    }  
    else if (liste_concert[demandeconcert].nom != "Rien"){
      affichage(demandeconcert);
    }
    else{
      printf("Entrée invalide.\n");
      sleep(1);
      ModeFestivalier();
  }
}









   