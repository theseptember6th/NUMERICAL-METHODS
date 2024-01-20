#include<iostream>
using namespace std;

void get_input(float *x,float *y,int size){
    cout<<"Enter the datas \n";
    for(int i=0;i<size;i++){
        cout<<"enter value of (x y) ";
        cin>>x[i]>>y[i];
    }

}
void display(float*x,float*y,int size){
    cout<<"     X   |   Y     \n";
    cout<<"--------------------\n";
    for(int i=0;i<size;i++){
        cout<<"     "<<x[i]<<"   |   "<<y[i]<<"\n";
        
    }
}
void Lagranges_interpolation(float*x,float*y,int size){
    float temp;
    cout<<"enter the value of x,you want to interpolate\n";
    cin>>temp;
    float sum=0;
      for(int i=0;i<size;i++){
        float product=1;
        for(int j=0;j<size;j++){
              if(i!=j){
                  product=product*(temp-x[j])/(x[i]-x[j]);
              }
        }
        product=product*y[i];
        sum=sum+product;
      }

      cout<<"the interpolated value is: "<<sum;

}

int main(){
   int size;
   cout<<"enter the no of data you want to enter\n";
   cin>>size;
   float *x=new float[size]; 
   float *y=new float[size];
   get_input(x,y,size);
   display(x,y,size);
   Lagranges_interpolation(x,y,size);

   delete [] x;
   delete [] y;
return 0;
}