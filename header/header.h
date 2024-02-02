#include<stdio.h>
#include<stdlib.h>
#include "../header/matrice_adjacence.h"
#include "../header/matrice_incidente.h"
#include "../header/liste_adjacence.h"
#include "../header/file_successeur.h"
#include "../header/file_pile.h"
int nombre_sommet(MatriceAdj g);
int boucle(MatriceAdj g, int n);
void liste_successeur(MatriceAdj g,int s);
void liste_predecesseur(MatriceAdj g,int s);
void liste_succsseur_ls(Filesuccesseur g,int s);
Filesuccesseur conv_matAdj_Fs(MatriceAdj ma);
//ListeAdjacence conv_fs_matAdj(MatriceAdj ma);
int plus_de_succ(ListeAdjacence g);
/*Parcours matrice adjacence*/
int sommet_suivant(int s, int n, int *visite);
void rec_parcours_profondeur_matrice_adjacence(int s, int  visite[], int nbSommetVisite, MatriceAdj g);
void it_parcours_profondeur_adjacence(int s, int visite[],int* nbSommetVisite, MatriceAdj g);
void it_parcours_largeur_adjacence(int s, int visite[],int* nbSommetVisite, MatriceAdj g);
void parcours_profondeur_matrice_adjacence(int sd, MatriceAdj g);
/*parcours file de successeurs*/
void rec_parcours_profondeur_file_successeur(int s, int  visite[], int nbSommetVisite, Filesuccesseur g);
void it_parcours_profondeur_file_successeur(int s, int visite[], Filesuccesseur g);
void it_parcours_largeur_file_successeur(int s, int visite[], Filesuccesseur g);
