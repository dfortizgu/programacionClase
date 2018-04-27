#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

const double w = 2.563424; //Omega en radianes

void euler(double ta, double tb, double h, std::vector<double> & y);
double f(double t, const std::vector<double> & y, int id);


int main(void){
  const double N =2;
  const double TA = 0;
  const double TB = 3.4;
  const double H = 0.01;
  std::vector<double> y = {0.12,0};  //{x0, v0}
  
  euler(TA,TB,H,y);
  return 0;
  
}

void euler(double ta, double tb, double h, std::vector<double> & y){
  const int N = (tb-ta)/h;
  std::vector<double>yaux(y.size());
  for(int nt = 0; nt<N; ++nt){
    double t = ta + h*nt;
    std::copy(y.begin(), y.end(),yaux.begin());
    for(int id=0 ; id<y.size() ; ++id){
      y[id] = y[id]+h*f(t,yaux,id);
    }
    std::cout<<t<<"\t"<<y[0]<<"\t"<<y[1]<<"\n";
  }
}


double f(double t, const std::vector<double> & y, int id){
  if(0==id){
    return y[1];
  }
  else if(1==id){
    return -w*w*y[0];
  }
  else{
    std::cerr<< "ERROR";
    exit(1);
  }
}
