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
  int p=ma.nbArcs;
  Filesuccesseur fs=alloc_mem_file_successeur(n,p);
  /*
  traitement parcours globale MatriceAdj
  parcours ligne par ligne MatriceAdj
  */
  int iaps=0;
  for(int s=0; s<n; s++){
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
