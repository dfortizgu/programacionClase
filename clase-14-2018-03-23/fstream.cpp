#include <iostream>
#include <fstream>

/*este codigo escribe en consola y luego se tiene que redireccionnar la salida

int main(void){
  
  for(double i=1 ; i<=100 ; i++){
    std::cout<< i << "\t" << 1/i << "\n";
  }
  return 0;
}
*/

void print_numbers(int max);

int main(void){
  print_numbers(100);
  return 0;
}

void print_numbers(int max){
  std::ofstream fout("datosfout.txt");
  for (int i =1 ; i<=max ; i++){
    fout << i << "\t" << 1.0/i <<"\n";
  }
  fout.close();
}
