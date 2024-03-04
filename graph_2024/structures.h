#include <stdio.h>
#include <stdlib.h>
typedef struct{
  int nbsom;
  int nbarc;
  int **matrice;
}MatrIncidente;
typedef struct{
  int nbsom;
  int **matrice
}MatriceAdjacence;
/* 5 Derivatives of adjacence matrix*/
typedef struct{
  int nbsom;
  int nbarc;
  int *fs, aps;
}FileSucc;
typedef struct{
  int somsuc;
  int link;
}Liste;
typedef struct{
  int nbsom;
  Liste* tabadj;
}ListeAdjacence;
