#include "../header/liste_adjacence.h"
#include "../header/file_successeur.h"
#include "../header/file_pile.h"
void erreur_alloc_mem();
void lib_mem_tab(int tab[]);
void alloc_mem_matrice(int nblignes, int nbcolones, int **mat);
ListeAdjacence alloc_mem_liste_adjacence(int n);
Filesuccesseur alloc_mem_file_successeur(int n, int p, int tailleFs);
ListeAdjSuccPred alloc_mem_liste_succ_pred(int n);
Pile Alloc_mem_pile(int hM);
