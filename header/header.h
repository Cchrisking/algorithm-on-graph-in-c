/*
#include<stdio.h>
#include<stdlib.h>
//Representation par matrice d'adjancence
typedef struct{
  int nbSommet;
  int **matrice;
}MatriceAdj;
typedef struct{
  int nbSommet;
  int nbArcs;//nbarcs pour graphe non orienté
  int **matrice;
}MatIncidente;
// Liste de successeurs
typedef struct{
  int nbSommet;
  int nbarcs;
  int *fs;
  int *aps;
  //cout si valué
}Filesuccesseur;
//Liste d'adjancence matrice
typedef struct cellule{
  int somAdj;
  struct cellule* suivant;
}*Liste;
typedef struct{
  int nbSommet;
  Liste* tabAdj;
}ListeAdjacence;
//representation chainnée Liste successeurs predecesseurs
typedef struct{
  Liste lpred;
  Liste lsucc;
}ListePredSuc;
typedef struct{
  int nbsommet;
  ListePredSuc* tabAdjSP;//SP successeurs predecesseur
}ListeAdjSuccPred;
//PILES
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
*/
/*
Liste chainé
Primitives
*/
/*
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
//________________Fonction File__________________
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
//________________Fonction Pile__________________
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
//prototype fonction
void erreur_alloc_mem();
void lib_mem_tab(int tab[]);
void alloc_mem_matrice(int nblignes, int nbcolones, int **mat);
ListeAdjacence alloc_mem_liste_adjacence(int n);
Filesuccesseur alloc_mem_file_successeur(int n, int p, int tailleFs);
ListeAdjSuccPred alloc_mem_liste_succ_pred(int n);
Pile Alloc_mem_pile(int hM);
//fin prototype
int nombre_sommet(MatriceAdj g);
int boucle(MatriceAdj g, int n);
void liste_successeur(MatriceAdj g,int s);
void liste_predecesseur(MatriceAdj g,int s);
void liste_succsseur_ls(Filesuccesseur g,int s);
Filesuccesseur conv_matAdj_Fs(MatriceAdj ma);
//ListeAdjacence conv_fs_matAdj(MatriceAdj ma);
int plus_de_succ(ListeAdjacence g);
//Parcours matrice adjacence
void rec_parcours_profondeur_matrice_adjacence(int s, int  visite[], int nbSommetVisite, MatriceAdj g);
void it_parcours_profondeur_adjacence(int s, int visite[], MatriceAdj g);
void it_parcours_largeur_adjacence(int s, int visite[], MatriceAdj g);
//parcours file de successeurs
void rec_parcours_profondeur_file_successeur(int s, int  visite[], int nbSommetVisite, Filesuccesseur g);
void it_parcours_profondeur_file_successeur(int s, int visite[], Filesuccesseur g);
void it_parcours_largeur_file_successeur(int s, int visite[], Filesuccesseur g);
//parcours liste adjacence
void rec_parcours_profondeur_liste_adjacence(int s, int  visite[], int nbSommetVisite, ListeAdjacence g);
void it_parcours_profondeur_liste_adjacence(int s, int visite[], ListeAdjacence g);
void it_parcours_largeur_liste_adjacence(int s, int visite[], ListeAdjacence g);
*/
