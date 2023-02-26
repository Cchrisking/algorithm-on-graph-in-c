/*Exercice3
un graphe  represeter par sa file de successeurs

*/
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
int plus_de_succ(ListeAdj g){
  int n=nbsommet(g);
  int nbSuccMax=0;
  int l,sMax;
  for(int s=0; s<n; s++){
    l=g.tab[s];
    nbSucc=longueur(l);
    if(nbSucc>nbSuccMax){
      nbSuccMax=nbSucc;
      smax=s;
    }
  }
  return smax;
}
/*
func conv_Fs_matAdj(ma)→ListeAdj
  PF:
    ma:MatriceAdj
  Debut:
    n←nbsom(ma)
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
ListeAdj conv_Fs_matAdj(MatriceAdj ma){
  n=nbsom(ma);
  la=allocSLA(n);
  for(int s=0;s<n; s++){
    la.tab[s]=initL();
    for (int t = n; t>0;  t++) {
      if(ma.mat[s][t]==1){
        la.tab[s]=inser_tete(t,la.tab[s]);
      }
    }
  }
  return la;
}
