#include<iostream>
using namespace std;

void getInput(float**matrix,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size+1;j++){
            cout<<"enter the elements in the matrix "<<"a["<<i<<"]"<<"["<<j<<"]"<<" ";
            cin>>matrix[i][j];
        }
    }
}

void Display(float **matrix,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size+1;j++){
            cout<<matrix[i][j]<<"\t";

        }
        cout<<"\n";
    }
}

void calculate(float **matrix,int size){
    float temp=0;
    for(int j=0;j<size;j++){   // we are doing column wise operation thats why column j is first
        for(int i=0;i<size;i++){
            
            if(i!=j){  //eliminating a[i][j];
               temp=matrix[i][j]/matrix[j][j];//so that k loop doesnt interfere as matrix updates
                                              // this is not for division but for storing 
                                            //preserving the value
               for(int k=0;k<size+1;k++){
                matrix[i][k]=matrix[i][k]-temp*matrix[j][k];
               }
            }
            
            
        }

    }

    cout<<"\nThe results are\n";
    for(int i=0; i<size;i++){
        cout<<"value of "<<i+1<<"variable is  "<<matrix[i][size]/matrix[i][i];
        cout<<"\n";
    }

}

int main()
{

    int row, column;
    cout << "Enter the size/variables of the matrix: \n";
    cin >> row;
    column = row + 1;

    float **matrix = new float *[row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new float[column];
    }

    getInput(matrix, row);

    cout << "\nRe - writting it in matrix form: \n\n";

    Display(matrix,row);
    calculate(matrix, row);
    


   cout<<"\ndeleting the matrix\n\n";
    for (int i = 0; i < row; i++)
    {

        delete[] matrix[i];
        
    }
    delete[] matrix;
}
