#include<stdlib.h>
typedef struct cellule{
  int somAdj;
  struct cellule* suivant;
}*Liste;
Liste init_liste(){
  return NULL;
}

int est_vide_liste(Liste l){
  return l==NULL;
}
Liste dernier(Liste l){
  if(est_vide_liste(l->suivant)){
    return l;
  }else{
    return dernier(l->suivant);
  }
}
/**/
void insert_tete(int elt, Liste l);
void insert_queue(int elt, Liste l);
void insert_triee(int elt, Liste l);
void affiche_liste(Liste l);
