include "structures.h"
/*Memory allocation*/
void array_memAllocation(int n, int* matrice){
  matrice=malloc(sizeof(int*)*n+1);
  if(matrice==NULL){
    printf("Array memory allocation failed");
  }else{
    printf("succesfull array memory allocation");
  }
}
void array_2dmemAllocation(int colone, int ligne, int** matrice){
  array_memAllocation(ligne, *matrice);
  if(matrice==NULL){
    printf("Failed to allocate memmory for the array\n");
  }else{
    for(int l=0; l<ligne; l++){
      for(int c=0; c<colone; c++){
        array_memAllocation(l, matrice[l]);
      }
    }
  }
}
