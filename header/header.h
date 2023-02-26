#include <stdio.h>
#include <stdlib.h>
/*Representation par matrice d'adjancence*/
typedef struct{
  int nbsommet;
  int **matrice;
}MatriceAdj;
typedef struct{
  int nbsommet;
  int nbarret;
  int **matrice;
}MatriceInci_arr;
typedef struct{
  int nbsommet;
  int nbarc;
  int **matrice;
}MatriceInci_arc;
/* Liste de successeurs*/
typedef struct{
  int nbsommet;
  int *fs;
  int *aps;
  //cout si valué
}Filesuccesseur;
/*Liste d'adjancence matrice*/
typedef struct cellule{
  int somSuccesseur;
  struct cellule* suivant;
}Liste;
typedef struct{
  int nbsommet;
  Liste* tabAdj;
}ListeAdj;
/*representation chainnée Liste successeurs predecesseurs*/
typedef struct celluleAdj{
  int somAdj;
  struct celluleAdj* suivant;
}*ListeAdj_;
typedef struct{
  Liste lpred;
  Liste lsucc;
}ListePredSuc;
typedef struct{
  int nbsommet;
  ListePredSuc* tabAdjSP;//SP successeurs predecesseur
}ListeAdjSucPred;
/*Liste pricipale*/
typedef struct cellule *Listesuc;
typedef struct listPrincipale *ListePrincipale;
struct listPrincipale{
  int numsommet;
  ListePrincipale suivant;// suivant Liste somSuccesseur
  Listesuc lsucc;
};
struct cellule{
  ListePrincipale succ;
  /*cout*/
  Listesuc suivant;//suivant liste successeurs
}
