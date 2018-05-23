#include <iostream>
#include <cmath>
#include <vector>

void rk4(std::vector<double> & data, double t, double h);
double f(int idx, double t, const std::vector<double> & y);

const double cd = 0.225;
const double m = 90;
const double g = 9.81;
const double H = 0.001;
const int DIM = 2;

int main(void)
{
  std::vector<double> y(DIM);

  // initial conditions
  y[0] = 1000.0;
  y[1] = 0.0;

  // time evolution
  int ii = 0;
  while(y[0]>0){
    double t = 0.0 + ii*H;
    std::cout << t << "  " << y[0] << "   " << y[1] << "\n";
    rk4(y, t, H);
    ++ii;
  }

  return 0;
}


void rk4(std::vector<double> & data, double t, double h)
{
  std::vector<double> k1, k2, k3, k4, aux;
  k1.resize(data.size());
  k2.resize(data.size());
  k3.resize(data.size());
  k4.resize(data.size());
  aux.resize(data.size());

  // k1
  for(int ii = 0; ii < data.size(); ++ii) {
    k1[ii] = h*f(ii, t, data);
  }
  // k2 aux
  for(int ii = 0; ii < data.size(); ++ii) {
    aux[ii] = data[ii] + k1[ii]/2;
  }
  //k2
  for(int ii = 0; ii < data.size(); ++ii) {
    k2[ii] = h*f(ii, t + h/2, aux);
  }
  // k3 aux
  for(int ii = 0; ii < data.size(); ++ii) {
    aux[ii] = data[ii] + k2[ii]/2;
  }
  //k3
  for(int ii = 0; ii < data.size(); ++ii) {
    k3[ii] = h*f(ii, t + h/2, aux);
  }
  // k4 aux
  for(int ii = 0; ii < data.size(); ++ii) {
    aux[ii] = data[ii] + k3[ii];
  }
  //k4
  for(int ii = 0; ii < data.size(); ++ii) {
    k4[ii] = h*f(ii, t + h, aux);
  }

  // write new y
  for(int ii = 0; ii < data.size(); ++ii) {
    data[ii] = data[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
  }
}

double f(int idx, double t, const std::vector<double> & y)
{
  if (0 == idx) {
    return y[1];
  }
  else if (1 == idx) {
    return y[1]*y[1]*(cd/m)-g;
  }
  else {
    std::cerr << "BAD index : " << idx << std::endl;
    return 0;
  }
}
