#include "../header/liste.h"
typedef struct{
  int nbSommet;
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
/**/
/*parcours liste adjacence*/
void rec_parcours_profondeur_liste_adjacence(int s, int  visite[], int nbSommetVisite, ListeAdjacence g);
void it_parcours_profondeur_liste_adjacence(int s, int visite[], ListeAdjacence g);
void it_parcours_largeur_liste_adjacence(int s, int visite[], ListeAdjacence g);
