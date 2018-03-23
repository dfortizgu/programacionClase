#include <iostream>
#include <fstream>
#include <string>

void print_numbers(int max, std::string name);

int main(void){

  print_numbers(100,"datosfout.txt");
  print_numbers(200,"datosfout2.txt");
  
  return 0;
}
void print_numbers(int max, std::string name){

  std::ofstream fout(name);
  fout.precision(16); fout.setf(std::ios::scientific);
  for(int i=1 ; i<=max ; i++){
    fout << i << "\t" << 1.0/i << "\n";
  }
  fout.close();
}
