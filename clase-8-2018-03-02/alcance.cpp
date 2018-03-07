#include <iostream>
int addition (int &a, int b)
{
  int r;
  std::cout<<&a<<"\n";
  r= a+b;
  return r;
}

int main(void)
{
  int a,b,c;
  a=5;
  b=4;
  c=addition(a,b);
  std::cout<<"El resultado es "<<c<<"\n";
  std::cout<<&a<<"\n";
  return 0;
}
