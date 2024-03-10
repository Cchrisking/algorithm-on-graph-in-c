#include "structures.h"
/*
--------------------------------------------------------------------------------
TOOLS DEFINITION
--------------------------------------------------------------------------------
*/
/*Memory allocation*/
void array_memAllocation(int size, int** matrice){
  matrice=malloc(sizeof(int)*size);
  if(*matrice==NULL){
    printf("Array memory allocation failed\n");
  }else{
    printf("succesfull array memory allocation 1D\n");
  }
}
void array_2dmemAllocation(int row, int column, int** matrice){
  array_memAllocation(row,matrice);
    for(int l=0; l<row; l++){
      printf("succesfull 2D alocation for row %d\n", l);
      array_memAllocation(column, &matrice[l]);
    }
  }
int* allocate_array(int size){
  int* array=malloc(sizeof(int)*size);
  return array;
}
/*
--------------------------------------------------------------------------------
END OF TOOLS DEFINITION
--------------------------------------------------------------------------------
*/
MatriceAdjacence g;
int isloop(MatriceAdjacence g, int n){
  if(n<0){
    return 0;
  }
  if(g.matrice[n][n]==1){
      return 1;
    }else{
      return isloop(g, n-1);
    }
}
int* liste_succsseur(MatriceAdjacence g, int s){
  int n=g.nbSommet;
  int *liste=malloc(sizeof(int)*(n+1));
  int i=0;
  for(int t=0; t<n; t++){
    if(g.matrice[s][t]==1){
      liste[i]=t;
      i+=1;
    }
  }
  return liste;
}
int*  liste_predecesseur(MatriceAdjacence g, int s){
  int n=g.nbSommet;
  int* listep=malloc(sizeof(int)*(n+1));
  int i=0;
  for(int t=0; t<n; t++){
    if(g.matrice[t][s]==1){
      listep[i]=t;
      i+=1;
    }
  }
  return listep;
}
int main(int argc, char const *argv[]) {
  MatriceAdjacence g;
  MatrIncidente mi;
  mi.nbSommet=4;
  mi.nbArcs=5;
  int** matrice;
  int** mincindent;
  g.nbSommet=3;
  /*
  -----------------------------------------------------------------------------
  Memmory allocation for arrays
  -----------------------------------------------------------------------------
  */
  matrice=malloc(sizeof(int*)*g.nbSommet);
  for(int row=0;row<g.nbSommet;row++){
    matrice[row]=allocate_array(g.nbSommet);
  }
  mincindent=malloc(sizeof(int*)*mi.nbSommet);
  for(int row=0;row<mi.nbSommet;row++){
    matrice[row]=allocate_array(mi.nbArcs);
  }
  printf("Memory allocation succesfull !\n");
  matrice[0][0]=1;
  matrice[0][1]=1;
  matrice[0][2]=1;
  matrice[1][0]=1;
  matrice[1][1]=0;
  matrice[1][2]=0;
  matrice[2][0]=0;
  matrice[2][1]=1;
  matrice[2][2]=0;
  printf("if you can see this it's working you can acceess 2D data!\n");
  g.matrice=matrice;
  printf("worked\n");
  for(int row=0; row<g.nbSommet; row++){
    for(int column=0; column<g.nbSommet; column++){
      printf("[%d][%d]: %d\n", row, column, g.matrice[row][column]);
    }
  }
  if(isloop(g, g.nbSommet-1)){
    printf("is a loop\n");
  }else{
    printf("Is not a loop\n");
  }
  int *liste=liste_succsseur(g, 2);
  for (int i = 0; i < g.nbSommet; i++) {
    printf("succeseur 2 -> %d\n", liste[i]);
  }
  int *listep=liste_predecesseur(g, 1);
  for (int i = 0; i < g.nbSommet; i++) {
    printf("predeseur %d -> 1\n", listep[i]);
  }
  return 0;
}
