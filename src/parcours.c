void rec_parcours_profondeur(int s, int  visite[], nbSommetVisite, Graphe g){
  visite[s]=1;
  //traiter
  nbSommetVisite+=1;
  for(int t=0; t<s; t++){
    if(!visite[t]){
      rec_parcours_profondeur(t, visite, nbSommetVisite, g);
    }
  }
}
void it_parcours_profondeur(int s, int visite[], Graphe g){
  Pile p=initPile(); //flag a completer
  p=empiler(s, p);////flag a completer
  int u;
  while(!est_vide_pile(p)){
    u =somet_pile(p);
    p=depile(p);
    if(!visite[u]){
      traite(u)////flag a completer
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
void it_parcours_largeur(int s, int visite[], Graphe g){
  File f=initFile(); //flag a completer
  p=emfiler(s, p);////flag a completer
  int u;
  while(!est_vide_file(f)){
    u =somet_file(f);
    f=depile(f);
    if(!visite[u]){
      traite(u)////flag a completer
      nbSommetVisite=+1;
      visite[u]=1;
      /*
      pour t de dernier successeur au premier successeur de u faire{
        if(!visite[t]){
        f=emfiler(t,f);
      }
    }
      */
    }
  }
}
void parcours_profondeur(int sd, graphe g){
  int n←nbSommet(g);//flag a completer
  int* visite;
  visite=alloc_mem_ab();
  for(int s=0; s<n; s++){
    visite[s]=0;
  }
  int s=sd;
  int nbSommetVisite=0;
  while(nbSommetVisite<n){
    if(!visite[0]){
      /*recursive*/
      rec_parcours_profondeur(s, visite, nbSommetVisite, g);
      /*iterative*/
      it_parcours_profondeur(s, visite, nbSommetVisite, g);
  }
  s=somesuivant(s,n,visite);
}
}
void parcours_largeur(int sd, Graphe g){
  int n=nbSommet(g);//flag a completer
  int* visite;
  visite=alloc_mem_tab();
  for(int s=0; s<n; s++){
    visite[s]=0;
  }
  int s=sd;
  int nbSommetVisite=0;
  while(nbSommetVisite<n){
    if(!visite[s]){
      it_parcours_largeur(s, visite, nbSommetVisite, g);
    }
  }
}
