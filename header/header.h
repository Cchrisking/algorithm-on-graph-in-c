#include<stdio.h>
#include<stdlib.h>
/*Representation par matrice d'adjancence*/
typedef struct{
  int nbSommet;
  int **matrice;
}MatriceAdj;
typedef struct{
  int nbSommet;
  int nbArcs;//nbarcs pour graphe non orienté
  int **matrice;
}MatIncidente;
/* Liste de successeurs*/
typedef struct{
  int nbsommet;
  int nbarcs;
  int *fs;
  int *aps;
  //cout si valué
}Filesuccesseur;
/*Liste d'adjancence matrice*/
typedef struct cellule{
  int somAdj;
  struct cellule* suivant;
}*Liste;
typedef struct{
  int nbsommet;
  Liste* tabAdj;
}ListeAdjacence;
/*representation chainnée Liste successeurs predecesseurs*/
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
/*
Primitives
*/
Liste init_liste(){
  return NULL;
}
Liste insert_tete(int elt,Liste){
  /*
  insert tete liste chainnée
  */
}
/*________________Fonction File__________________*/
//initialisation d'une File
File initFile(){
  File f;
  f.tete=initListe();
  f.queue=initListe();
  return f;
}
//fonction qui test si une File est vide
int estVideFile(File f){
  return estVide(f.tete);
}
//renvoi le premier elt de la file
int SommetFile(File f){
  return (f.tete)->somSucc;
}
//ajout d'un elt dans la file
File enfiler( int elt,File f){
  Liste cel;
  cel=(Liste)malloc(sizeof(struct cellule));
  cel->somSucc=elt;
  cel->suivant=NULL;
  if (estVide(f.tete)){
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

void AfficheF(File f){
  while(!estVideFile(f)){
    printf("%d_",SommetFile(f));
    defiler(f);
  }
}
/*________________Fonction Pile__________________*/
Pile initPile(Pile p) {
	p.haut = 0;
	return p;
}

int estVidePile(Pile p) {
	return p.haut == 0;
}

int estPleinPile(Pile p) {
	return p.haut == p.hautMax;
}

int sommetPile(Pile p) {
	return p.tab[p.haut];
}

Pile empiler(Pile p, int elt) {
	if (!estPleinPile(p)) {
		p.haut = p.haut + 1;
		p.tab[p.haut] = elt;
	}
	return p;
}

Pile depiler(Pile p) {
	if (!estVidePile(p)) {
		p.haut = p.haut - 1;
	}
	return p;
}
/*Liste chainé*/
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
    inser_tete(elt, l);
  }else{
    Liste der = dernier(l);
    Liste newCel=(Liste)malloc(sizeof(Liste));
    newCel->somAdj=elt;
    newCel->suivant=der->suivant;
    der->suivant=newCel;
  }
}
void inser_triee(int elt, Liste l){
  Liste ll=l;
  while(elt>ll->somAdj){
    ll=ll->suivant;
  }
  inser_tete(elt, ll);
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
int nombre_sommet(MatriceAdj g);
int boucle(MatriceAdj g, int n);
void liste_successeur(MatriceAdj g,int s);
void liste_predecesseur(MatriceAdj g,int s);
void liste_succsseur_ls(Filesuccesseur g,int s);
Filesuccesseur conv_matAdj_Fs(MatriceAdj ma);
int plus_de_succ(ListeAdj g);
ListeAdj conv_Fs_matAdj(MatriceAdj ma);
/*Parcours matrice adjacence*/
void rec_parcours_profondeur(int s, int  visite[], nbSommetVisite, MatriceAdj g);
void it_parcours_profondeur(int s, int visite[], MatriceAdj g);
void it_parcours_largeur(int s, int visite[], MatriceAdj g);
void parcours_profondeur(int sd, MatriceAdj g);
void parcours_largeur(int sd, MatriceAdj g);
/*parcours listeSuccesseurs*/
void rec_parcours_profondeur(int s, int  visite[], nbSommetVisite, Filesuccesseur g);
void it_parcours_profondeur(int s, int visite[], Filesuccesseur g);
void it_parcours_largeur(int s, int visite[], Filesuccesseur g);
void parcours_profondeur(int sd, Filesuccesseur g);
void parcours_largeur(int sd, Filesuccesseur g);
/*parcours liste adjacence*/
void rec_parcours_profondeur(int s, int  visite[], nbSommetVisite, ListeAdjacence g);
void it_parcours_profondeur(int s, int visite[], ListeAdjacence g);
void it_parcours_largeur(int s, int visite[], ListeAdjacence g);
void parcours_profondeur(int sd, ListeAdjacence g);
void parcours_largeur(int sd, ListeAdjacence g);
