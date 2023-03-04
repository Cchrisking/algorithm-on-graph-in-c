int nombre_sommet(MatriceAdj g){
  return g.nbsommet;
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
  for(int i=0; i<n; i++){
    n=nombre_sommet(g);
    if(g.matrice[s][t]==1){
      insert_triee(elt, listeSuccesseurs);
    }
  }
}
//c)b)determiner les predecesseurs d'un sommet donné
void liste_predecesseur(MatriceAdj g,int s){
  int n;
  int Liste listePredecesseurs;
  for(int i=0; i<n; i++){
    n=nombre_sommet(g);
    if(g.matrice[t][s]==1){
      insert_triee(t, listePredecesseurs);
    }
  }
}
