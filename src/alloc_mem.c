#include "../header/header.h"
/*__Allocation mémoire__*/
// Allocation mémoire d'un tableau et libération
/**
Erreur alloc tab
*/
void erreur_alloc_mem(){
  perror("\nErreur allocation memoire\n");
}
void alloc_mem_tab(int nbElt, int **tab) {
  *tab =(int*)malloc(sizeof(int)*nbElt);
  if (*tab==NULL) {
    erreur_alloc_mem();
  }
}
void lib_mem_tab(int tab[]) {
  free(tab);
  tab=NULL ;
}
// Allocation mémoire d'une matrice
void alloc_mem_matrice(int nblignes, int nbcolones, int **mat) {
  mat=malloc(sizeof(int*)*(nblignes+1));
  if (mat==NULL) {
    erreur_alloc_mem();
  }
  for(int je=0; je < (nblignes + 1); je++) {
    mat[je]=malloc(sizeof(int)*(nbcolones+1));
    if (mat[je]==NULL) {
      erreur_alloc_mem();
    }
  }
}
// Allocation mémoire d'une Liste Adjacentes
ListeAdjacence alloc_mem_liste_adjacence(int n) {
  ListeAdjacence la;
  la.nbSommet=n;
  la.tabAdj=(Liste*)malloc(sizeof(Liste)*n);
  return la;
}
// Allocation mémoire d'un File de successeur christou
Filesuccesseur alloc_mem_file_successeur(int n, int p, int tailleFs){
  Filesuccesseur fs;
  fs.nbSommet=n;
  fs.nbarcs=p;
  alloc_mem_tab(n+1,&fs.aps);
  alloc_mem_tab(tailleFs, &fs.fs);
  return fs;
}
// Alllocation memoire tableau de listes des successeurs et prédécesseurs
ListeAdjSuccPred alloc_mem_liste_succ_pred(int n) {
  ListeAdjSuccPred lsp ;
  lsp.nbsommet = n ;
  lsp.tabAdjSP =malloc(sizeof(ListePredSuc)*n);
  return lsp ;
}
/*Allocation memoire Pile */
Pile Alloc_mem_pile(int hM) {
	Pile p;
	p.hautMax = hM;
	p.tab = malloc(hM * sizeof(int));
	return p;
}
