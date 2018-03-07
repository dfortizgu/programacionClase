#include <iostream>
int maximo (int a, int b){


  if(a>=b){

    return a;
    
  }else{

    return b;
    
  }

}
  /* 

 int m=0;

  if(a>=b){
    
    m= a;
  }
  else{
    m= b;
  }
  return m;
}

  */

/* 
otra forma seria 

int maximo(int a, int b){

 int m = a;
 if(b>=a){
 
 m=b

 }
 return m;
}


o

 En una sola linea la funcion seria:
 int maximo(int a, int b){
   return (a>b) ? a:b;
 }
*/

int main(void){

  int a,b;
  
  std::cout<<"Escriba dos numeros enteros\n";
  std::cin>>a;
  std::cin>>b;
  
  std::cout<< maximo(a,b)<<" \n";
  return 0;
}
