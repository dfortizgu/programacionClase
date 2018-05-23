#include <iostream>

struct Quaternion {
  double a{0.0};
  double b{0.0};
  double c{0.0};
  double d{0.0};
  void print(void);
  Quaternion operator+(const Quaternion & rhs);
  Quaternion operator-(const Quaternion & rhs);
  Quaternion operator*(const Quaternion & rhs);
};

int main(void)
{
  Quaternion q1, q2;
  q1.a = 1; q1.b = 2; q1.c = 3; q1.d = 0;
  q2.a = 0; q2.b = 2; q2.c = -3.4; q2.d = -1;
  Quaternion q3;
  q3 = q1 + q2;
  q3.print();
  q3 = q1 - q2;
  q3.print();
  q3 = q1 * q2;
  q3.print();
  return 0;
}

void Quaternion::print(void){
  std::cout<<"("<< a<<","<< b<<","<< c<<","<< d<<")\n";
}

Quaternion Quaternion::operator+(const Quaternion & rhs){
  Quaternion tmp;
  tmp.a=a+rhs.a;
  tmp.b=b+rhs.b;
  tmp.c=c+rhs.c;
  tmp.d=d+rhs.d;
  return tmp;
}

Quaternion Quaternion::operator-(const Quaternion & rhs){
  Quaternion tmp;
  tmp.a=a-rhs.a;
  tmp.b=b-rhs.b;
  tmp.c=c-rhs.c;
  tmp.d=d-rhs.d;
  return tmp;
}

Quaternion Quaternion::operator*(const Quaternion & rhs){
  Quaternion tmp;
  tmp.a=a*rhs.a-b*rhs.b-c*rhs.c-d*rhs.d;
  tmp.b=a*rhs.b+b*rhs.a+c*rhs.d-d*rhs.c;
  tmp.c=a*rhs.c-b*rhs.d+c*rhs.a+d*rhs.b;
  tmp.d=a*rhs.d+b*rhs.c-c*rhs.b+d*rhs.a;
  return tmp;
}
