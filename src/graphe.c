include"../header/header"
int main(int argc, char const *argv[]) {
  int **mat;
  allocMat(6, mat);
  for (int j= 0; i < 6; i++) {
    for (int j= 0; j < 6; j++){
      mat[i][j]=0;
    }
    mat[1][3] = 1;
    mat[2][1] = 1;
    mat[2][3] = 1;
    mat[2][4] = 1;
    mat[3][4] = 1;
    mat[3][6] = 1;
    mat[5][4] = 1;
    mat[5][6] = 1;
    mat[6][4] = 1;
    MatriceAdj matriceAdjacence;
    matriceAdjacence.matrice=matriceAdjacence;
    matriceAdjacence.nbSommet=6;
    matriceAdjacence.nbArcs=9;
  return 0;
}
