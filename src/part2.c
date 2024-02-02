#include "../header/header.h"
int main(int argc, char const *argv[]){
  int **mat;
  alloc_mem_matrice(6,6,mat);
  for (int i= 0; i < 6; i++) {
    for (int j= 0; j < 6; j++){
      mat[i][j]=0;
    }
  }
    mat[1][3] = 1;
    mat[2][1] = 1;
    mat[2][3] = 1;
    mat[2][4] = 1;
    mat[3][4] = 1;
    mat[3][6] = 1;
    mat[5][4] = 1;
    mat[5][6] = 1;
    mat[6][4] = 1;
    MatriceAdj matriceAdjacence;
    matriceAdjacence.matrice=mat;
    matriceAdjacence.nbSommet=6;
    affiche_matrice_adjacence(matriceAdjacence);
  return 0;
}
/*ALLOCATION MEMOIRE*/
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

/*FIN ALLOCATION MEMOIRE*/
/*DEBUT PARCOURS*/
int sommet_suivant(int s, int n, int *visite){
  for (int i = 1; i <= n; i++) {
    if (visite[i] == 0) {
      return i;
    }
  }
  return 0;
}
void parcours_profondeur_matrice_adjacence(int sd, MatriceAdj g){
  int n=g.nbSommet;
  int* visite=(int*)malloc(sizeof(int)*n);
  for(int s=0; s<n; s++){
    visite[s]=0;
  }
  int s=sd;
  int nbSommetVisite=0;
  int finParcours=0;
  /*Traitement*/
  while(finParcours==0){
    //rec_parcours_profondeur_matrice_adjacence(s, visite,nbSommetVisite, g);
    it_parcours_profondeur_adjacence(s,visite,&nbSommetVisite, g);
    if(nbSommetVisite<n){
      s=sommet_suivant(s,n,visite);
    }
  }
}
void rec_parcours_profondeur_matrice_adjacence(int s, int  visite[], int nbSommetVisite, MatriceAdj g){
  visite[s]=1;
  //traiter
  nbSommetVisite+=1;
  for(int t=0; t<s; t++){
    if(!visite[t]){
      rec_parcours_profondeur_matrice_adjacence(t, visite, nbSommetVisite, g);
    }
  }
}
void it_parcours_profondeur_adjacence(int s, int visite[],int* nbSommetVisite,MatriceAdj g){
  Pile p=init_pile();
  p=empiler(s, p);
  int u;
  while(!est_vide_pile(p)){
    u =sommet_pile(p);
    p=depiler(p);
    if(!visite[u]){
      //traite(u)////flag a completer
      *nbSommetVisite=+1;
      visite[u]=1;
      for (int t=0; t<g.nbSommet; t++){
        if(!visite[t]==0 && g.matrice[s][t]==1){
        p=empiler(t,p);
      }
    }
  }
}
}
void it_parcours_largeur_adjacence(int s, int visite[],int* nbSommetVisite, MatriceAdj g){
  File f=init_file(); //flag a completer
  f=enfiler(s, f);////flag a completer
  int u;
  while(!est_vide_file(f)){
    u =sommet_file(f);
    f=defiler(f);
    if(!visite[u]){
      //traite(u)////flag a completer
      nbSommetVisite=+1;
      visite[u]=1;
      for (int t=0; t<g.nbSommet;t++){
        if(!visite[t]==0&& g.matrice[s][t]){
        f=enfiler(t,f);
      }
    }
    }
  }
}
void rec_parcours_profondeur_file_successeur(int s, int  visite[], int nbSommetVisite, Filesuccesseur g){
  visite[s]=1;
  //traiter
  nbSommetVisite+=1;
  for(int t=0; t<s; t++){
    if(!visite[t]){
      rec_parcours_profondeur_file_successeur(t, visite, nbSommetVisite, g);
    }
  }
}
void it_parcours_profondeur_file_successeur(int s, int visite[], Filesuccesseur g){
  Pile p=init_pile(); //flag a completer
  p=empiler(s, p);////flag a completer
  int u,nbSommetVisite=0;
  while(!est_vide_pile(p)){
    u =sommet_pile(p);
    p=depiler(p);
    if(!visite[u]){
      //traite(u)////flag a completer
      nbSommetVisite=+1;
      visite[u]=1;
      /*
      pour t de dernier successeur au premier successeur de u faire{
        if(!visite[t]){
        p=empiler(t,p);
      }
    }
      */
    }
  }
}
void it_parcours_largeur_file_successeur(int s, int visite[], Filesuccesseur g){
  File f=init_file(); //flag a completer
  f=enfiler(s, f);////flag a completer
  int u,nbSommetVisite=0;
  while(!est_vide_file(f)){
    u =sommet_file(f);
    f=defiler(f);
    if(!visite[u]){
      ///traite(u)////flag a completer
      nbSommetVisite=+1;
      visite[u]=1;
      /*
      pour t de dernier successeur au premier successeur de u faire{
        if(!visite[t]){
        f=enfiler(t,f);
      }
    }
      */
    }
  }
}
void rec_parcours_profondeur_liste_adjacence(int s, int  visite[], int nbSommetVisite, ListeAdjacence g){
  visite[s]=1;
  //traiter
  nbSommetVisite+=1;
  for(int t=0; t<s; t++){
    if(!visite[t]){
      rec_parcours_profondeur_liste_adjacence(t, visite, nbSommetVisite, g);
    }
  }
}
void it_parcours_profondeur_liste_adjacence(int s, int visite[], ListeAdjacence g){
  Pile p=init_pile(); //flag a completer
  p=empiler(s, p);////flag a completer
  int u,nbSommetVisite=0;
  while(!est_vide_pile(p)){
    u =sommet_pile(p);
    p=depiler(p);
    if(!visite[u]){
    //  traite(u)////flag a completer
      nbSommetVisite=+1;
      visite[u]=1;
      /*
      pour t de dernier successeur au premier successeur de u faire{
        if(!visite[t]){
        p=empiler(t,p);
      }
    }
      */
    }
  }
}
void it_parcours_largeur_liste_adjacence(int s, int visite[], ListeAdjacence g){
  File f=init_file(); //flag a completer
  f=enfiler(s, f);////flag a completer
  int u,nbSommetVisite=0;
  while(!est_vide_file(f)){
    u =sommet_file(f);
    f=defiler(f);
    if(!visite[u]){
      //traite(u)////flag a completer
      nbSommetVisite=+1;
      visite[u]=1;
      /*
      pour t de dernier successeur au premier successeur de u faire{
        if(!visite[t]){
        f=enfiler(t,f);
      }
    }
      */
    }
  }
}
/*FIN PARCOURS*/
/*DEBUT MATRICE ADJACENCE*/
#include "../header/header.h"
int nombre_sommet(MatriceAdj g){
  return g.nbSommet;
}
/*
Exercice3 1)
un graphe orienté represeter par sa matrice d'adjecence MatriceAdj*/
//a) determiner si la graphe est sans boucle en recursif:
/*pseudo code*/
/*
func boucle(g,n)→Bool
  Début:
    si n=0 Alors
        renvoyer faux 0
    Finsi
    si(g.mat[n][n]) Alors
      renvoyer vraie
    Finsi
    renvoyer boucle(g,n-1)
  FIN
*/
int boucle(MatriceAdj g, int n){
  if(n==0){
    return 0;
  }
  if(g.matrice[n][n]==1){
    return 1;
  }else{
    return boucle(g, n-1);
  }
}
//b)determiner les successeurs d'un sommet donné
/*Pseudo code*/
/*
procedure liste_succsseur(s, g)→vide
  parametre formelle:
  s:sommet(E)
  g:graphe(E) Mtrice adjacence
  Debut:
    pour i variant de 1 à n faire
      n←nbsommet(g)
      si g.mat[s][t]=1 Alors
        //t € Γ(s)
        triter (t)
      Finsi
    Finpour
    FIN
*/
void liste_successeur(MatriceAdj g,int s){
  int n;
  Liste listeSuccesseurs;
  for(int t=0; t<n; t++){
    n=nombre_sommet(g);
    if(g.matrice[s][t]==1){
      insert_triee(t, listeSuccesseurs);
    }
  }
}
//c)b)determiner les predecesseurs d'un sommet donné
void liste_predecesseur(MatriceAdj g,int s){
  int n;
  Liste listePredecesseurs;
  for(int t=0; t<n; t++){
    n=nombre_sommet(g);
    if(g.matrice[t][s]==1){
      insert_triee(t, listePredecesseurs);
    }
  }
}

