#include <iostream>

int main(void){
  int a = 10;
  int*ptr = &a;
  std::cout<<a<<"\n";
  std::cout<<&a<<"\n";
  std::cout<<ptr<<"\n";
  std::cout<<&ptr<<"\n";
  std::cout<<*ptr<<"\n";
  return 0;
}
