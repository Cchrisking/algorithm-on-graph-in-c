#include<stdio.h>
/*matrice d'adjacence*/
typedef struct{
  int nbsommet;
  int nbarcs;
  int *fs;
  int *aps;
}Filesuccesseur;
/*representation chainée*/
typedef struct cellule{
  int somsucc;
  sctruct cellule* suivant;
}*Liste;
typedef struct{
  int nbsommet;
  Liste *tabAdj;
}ListeAdjacence;
/*Liste adjacence successeurs & predecesseurs*/
typedef struct cellule_adjacence{
  int somAdj;
  struct cellule_adjacence *suivant;
}*Liste_sp;//sp: successeurs & predecesseurs
typedef struct{
  Liste_sp lsuccesseur;
  Liste_sp lpredecesseur;
}Liste_succpred;
typedef struct{
  int nbsommet;
  Liste_succpred *tabSp;
}Liste_adj_succpred;
