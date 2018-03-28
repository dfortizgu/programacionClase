#include <iostream>
#include <cmath>

using fptr = double(double);

double bisection(double xl, double xu, double eps, int nmax, fptr f);
double funcion(double x);

int main (void) {
  std::cout<< funcion(1) <<"\n";
  std::cout<< bisection(1,2,1.0e-8,100,funcion)<<"\n";
  return 0;

}

//Cambiar funcion

double funcion(double x){
  return std::pow(x,10)-1;
}

double bisection(double xl, double xu, double eps, int nmax, fptr func){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);

  double xr = 0;

  for(int i=0 ; i<=nmax ; ++i){
    xr = xu - (func(xu)*(xl-xu))/(func(xl) - func(xu));
    if(std::fabs(func(xr)) < eps){
      break;
    }
    if(func(xl)*func(xr)<0){
	     xu=xr;
      }else{
	       xl=xr;
      }
  }
  return xr;
}
