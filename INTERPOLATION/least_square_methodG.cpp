
//for linear form  y=ax2+bx+c
//   [y =a[x2 +b[x +cn
//   [xy =a[x3 + b [x2 +c [x
//   [ x2*y= a[x4 +b[x3 +c[x2         [ == summation sign 
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void get_input(float *x,float *y,int size){
    cout<<"enter the datas\n";
    for(int i=0;i<size;i++){
        cout<<"enter the values of (x,y)";
        cin>>x[i]>>y[i];
    }
}
void gaussjordan(float **matrix, int degree) {
    float temp = 0;

    for (int j = 0; j < degree; j++) {
        for (int i = 0; i < degree; i++) {
            if (i != j) {
                temp = matrix[i][j] / matrix[j][j];
                for (int k = 0; k < degree + 1; k++) {
                    matrix[i][k] = matrix[i][k] - temp * matrix[j][k];
                }
            }
        }
    }

    cout << "\nThe results are\n";
    for (int i = 0; i < degree; i++) {
        cout << "value of " << i + 1 << " variable is " << matrix[i][degree] / matrix[i][i];
        cout << "\n";
    }
}


void display(float**matrix,int degree){
    for(int i=0;i<degree;i++){
        for(int j=0;j<degree +1;j++){
             cout<<matrix[i][j]<<setw(6);
        }
        cout<<"\n";
    }
}
void least_square_method(float**matrix,float *x,float*y,int size,int degree){
   for(int i=0;i<=degree;i++){
      for(int j=0;j<=degree;j++){
         matrix[i][j]=0;
        for(int k=0;k<size;k++){
            matrix[i][j]=matrix[i][j]+pow(x[k],i+j);
        }
     }
   }

   for(int i=0;i<=degree;i++){
    
     for(int k=0;k<size;k++){
        matrix[i][degree+1]=matrix[i][degree+1]+pow(x[k],i)*y[k];
     }
   }
   display(matrix,degree+1);
   gaussjordan(matrix,degree+1);

}

int main(){
    int n,degree;
    cout<<"enter the no of datas\n";
    cin>>n;
    cout<<"enter the degree of polynomial equation you want to make\n";
    cin>>degree;
    float **matrix =new float* [degree+1];
    for(int i=0;i<degree+1;i++){
        matrix[i]=new float [degree+2];
    }
    float *x=new float[n];
    float *y=new float[n];
    get_input(x,y,n);
    least_square_method(matrix,x,y,n,degree);
    delete [] x;
    delete [] y;
    for(int i=0;i<=degree;i++){
         delete [] matrix[i];
    }
    delete [] matrix;
return 0;
}