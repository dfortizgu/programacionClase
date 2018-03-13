#include <iostream>
#include <cmath>

double f(double x);
double fdevforw(double x, double h);
double fdevcent(double x, double h);
double fdevrichforw(double x, double h);
double fdevrichcent(double x, double h);

int main(void)
{
  std::cout.precision(16);
  double x = M_PI/3;
  double h = 0.1;

  //Error para fdevforward
  for(h=0.1;h>=1e-5;h*=0.5)
    {
      double error = (cos(x)-fdevrichcent(x,h))/cos(x);
      std::cout << h << "\t" << fabs(error) <<"\n";
    }

  std::cout << "\n\n";


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
