#include <iostream>

int suma(int a, int b);

int main(void){
  std::cout << suma(2,100)<<"\n";
}

int suma(int a, int b){
  int sum=0, i=a;
    while(i<=b){
      sum+=i;
      i++;
    }

  return sum;
}
