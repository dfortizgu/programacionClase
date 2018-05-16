#include <iostream>
typedef double REAL;


int main(void){
  REAL under = 1.0, over = 1.0;
  int N = 1080, ii=0;
  while(ii<N){
    std::cout<<ii<<"\t"<<under << "\t"<<over<<"\n";
    under /=2.0;
    over *=2.0;
    ++ii;
  }
  return 0;
}
