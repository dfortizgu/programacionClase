#include <iostream>
#include <fstream>
#include <string>

double promedio(std::string name);

int main(void){
  std::cout<< promedio("datosfout.txt");
  return 0;
}

double promedio(std::string name){
  std::ifstream fin(name);
  std::ifstream pin(name);
  double sum = 0;
  double m;
  double n = 0;
  double x;
  while (fin){
    fin >> m >> x;
    if(fin.eof())break;
    n++;
  }
  fin.close();

  while(pin){
    pin >> m >> x;
    if(pin.eof())break;
    sum+=m;
  }
  pin.close();
  return sum/n;
}
