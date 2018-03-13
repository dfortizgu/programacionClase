#include <iostream>
#include <cmath>

double f(double x);
double fdevforw(double x, double h);
double fdevcent(double x, double h);
double fdevrichcent(double x, double h);
double fdev2cent(double x, double h);
double fdev2richcent(double x, double h);

int main(void) {
  std::cout.precision(16);
  double x = M_PI/4;
  double h = 0.1;
  std::cout << fdevforw(x,h) << "\n";
  std::cout << fdevcent(x,h) << '\n';
  std::cout << fdevrichcent(x,h) << '\n';
  std::cout << cos(x) << "\n";
  std::cout << fdev2cent(x,h) << '\n';
  std::cout << fdev2richcent(x,h) << '\n';
  std::cout << -sin(x);
  return 0;
}

double f(double x)
{
  return std::sin(x);
}


double fdevforw(double x, double h)
{
  return (f(x+h)-f(x))/h;
}


double fdevcent(double x, double h)
{
  return (f(x+h/2)-f(x-h/2))/h;
}

double fdevrichcent(double x, double h)
{
  return (4*fdevcent(x,h/2)-fdevcent(x,h))/3;
}


double fdev2cent(double x, double h)
{
  return (fdevrichcent(x+h/2,h)-fdevrichcent(x-h/2,h))/h;
}

double fdev2richcent(double x, double h)
{
  return (4*fdev2cent(x,h/2)-fdev2cent(x,h))/3;
}
