#include "structures.h"
/*
--------------------------------------------------------------------------------
TOOLS DEFINITION
--------------------------------------------------------------------------------
*/
/*Memory allocation*/
void array_memAllocation(int size, int** matrice){
  *matrice=malloc(sizeof(int)*size);
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
/*insert element in linked list*/
Liste init_list(){
  return NULL;
}
Liste new_node(int e){
  Liste node=(Liste)malloc(sizeof(struct cellule));
  node->sommetAdja=e;
  return node;
}
Liste last_node(Liste liste){
  Liste current,last;
  current=liste;
  while(current!=NULL){
    last=current;
    current=current->suivant;
  }
  return last;
}
void push(int e, Liste* liste){
  Liste node=new_node(e);
  node->suivant=*liste;
  *liste=node;
}
void push_back(int sommet, Liste* liste){
  Liste node;
  Liste last=(Liste)malloc(sizeof(struct cellule));
  if(*liste==NULL){
    push(sommet, liste);
  }else{
    node=new_node(sommet);
    last=last_node(*liste);
    node->suivant=NULL;
    last->suivant=node;
  }
}
void liste_traversal(Liste liste){
  if(liste!=NULL){
    printf("%d ->", liste->sommetAdja);
    liste_traversal(liste->suivant);
  }
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
void liste_successeur_chainee(int** matrice,int row, int column, int s, Liste* succeseurs){
  int i=0;
  Liste* liste;
  for(int t=0; t<row; t++){
    if(matrice[s][t]==1){
      push_back(i, succeseurs);
    }
    i++;
  }
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
  Liste successeurs=init_list();
  for (int i = 0; i < g.nbSommet; i++) {
    printf("succeseur: %d:",i);
    liste_successeur_chainee(g.matrice, g.nbSommet, g.nbSommet,i,&successeurs);
    liste_traversal(successeurs);
    printf("\n");
    successeurs=init_list();
  }
  array_2dmemAllocation(mi.nbSommet,mi.nbArcs, mincindent);
  for(int row=0; row<mi.nbSommet; row++){
    for(int column=0; column<mi.nbArcs; column++){
      mincindent[row][column]=0;
    }
  }
  for(int row=0; row<mi.nbSommet; row++){
    for(int column=0; column<mi.nbArcs; column++){
      printf("%d",mincindent[row][column]);
    }
    printf("\n");
  }
  return 0;
}
