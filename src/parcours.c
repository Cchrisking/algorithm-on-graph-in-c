#include "../header/header.h"
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
void it_parcours_profondeur_adjacence(int s, int visite[], MatriceAdj g){
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
      for (int t=0; t<g.nbSommet; t++){
        if(!visite[t]==0 && g.matrice[s][t]==1){
        p=empiler(t,p);
      }
    }
  }
}
}
void it_parcours_largeur_adjacence(int s, int visite[], MatriceAdj g){
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
