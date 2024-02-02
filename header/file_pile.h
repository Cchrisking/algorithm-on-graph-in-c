typedef struct {
	int hautMax;
	int haut;
	int *tab;
}Pile;
//Struct FILES
typedef struct{
  Liste tete;
  Liste queue;
}File;
/*________________Fonction File__________________*/
//initialisation d'une File
File init_file(){
  File f;
  f.tete=init_liste();
  f.queue=init_liste();
  return f;
}
//fonction qui test si une File est vide
int est_vide_file(File f){
  return est_vide_liste(f.tete);
}
//renvoi le premier elt de la file
int sommet_file(File f){
  return (f.tete)->somAdj;
}
//ajout d'un elt dans la file
File enfiler( int elt,File f){
  Liste cel;
  cel=(Liste)malloc(sizeof(struct cellule));
  cel->somAdj=elt;
  cel->suivant=NULL;
  if (est_vide_file(f)){
    f.tete=f.queue=cel;
  }
  else{
    (f.queue)->suivant=cel;
    f.queue=cel;
  }
  return f;
}
//Enlève la premiere valeur de la file
File defiler(File f){
  Liste tt;
  tt =f.tete;
  if (f.tete==f.queue){
    f.tete=f.queue=NULL;
  }
  else {
    f.tete=(f.tete)->suivant;
  }
  free(tt);
  tt=NULL;
  return f;
}

void affiche_file(File f){
  while(!est_vide_file(f)){
    printf("%d_",sommet_file(f));
    defiler(f);
  }
}
/*________________Fonction Pile__________________*/
Pile init_pile() {
  Pile p;
  p.haut = 0;
	return p;
}

int est_vide_pile(Pile p) {
	return p.haut == 0;
}
int est_plein_pile(Pile p) {
	return p.haut == p.hautMax;
}

int sommet_pile(Pile p) {
	return p.tab[p.haut];
}

Pile empiler(int elt, Pile p) {
	if (!est_plein_pile(p)) {
		p.haut = p.haut + 1;
		p.tab[p.haut] = elt;
	}
	return p;
}

Pile depiler(Pile p) {
	if (!est_vide_pile(p)) {
		p.haut = p.haut - 1;
	}
	return p;
}
