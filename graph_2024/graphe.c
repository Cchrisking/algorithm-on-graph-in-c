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
  
  return 0;
}
