#include <stdio.h>
#include <stdlib.h>
typedef struct{
  int nbsom;
  int nbarc;
  int **matrice;
}MatrIncidente;
typedef struct{
  int nbsom;
  int **matrice;
}MatriceAdjacence;
/* 5 Derivatives of adjacence matrix*/
/*File de successeur*/
typedef struct{
  int nbsom;
  int nbarc;
  int *fs, aps;
}FileSucc;
/*Liste d'adjacence*/
typedef struct{
  int somsuc;
  int link;
}Liste;
typedef struct{
  int nbsom;
  Liste* tabadj;
}ListeAdjacence;
/*Liste principale*/
typedef struct cellule ListeSuccesseur;
typedef struct listePrincipale *ListePrincipale;
struct listePrincipale{
  int nbSom;
  ListePrincipale suivant; //suivant liste principale
  ListeSuccesseur succeseurs; // suivant liste succeseur
};
struct cellule{
  ListePrincipale successeur;
  ListeSuccesseur suivant;
};
/*Liste  creuse*/
typedef struct cellulecreuse{
  int sommetsuccesseur;
  int sommetpredecesseur;
  struct cellulecreuse* suivant;
  struct cellulecreuse* predecesseur;
}*ListeCreuse;
typedef struct matrice{
  ListeCreuse* tabsuccesseur;
  ListeCreuse* tabpredecesseur;
}MatriceCreuse;
/*Derivatives of oncidece matrix*/
/*Representation colone par colone*/
typedef struct{
  int nbsom;
  int nbarcs;
  int *alpha;
  int *beta;
}Matricecolcol;
/*representation ligne par ligne*/
typedef struct{
  int nbSom;
  int nbArcs;
  int *aps;
  int *fs;
  int *as;
}matricelignlign;
