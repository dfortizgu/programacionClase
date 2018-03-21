#include <iostream>
#include <cmath>

using fptr = double(double);

double funcion(double x);
double trapezoid_regular(const double a, const double b, const int n, fptr func);
double trapezoid_richardson(const double a, const double b, const int n, fptr func);
double simpson_regular(const double a, const double b, const int n, fptr func);
double simpson_richardson(const double a, const double b, const int n, fptr func);

int main(void){
  std::cout.precision(16);
  const int N = 20;
  std::cout << "Trapecio regular (n=20) es : " << trapezoid_regular(0, 5*M_PI/4, N, funcion) << "\n";
  std::cout << "Trapecio regular (n=40) es : " << trapezoid_regular(0, 5*M_PI/4, 2*N, funcion) << "\n";
  std::cout << "Trapecio richardson (n=20) es : " << trapezoid_richardson(0, 5*M_PI/4, N, funcion) << "\n";
  std::cout << "Trapecio richardson (n=40) es : " << trapezoid_richardson(0, 5*M_PI/4, 2*N, funcion) << "\n";
  std::cout << "Simpson regular (n=20) es : " << simpson_regular(0, 5*M_PI/4, N, funcion) << "\n";
  std::cout << "Simpson regular (n=40) es : " << simpson_regular(0, 5*M_PI/4, 2*N, funcion) << "\n";
  std::cout << "Simpson richardson (n=20) es : " << simpson_richardson(0, 5*M_PI/4, N, funcion) << "\n";
  std::cout << "Simpson richardson (n=40) es : " << simpson_richardson(0, 5*M_PI/4, 2*N, funcion) << "\n";

  return 0;
}

//Para cualquier funcion solo es necesario cambiar "funcion"

double funcion(double x){
  return (std::cos(2*x)/std::exp(x));
}

double trapezoid_regular(const double a, const double b, const int n, fptr func){
  const double h = (b-a)/n;
  double sum = 0.5*(func(a)+func(b));
  for (int i=1;i<n-1;++i) {
    double x = a+i*h;
    sum+=func(x);
  }
  return h*sum;
}

double trapezoid_richardson(const double a, const double b, const int n, fptr func){
  return (4*trapezoid_regular(a,b,2*n,func)-trapezoid_regular(a,b,n,func))/3;
}


double simpson_regular(const double a, const double b, const int n, fptr func){
  double h = (b-a)/n;
  double sum = func(a)+func(b);
  for(int i=1;i<=n/2-1;++i){
    double x=a+2*i*h;
    sum+=2*func(x);
  }
  for(int i=1;i<=n/2;++i){
    double x=a+(2*i-1)*h;
    sum+=4*func(x);
  }
  return h*sum/3;
}


double simpson_richardson(const double a, const double b, const int n, fptr func){
  return (4*simpson_regular(a,b,2*n,func)-simpson_regular(a,b,n,func))/3;
}
