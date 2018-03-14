#include <iostream>

int suma(int n){
  int i, sum = 0;
  for (i=1;i<=n;i++){
    sum+=i;
  }
  return sum;
}

int main (void){
  std::cout << suma(100);
  return 0;
}
