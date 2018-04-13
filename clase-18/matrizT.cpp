#include <iostream>

int main(void){
  int m = 3;
  int n = 5;
  int M [m][n]={{0.0}};
  int MT [n][m]={{0.0}};
  //inicializa todas las entradas en 0 0
  
  //llenando la matriz
  for (int i = 0; i<m; ++i){
    for (int j = 0; j<n; ++j){
      M[i][j]= i*n+j;
    }
  }

  //Traspuesta
  for(int i = 0; i<m; ++i){
    for(int j = 0; j<n; ++j){
      MT[j][i]=M[i][j];
    }
  }

  //Escribiendo M
  for(int i = 0; i<m;++i){
    for(int j = 0; j<n; j++){
      std::cout << M[i][j]<<"  ";
    }
    std::cout<<"\n\n";
  }

  std::cout<<"\n\n\n";

  //Escribiendo M
  for(int i = 0; i<n;++i){
    for(int j = 0; j<m; j++){
      std::cout << MT[i][j]<<"  ";
    }
    std::cout<<"\n\n";
  }
}