/*FIN MATRICE ADJACENCE*/
/*DEBUT LISTE SUCCESSEURS*/
#include "../header/header.h"
/*Exercice3
un graphe  represeter par sa file de successeurs

*/
//2)determiner les successeurs d'un sommet donné
/*Pseudo code*/
/*
procedure liste_succsseur_ls(g,s)
PF:
  s:entier(E) sommet
  g:Filesuccesseur
Debut:
  iaps ←g.APS[s]
  nbsucc ←g.APS[s+1]-g.APS[s]
  pour i de 1 a nbsucc faire
    t←g.FS[iaps]
    iaps←iaps+1
    traiter(t)
  Finpour
FIN
*/
void liste_succsseur_ls(Filesuccesseur g,int s){
  int iaps=g.aps[s+1];
  int nombreSuccesseurs=iaps-g.aps[s];
  int t;
  Liste listeSuccesseursFileSuccesseurs;
  for(int i=0; i<nombreSuccesseurs; i++){
    t=g.fs[iaps];
    iaps+=1;
    insert_triee(t, listeSuccesseursFileSuccesseurs);
  }
  printf("\n\t\tListe de successeurs file de successeurs: \n");
  affiche_liste(listeSuccesseursFileSuccesseurs);
}
/*Exercice4*/
/*2
func conv_matAdj_Fs(ma)→Filesuccesseur
  PF:
  ma:MatriceAdj(E)
  Debut:
    n←nbsom(ma)
    p←nbarcs(ma)
    fs←allocSFS(n,p)
    //traiement parcours grobale MatriceAdj
    //parcours ligne par ligne MatriceAdj
    iaps←1
    pour s de 1 à n faire
      fs.APS[s]←iaps
      pour t de 1 à n faire
        si(ma.mat[s][t]=1) Alors
          //t apartient à Γ(s)
          fs.FS[iaps]←t
          iaps←iaps+1
        Finsi
      Finpour
    Finpour
    //ajout sommet virtuelle
    fs.APS[s]←iaps//fs.APS[n+1]←p+1
    renvoyer fs
  Fin
*/
Filesuccesseur conv_matAdj_Fs(MatriceAdj ma){
  int n=ma.nbSommet;
  int p=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(ma.matrice[i][j]==1){
        p++;
      }
    }
  }
  Filesuccesseur fs=alloc_mem_file_successeur(n,p,p);
  /*
  traitement parcours globale MatriceAdj
  parcours ligne par ligne MatriceAdj
  */
  int iaps=0;
  int s;
  for(s=0; s<n; s++){
    fs.aps[s]=iaps;
    for(int t=0; t<n;t++){
      if(ma.matrice[s][t]==1){
        fs.fs[iaps]=t;
        iaps+=1;
      }
    }
  }
  //ajout sommet virtuelle
  fs.aps[s]=iaps;
  return fs;
}
/*DEBUT MATRICE ADJACENCE*/
/*
Exercice3 1)
un graphe orienté represeter par sa matrice d'adjecence MatriceAdj*/
//a) determiner si la graphe est sans boucle en recursif:
/*pseudo code*/
/*
func boucle(g,n)→Bool
  Début:
    si n=0 Alors
        renvoyer faux 0
    Finsi
    si(g.mat[n][n]) Alors
      renvoyer vraie
    Finsi
    renvoyer boucle(g,n-1)
  FIN
*/
//b)determiner les successeurs d'un sommet donné
/*Pseudo code*/
/*
procedure liste_succsseur(s, g)→vide
  parametre formelle:
  s:sommet(E)
  g:graphe(E) Mtrice adjacence
  Debut:
    pour i variant de 1 à n faire
      n←nbsommet(g)
      si g.mat[s][t]=1 Alors
        //t € Γ(s)
        triter (t)
      Finsi
    Finpour
    FIN
*/
/*FIN LISTE SUCCESSEURS*/
/*DEBUT LISTE ADJACENCE*/
#include "../header/header.h"
/*Exercice3*/
//3)determiner le sommet qui possede plus de successeurs
/*Pseudo code*/
/*
func plus_de_succ(g)→entier
  PF:
  g:ListeAdj
  Début:
    //parcours globale du tableau de Listes
    n←nbsommet(g)
    nbSuccMax←null
    pour s de 1 à n faire
      l←g.tab[s]
      nbSucc←longueur[l]
      si nbSucc>nbSuccMax Alors
      nbSuccMax←nbSucc
      sMax←s
      Finsi
    Finpour
    renvoyer sMax
  FIN
*/
int longueur(int s){
  return s+1-s;
}
int plus_de_succ(ListeAdjacence g){
  int n=g.nbSommet;
  int nbSuccMax=0;
  int l,sMax,nbSucc;
  for(int s=0; s<n; s++){
    l=g.tabAdj[s]->somAdj;
    nbSucc=longueur(l);
    if(nbSucc>nbSuccMax){
      nbSuccMax=nbSucc;
      sMax=s;
    }
  }
  return sMax;
}
/*Exercice4*/
/*1
func conv_Fs_matAdj(ma)→ListeAdj
  PF:
    ma:MatriceAdj
  Debut:
    n←nombre_sommet(ma)
    la←allocSLA(n)
    //parcour globale de la liste M.A
    //parcours ligne par ligne
    pour s de 1 à n faire
      la.tab[s]←initL()
      pour t de n à 1 faire
        si ma.mat[s][t]=1 Alors
        la.tab[s]←inser_tete(t,la.tab[s])
        Finsi
      Finpour
    Finpour
    renovyer la
  FIN
*/
/*ListeAdjacence conv_fs_matAdj(MatriceAdj ma){
  int n=ma.nbSommet;
  ListeAdjacence la=alloc_mem_liste_adjacence(n);
  for(int s=0;s<n; s++){
    la.tabAdj[s]=init_liste();
    for (int t = n; t>0;  t--) {
      if(ma.matrice[s][t]==1){
        insert_tete(t,(la.tabAdj[s]));
      }
    }
  }
  return la;
}*/
/*FIN LISTE ADJACENCE*/
