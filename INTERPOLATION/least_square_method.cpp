
//for linear form  y=ax+b
//   [y =a[x +bn
//   [xy =a[x^2 + b [x           [ == summation sign 
#include<iostream>
#include<cmath>
using namespace std;

void get_input(float *x,float *y,int size){
    cout<<"enter the datas\n";
    for(int i=0;i<size;i++){
        cout<<"enter the values of (x,y)";
        cin>>x[i]>>y[i];
    }
}
void least_square_method(float *x,float*y,int size){
    float sumx=0,sumx2=0,sumy=0,sumxy=0;
    for(int i=1;i<=size;i++){ 
        sumx=sumx+ x[i-1];
        sumy=sumy+y[i-1];
        sumx2=sumx2+pow(x[i-1],2);
        sumxy=sumxy+x[i-1]*y[i-1];
    }
    //using cramers rule
    float D1,D2,D;
    D1=(sumy*sumx)-(size*sumxy);   // Da
    D2=(sumx*sumxy)-(sumx2*sumy);  // Db
    D=(sumx*sumx)-(sumx2*size);
    
    float a,b;
    a=D1/D;
    b=D2/D;
    cout<<"the linear first degree function is\n";
    cout<<"y="<<a<<"x+ "<<b;
}

int main(){
    int n;
    cout<<"enter the no of datas\n";
    cin>>n;
    float *x=new float[n];
    float *y=new float[n];
    get_input(x,y,n);
    least_square_method(x,y,n);
    delete [] x;
    delete [] y;
return 0;
}