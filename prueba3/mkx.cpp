#include <iostream>
#include <cmath>
#include <vector>

void rk4(std::vector<double> & data, double t, double h);
double f(int idx, double t, const std::vector<double> & y);

const double m = 10;
const double TF= 100;
const double H = 0.001;
const double k = 1;
const double L = 3;
const double b = 0.23;
const double nsteps = TF/H;
const int DIM = 2;

int main(void)
{
  std::vector<double> y(DIM);

  // initial conditions
  y[0] = 1.0;
  y[1] = 1;

  // time evolution

  for (int i = 0; i < nsteps; i++) {
    double t = 0.0 + i*H;
    std::cout << t << "  " << y[0] << "   " << y[1] << "\n";
    rk4(y, t, H);
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
    return -k*pow(y[0],L)/m-b*y[1]/m;
  }
  else {
    std::cerr << "BAD index : " << idx << std::endl;
    return 0;
  }
}
