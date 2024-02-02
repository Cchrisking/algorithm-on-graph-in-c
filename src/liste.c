#include "../header/header.h"
void insert_tete(int elt, Liste l){
  Liste cel=(Liste)malloc(sizeof(Liste));
  cel->somAdj=elt;
  cel->suivant=l;
}
void insert_queue(int elt, Liste l){
  if(est_vide_liste(l)){
    insert_tete(elt, l);
  }else{
    Liste der = dernier(l);
    Liste newCel=(Liste)malloc(sizeof(Liste));
    newCel->somAdj=elt;
    newCel->suivant=der->suivant;
    der->suivant=newCel;
  }
}
void insert_triee(int elt, Liste l){
  Liste ll=l;
  while(elt>ll->somAdj){
    ll=ll->suivant;
  }
  insert_tete(elt, ll);
}
void affiche_liste(Liste l){
  Liste ll=l;
  int donnee=ll->somAdj;
  printf("\t\t");
  while (ll!=NULL) {
    printf("%d ", donnee);
  }
  printf("\n");
}
