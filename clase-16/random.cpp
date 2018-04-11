#include<iostream>
#include<random>

int main(void){
  int seed = 0;

  /*mt19937 es un generador de numeros aleatorios incluido en la libreria random
    gen es solo el nombre del generafor que toma como semilla a seed
  */
  std::mt19937 gen(seed);
  
  /*Se elige el tipo de distribucion a utilizar*/
  std::uniform_real_distribution<> dis(1,2);

  for(int n = 0; n<100000; n++){
    /*Se usa la distribucion dis para transformar el int generado por gen en
      un numero acorde con la distribucion elegida
    */
    std::cout << dis(gen) << "\n";
  }
}
