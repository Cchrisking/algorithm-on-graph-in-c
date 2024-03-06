#include "structures.h"
MatriceAdjacence g;
int isloop(MatriceAdjacence g, int n){
  if(n==0){
    return 0;
  }else{
    if(g.matrice[n][n]==1){
      return 1;
    }else{
      return isloop(g, n-1);
    }
  }
}
int main(int argc, char const *argv[]) {
  MatriceAdjacence g;
  g.nbSommet=3;
  array_2dmemAllocation(g.nbSommet,g.nbSommet,g.matrice);
  return 0;
}
