#include <iostream>
#include <cmath>

using fptr = double(double);

double bisection(double xl, double xu, double eps, int nmax, fptr f);
double funcion(double x);

int main (void) {
  std::cout<< bisection(12,20,1.0e-8,100,funcion)<<"\n";
  return 0;
  
}

double funcion(double x){
  return std::exp(-x)-x;
}

double bisection(double xl, double xu, double eps, int nmax, fptr f){
  
  double xr;
  
  for(int i=0 ; i<=nmax ; ++i){
    
    xr = 0.5*(xl+xu);
    if(std::fabs(f(xr))<eps) break;
    
    if(f(xl)*f(xr)<0){
	xu=xr;
      }else{
	xl=xr;
      }
  }
  return xr;
}


