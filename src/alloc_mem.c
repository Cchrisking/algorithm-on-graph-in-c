/*__Allocation mémoire__*/
// Allocation mémoire d'un tableau et libération
/**
Erreur alloc tab
*/
void erreur_alloc_mem(){
  perror("\nErreur allocation memoire\n");
}
void alloc_mem_tab(int nbElt, int tab[]) {
  tab = (int)malloc(sizeof(int )*nbElt);
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
  mat=(int**)malloc(sizeof(int)*(nblignes+1));
  if (mat==NULL) {
    erreur_alloc_mem();
  }
  for(int je=0; je < (nblignesg + 1); je++) {
    alloc_mem_ab(nbcolones + 1, &(mat)[i]);
    if ((mat)[i]==NULL) {
      erreur_alloc_mem();
    }
  }
}
// Allocation mémoire d'une Liste Adjacentes
ListAdjacence alloc_mem_liste_adjacence(int n) {
  ListAdjacence la ;
  la.nbsommet=n;
  la.tabAdj=(Liste)malloc(sizeof(Liste)*n);
  return la;
}
// Allocation mémoire d'un File de successeur christou
Filesuccesseur alloc_mem_file_successeur(int n, int p){
  Filesuccesseur fs;
  fs.nbsommet=n;
  fs.nbarcs=p;
  fs.FS=alloc_mem_tab[p];
  fs.APS=alloc_mem_ab(n+1);
  return fs;
}
// Alllocation memoire tableau de listes des successeurs et prédécesseurs
ListAdjSuccPred alloc_mem_liste_succ_pred(int n) {
  ListAdjSuccPred lsp ;
  lsp.nbsommet = n ;
  lsp.tabAdjSP = (ListeSuccPred)malloc(sizeof(ListeSuccPred)*n);
  return lsp ;
}
/*Allocation memoire Pile */
Pile Alloc_mem_pile(int hM) {
	Pile p;
	p.hautMax = hM;
	p.tab = malloc(hM * sizeof(int));
	return p;
}
