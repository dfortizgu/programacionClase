#include <iostream>
#include <cmath>

struct complex {
  double x{0.0};
  double y{0.0};
  void print(void);
  double real(void);
  double img(void);
  double norma(void);
  double angle(void);
  complex operator+(const complex & rhs);
  complex sin(void);
};

int main (void){
  complex A;
  complex B;
  complex C;
  A.x=1;
  A.y=1;
  B.x=3;
  B.y=-2;
  
  A.print();
  std::cout<<"Parte real: "<<A.real()<<"\n";
  std::cout<<"Parte imaginaria: "<<A.img()<<"\n";
  std::cout<<"Norma "<<A.norma()<<"\n";
  std::cout<<"Angulo " << A.angle()<<"\n";
  std::cout<<"\n";
  
  B.print();
  std::cout<<"Parte real: "<<B.real()<<"\n";
  std::cout<<"Parte imaginaria: "<<B.img()<<"\n";
  std::cout<<"Norma "<<B.norma()<<"\n";
  std::cout<<"\n";
  
  C=A+B;

  A.print();
  B.print();
  C.print();
  std::cout<<"\n";

  C=A.sin();
  C.print();
  
   
  return 0;
}

/*Complex::print indica que print pertenece a complex, si no se coloca de esta
forma ocurre un error por el alcance de la funcion, print por si sola no sabe
quien es x y y*/

void complex::print(void){
  if(y==0){
    std::cout<< x <<"\n";
  }else if(y<0){
    if(y==-1){
      std::cout<< x <<"-i\n";
    }else{
      std::cout<< x << y <<"i\n";
    }
  }else{
    if(y==1){
      std::cout<< x <<"+i\n";
    }else{
      std::cout<< x << "+"<< y <<"i\n";
    }
  }
}

double complex::real(void){
  return x;
}


double complex::img (void){
  return y;
}

double complex::norma (void){
  return std::hypot(x,y);
}

//atan2 retorna el arctan(a/b)

double complex::angle(void){
  return std::atan2(y,x);
}

complex complex::operator+ (const complex & rhs){
  complex tmp;
  tmp.x=x+rhs.x;
  tmp.y=y+rhs.y;
  return tmp;
}


complex complex::sin(void){
  complex tmp;
  tmp.x=std::sin(x)*std::cosh(y);
  tmp.y=std::cos(x)*std::sinh(y);
  return tmp;
}
