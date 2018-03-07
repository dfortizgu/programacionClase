#include <iostream>
int suma (int a, int b){

  return a+b;

}

int main(void){
  int a;
  int b;
  std::cout<<"Este programa suma dos numeros enteros a y b\n"<<"Ingrese a\n";
  std::cin>> a;
  std::cout<<"Ingrese b\n";
  std::cin>> b;
  std::cout<< "La suma de a y b es "<< suma(a,b)<<"\n";
  return 0;
}
