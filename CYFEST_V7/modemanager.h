#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>



int affichage(int numerosdesalledanslaliste){
  //fonction permettant d'afficher une salle rangé par rangé
  printf("\033[32m              Scene %d\n   _____________________________\n\033[0m",numerosdesalledanslaliste);
  for (int k = liste_salle[numerosdesalledanslaliste].nombresiegeA/15;k>=1;k--){
    printf("\033[34mRA%d 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n",liste_salle[numerosdesalledanslaliste].nombresiegeA/15-k+1);
  };
    for (int k = liste_salle[numerosdesalledanslaliste].nombresiegeB/15;k>=1;k--){
    printf("\033[37mRB%d 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n",liste_salle[numerosdesalledanslaliste].nombresiegeB/15-k+1);
  };
    for (int k = liste_salle[numerosdesalledanslaliste].nombresiegeC/15;k>=1;k--){
    printf("\033[31mRC%d 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n\033[0m",liste_salle[numerosdesalledanslaliste].nombresiegeC/15-k+1);
  };
  int demandesortie;
  printf("\nTaper 0 pour quitter\n");
  scanf("%d",&demandesortie);
  if (demandesortie == 0){
    return 0;
  }
  else{
    return 0;
  }
}

void ModeManager(){
  /*Fonction principale du mode manager permettant d'afficher le menu( avec les salles disponible)*/
    char demandesalle;
    int ecart = 0;
    //affichage des salle
    printf("\033[31m\n\n\n\n\n\n      Nom      Sieges A  Sieges B   Sieges C    Statut    Fosse   \n\033[0m");
    for (int i = 0; i <= 100; i++) {
      if (liste_salle[i].nom != "Rien"){
        printf("%d   %s",i+1,strtok(liste_salle[i].nom, "\n"));
        int longueur = strlen(liste_salle[i].nom);
        for (int j = 0;j <= 12-longueur; j++){printf(" ");}
        printf("%d          %d        %d",liste_salle[i].nombresiegeA,liste_salle[i].nombresiegeB,liste_salle[i].nombresiegeC);
        if (liste_salle[i].statut == 1){printf("       Occupé    ");}else{printf("       Vide      ");};
        if (liste_salle[i].fosse == 1){printf("Avec\n");}else{printf("Sans\n");};
      }
      //empeche d'afficher une salle de trop avec un ecart au dernier element de la liste
      else{
        ecart++;
        if (ecart == 1){
          break;
        }
      }
    };
    printf("\nA. Crée une salle\nB. Supprimer une salle\nC. Attribuer un concert\nD. Quitter\n");
  //demande utilisateur
    while (getchar() != '\n');
    scanf("%c", &demandesalle);
    if (demandesalle == 'A'){
      methodecreationsalle();
      ModeManager();
      exit(0);
    }
    else if (demandesalle == 'B'){
      methodesupprimersalle();
      ModeManager();
      exit(0);
    }
    else if (demandesalle == 'C'){
      //Attribuer un concert
      methodeattributionconcert();
      ModeManager();
      exit(0);
    }
    else if (demandesalle == 'D'){
      //retour au menu
      exit(0);
    }
    else{
      int demandesalleint = demandesalle -48;
      if (liste_salle[demandesalleint].nom != "Rien"){
        affichage(demandesalleint-1);
      }
      else{
        printf("\n\n\n\n\nEntrée invalide.\n%d",demandesalleint);
        sleep(1);
        ModeManager();
        exit(0);
      }
    }
  }

























