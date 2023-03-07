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
