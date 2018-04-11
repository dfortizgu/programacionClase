#include <iostream>
#include <vector>
#include <cmath>


double prom (const std::vector<double> &data);
double stddev (const std::vector<double> &data, double avg);

int main(void){
  std::vector<double> data;
  int N = 10;
  data.resize(N);
  data[0]=0;
  data[1]=0;
  data[2]=0;
  data[3]=0;
  data[4]=0;
  data[5]=0;
  data[6]=0;
  data[7]=0;
  data[8]=0;
  data[9]=0;

  double avg = prom(data);
  double dev = stddev(data, avg); 

  std::cout<< avg <<"\n";
  std::cout<< dev <<"\n";
  
}


double prom (const std::vector<double> &data){
  double sum = 0;
  int N = data.size();
  for(int i = 0 ; i<N ; i++){
    sum+=data[i];
  }
  return sum/N;
}

double stddev (const std::vector<double> &data, double avg ){
  double sum  = 0;
  int N = data.size();
  for(int i = 0; i<N ; i++){
    sum += (data[i]-avg)*(data[i]-avg);
  }
  return std::sqrt(sum/(N-1));
}
