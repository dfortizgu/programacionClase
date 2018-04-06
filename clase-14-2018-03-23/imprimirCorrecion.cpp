#include <iostream>
#include <fstream>
#include <string>

void read_numbers(std::string name);

int main(void){
  read_numbers("datosfout.txt");
  read_numbers("datosfout2.txt");
  return 0;
}

void read_numbers(std::string name){
  std::ifstream fin(name);
  int n;
  double x;

  while (fin){
    fin >> n >> x;
    if(fin.eof())break;
    std::cout << n << "\t" << x << std::endl;
  }
  fin.close();
}
