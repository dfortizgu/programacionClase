#include <iostream>
#include <fstream>
#include <string>

int read_suma(std::string name);

int main(void){
  std::cout << read_suma("datosfout.txt")<<std::endl;
  return 0;
}

int read_suma(std::string name){
  std::ifstream fin(name);
  int n,  sum = 0;
  double x;
  while(fin){
    fin >>n >> x;
    sum+=n;
  }
  fin.close();
  return sum;

}
