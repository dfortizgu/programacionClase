#include <iostream>
#include <cmath>

int main(void){

  double x = 0.0;
  for(x= -M_PI ; x<= M_PI ; x+=0.1){ 
    std::cout << x <<"\t"<<std::sin(x)<<"\n";
  }

  return 0;
}
