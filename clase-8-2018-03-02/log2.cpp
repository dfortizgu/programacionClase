#include <iostream>
#include <cmath>

int main(void){
  double x=1;
  for(x=0.1;x<=10000;x*=2){
    /*x*=2 edtermina que el incremento es multiplicando por 2 en vez de sumar un
    valor a cada paso
    */

    std::cout<<x<<"\t"<<std::log2(x)<<"\n";
    
  }
  return 0;
}
