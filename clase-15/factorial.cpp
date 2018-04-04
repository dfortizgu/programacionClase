#include <iostream>

long long fact(int n);

int main(void){
  std::cout<<fact(99)<<"\n";
}

long long fact(int n){
  if (n==0)return 1;
  return n*fact(n-1);
}
