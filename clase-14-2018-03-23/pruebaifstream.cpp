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
  //int n;
  //double x;
  std::string line;
  while (!fin.eof()){
    getline(fin, line);
    std::cout<<line<<"\n";
  }
  fin.close();
}
