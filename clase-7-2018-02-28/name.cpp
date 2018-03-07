#include <iostream>
#include <string>

void hola(std::string name){
  std::cout<<"Cual es su nombre?\n";
  std::cin>>name;
  std::cout<<"Hola "<< name <<"!\n";

}

int main (void){

  std::string name;
  hola(name);
  return 0;

}
