#include <iostream>
int main (){
  /*cin lee un input del teclado, con >> se introduce dicho inout en una
    variable previamente nombrada
  */
  int age = 0;
  std::cout << "¿Cual es su edad?\n";
  std::cin >> age;
  std::cout << "Su edad: " << age << " años\n";  
  return 0;
}
