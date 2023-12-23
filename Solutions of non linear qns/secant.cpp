#include<iostream>
#include<cmath>
using namespace std;

float function_(float x)
{
    //return (x * log10(x) - 1.9);  // xlogx-1.9
    return (pow(x,3)-x-11);    //x3-x-11
}

float derivative_(float x)
{
    //return (log10(x) + 1 / log10(2.7182)); // logx+1/loge
    return(3*pow(x,2)-1);  //3x2-1
}

void Secant(float a,float b,float error){
    float temp,c;
    int count=0;
       do{
           if(abs(function_(b)-function_(a))<error){
            cout<<"f(b)- f(a) = 0 ,so invalid\n";
            cout<<"Terminating the program...";
            exit(0);
           }
           else{
            c=(a*function_(b)-b*function_(a))/(function_(b)-function_(a));
            a=b;
            b=c;
           }
           count++;
           if(count>=100){
            cout<<"\nITERATED for 100 times ,couldnt find the roots\n";
            exit(0);
           }
       }while(abs(function_(c))>error);

       cout<<"\nthe ans is "<<c;
}

int main(){
    float a,b,error;
  cout<<"enter the interval (a,b): ";
  cin>>a>>b;
  cout<<"enter the tolerable error: ";
  cin>>error;
  Secant(a,b,error);
return 0;
}