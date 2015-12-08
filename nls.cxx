#include<iostream>
#include<cmath>

using namespace std;

void func(double*, double*, const double);

int main (){
  const double psi0=pow(10,-8);
  const double eta=0.5;
  const double dx=0.1;
  const int xend=100;
  const int xbeg=0;
  const int N=(xend-xbeg)/dx;
  double y[2];
  double ytemp[2];
  double k1[2],k2[2],k3[2];
  y[0]=psi0;
  y[1]=sqrt(eta)*psi0;
  cout <<0<< "\t"<<y[0]<<"\t"<<y[1]<< endl;
  
  for(int i=1; i<N; i++){
    func(y,k1,eta); //calculates k1
    ytemp[0]=y[0]+1./2*dx*k1[0];
    ytemp[1]=y[1]+1./2*dx*k1[1];
    func(ytemp,k2,eta);//calculates k2
    ytemp[0]=y[0]+(-k1[0]+2*k2[0])*dx;
    ytemp[1]=y[1]+(-k1[1]+2*k2[1])*dx;
    func(ytemp,k3,eta);//calculates k3
 
    y[0]+=dx/6.*(k1[0]+4*k2[0]+k3[0]);
    y[1]+=dx/6.*(k1[1]+4*k2[1]+k3[1]);
    cout <<dx*i<< "\t"<<y[0]<<"\t"<<y[1]<< endl;
  }
  
  
  return 0;
}
void func(double* y, double* f, const double eta){
  f[0]=y[1];
  f[1]=(eta-abs(y[0])*abs(y[0]))*y[0];
}