#include <iostream>

int suma (int a, int b);

int main (void){
  std::cout<<suma(500,100)<<"\n";
  return 0;
}

int suma (int a, int b){
  int i=a, sum=0;
  do{
    sum+=i;
    i++;
  }
  while(i<=b);
  return sum;
}
