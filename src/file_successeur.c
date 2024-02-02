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
