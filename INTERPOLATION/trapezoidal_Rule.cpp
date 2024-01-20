#include<iostream>
#include<cmath>
using namespace std;

void get_input(float*y,int size){
   for(int i=0;i<size;i++){
    cout<<"enter the datas y["<<i<<"]:  ";
    cin>>y[i];
   }
}

void Trapezoidal(float*y,int n,float h){
    float sum=0;
    for(int i=1;i<n;i++){
        sum=sum+y[i];
    }
    sum=sum*2;
    sum=sum+y[0]+y[n];
    sum=(sum*h)/2;
    cout<<"the final answer is "<<sum;
}

int main(){
 int n;
 float Xo,Xn;
 cout<<"enter the no of datas\n";
 cin>>n;
 float *y=new float [n];
 cout<<"enter the  interval you want to integrate i.e (x0 xn)";
 cin>>Xo>>Xn;
 float h=(float)(Xn-Xo)/n;
 get_input(y,n);
 Trapezoidal(y,n,h);
delete [] y;
return 0;
}