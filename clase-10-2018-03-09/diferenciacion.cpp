#include <cstdio>
#include <cmath>

double f(double x);
double fdevforw(double x, double h);
double fdevcent(double x, double h);
double fdevrichforw(double x, double h);
double fdevrichcent(double x, double h);


int main(void)
{
  double x = M_PI/3;
  double h = 0.1;

  
  /* % indica que se pondra una funcion, 25 indica que el valor ocupe maximo 25
     espacios, .16 indica una presicion de 16 cifras decimales, e imprime en
     notacion cientifica y\n un caracter nueva linea, despues de la coma se 
     coloca lo que se lee, en este caso la variable*/

  
  std::printf("%25.16e\n", fdevforw(x,h));
  std::printf("%25.16e\n", fdevcent(x,h));
  std::printf("%25.16e\n", fdevrichforw(x,h));
  std::printf("%25.16e\n", fdevrichcent(x,h));
  std::printf("%25.16e\n", std::cos(x));
  
  return 0;
}



double f(double x)
{
  return std::sin(x);
}

//Aplicando derivacion forward

double fdevforw(double x, double h)
{
  return (f(x+h)-f(x))/h;
}

//Aplicando derivacion central

double fdevcent(double x, double h)
{
  return (f(x+h/2)-f(x-h/2))/h;
}
 
double fdevrichforw(double x, double h)
{
  double result1 = fdevforw(x,h);
  double result2 = fdevforw(x,h/2);
  double result = (4*result2-result1)/3;
  return result;
}

double fdevrichcent(double x, double h)
{
  double result1 = fdevcent(x,h);
  double result2 = fdevcent(x,h/2);
  double result = (4*result2-result1)/3;
  
  return result;
}
