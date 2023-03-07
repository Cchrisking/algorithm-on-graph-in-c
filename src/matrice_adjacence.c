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

/*une matrice d’incidence à une autre représentation par une matrice adjacente*/
MatAdjacence MatIncToMatAdj(MatIncidente mi) {
  int n=mi.nbSom;
  int arcs=mi.nbArcs;
  MatAdjacence g;
  int s,t;
  int **mat;
  allocMat(n,n,&mat);
  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= n; j++){
      mat[i][j]=0;
    }
  }
  g.mat=mat;
  g.nbSom=n;
  for (int i = 1; i <= arcs; i++){
    for (int j = 1; j <= n; j++){
      if (mi.mat[j][i]==1){
        t=j;
      }
      if (mi.mat[j][i]==-1){
        s=j;
      }
    }
    g.mat[s][t]=1;
  }
  return g;
}
/*une matrice d’incidence à une autre représentation par une matrice d’incidence col par col */
MatIncidColCol MatIncToMatIncColcol(MatIncidente mi){
  int n=mi.nbSom;
  MatIncidColCol micol;
  micol.nbArcs=mi.nbArcs;
  micol.nbSom=mi.nbSom;
  allocTab(micol.nbArcs, &micol.alpha);
  allocTab(micol.nbArcs, &micol.beta);
  for(int i=1;i<=mi.nbArcs;i++){
    for(int j=1;j<=n;j++){
      if(mi.mat[j][i]==1){
        micol.beta[i]=j;
      }
      if(mi.mat[j][i]==-1){
        micol.alpha[i]=j;
      }
    }
  }
  return micol;
}

/une matrice d’incidence à une autre représentation par une matrice d’incidence col par col./
MatIncidLigLig MatIncToMatIncLigLig(MatIncidente mi){
  MatIncidLigLig milig;
  milig.nbArcs=mi.nbArcs;
  milig.nbSom=mi.nbSom;
  int n=mi.nbSom;
  int iaps=1;
  int ias=1;
  allocTab(milig.nbArcs, &milig.AS);
  allocTab(milig.nbArcs, &milig.FS);
  allocTab(milig.nbSom, &milig.APS);
  for(int s=1;s<=n;s++){
    milig.FS[s]=iaps;
    for(int a=1;a<=mi.nbArcs;a++){
      if(mi.mat[s][a]==-1){
        milig.APS[iaps]=a;
        iaps++;
      }
      if(mi.mat[s][a]==1){
        milig.AS[a]=s;
      }
    }
  }
  milig.FS[n+1]=iaps;
  return milig;
}
