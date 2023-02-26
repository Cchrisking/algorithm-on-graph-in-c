/*Exercice3
un graphe  represeter par sa file de successeurs

*/
//2)determiner les successeurs d'un sommet donné
/*Pseudo code*/
/*
procedure liste_succsseur_ls(s,g)
PF:
  s:entier(E)
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
void liste_succsseur_ls(int s, Filesuccesseur g){
  int iaps=g.APS[s+1];
  int nbsucc=iaps-g.APS[s];
  int t;
  for(int i=0; i<nbsucc;i++){
    t=g.FS[iaps];
    iaps+=1;
    traiter(t);
  }
}
/*
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
  int n=nbsom(m);
  int p=nbarcs(ma);
  fs=allocSFS(n,p);
  /*
  traitement parcours globale MatriceAdj
  parcours ligne par ligne MatriceAdj
  */
  int iaps=0;
  for(int s=0; s<n; s++){
    fs.APS[s]=iaps;
    for(int t=0; t<n;t++){
      if(ma.mat[s][t]==1){
        fs.FS[iaps]=t;
        iaps+=1;
      }
    }
  }
  //ajout sommet virtuelle
  fs.APS[s]=iaps;
  return fs;
}
