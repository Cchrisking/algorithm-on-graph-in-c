#include <stdio.h>
#include <stdlib.h>
typedef struct{
  int nbSommet;
  int nbArcs;
  int **matrice;
}MatrIncidente;
typedef struct{
  int nbSommet;
  int **matrice;
}MatriceAdjacence;
/* 5 Derivatives of adjacence matrix*/
/*File de successeur*/
typedef struct{
  int nbSommet;
  int nbArcs;
  int *fs, aps;
}FileSucc;
/*Liste d'adjacence*/
typedef struct{
  int somsuccesseur;
  int suivant;
}Liste;
typedef struct{
  int nbSommet;
  Liste* tabadj;
}ListeAdjacence;
/*le tableau de listes des successeurs et prédécesseurs*/

/*Liste principale*/
typedef struct cellule *ListeSuccesseur ;
typedef struct listPrincipale *ListePrincipale ;
struct listPrincipale {
int numSom ;
ListePrincipale suivant ;
ListeSuccesseur succeseur ;
};
struct cellule{
  ListePrincipale succeseur ;
  ListeSuccesseur suivant ;
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
  int nbSommet;
  int nbArcs;
  int *alpha;
  int *beta;
}Matricecolcol;
/*representation ligne par ligne*/
typedef struct{
  int nbSommet;
  int nbArcs;
  int *aps;
  int *fs;
  int *as;
}matricelignlign;
/*Memory allocation*/
void array_memAllocation(int n, int** matrice);
void array_2dmemAllocation(int colone, int ligne, int** matrice);
