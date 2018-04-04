#include <iostream>
#include <cmath>

using fpt = double(double);

double newton_root(double xi, double eps, int nmax, fpt func, fpt dev);
double funcion(double x);
double derivada(double x);

int main(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);


  std::cout<<newton_root(1, 1.0e-15, 100, funcion, derivada)<<"\n";
  return 0;
}

//Funcion

double funcion(double x){
  return x*x-3;
}

//Derivada de la funcion

double derivada(double x){
  return 2*x;
}

double newton_root(double xi, double eps, int nmax, fpt func, fpt dev){
  for(int i=1; i<=nmax; ++i){
    if(std::fabs(func(xi))<eps) break;
    xi=xi-func(xi)/dev(xi);
  }
  return xi;
}
