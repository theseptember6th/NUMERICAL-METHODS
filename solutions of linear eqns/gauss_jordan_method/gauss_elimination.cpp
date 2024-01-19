#include<iostream>
#include<iomanip>
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
    cout.setf(ios::fixed);
    for(int i=0;i<size;i++){
        for(int j=0;j<size+1;j++){
            
            cout<<matrix[i][j]<<setprecision(2)<<setw(8);

        }
        cout<<"\n";
        
    }
    cout.unsetf(ios::fixed);
}
void RESULT(float **matrix, int size) {
    float *result = new float[size];

    for (int i = size - 1; i >= 0; i--) {
        result[i] = matrix[i][size]; // initialize with the rightmost element

        for (int j = i + 1; j < size; j++) {
            result[i] = result[i] - matrix[i][j] * result[j];
        }

        result[i] = result[i]/matrix[i][i];
    }

    cout << "\nSolution is :\n";
    for (int i = 0; i < size; i++) {
        cout << "x[" << i << "] = " << result[i] << endl;
    }

    delete[] result;
}

void upper_Triangular(float **matrix,int size){
    float temp=0;
    for(int j=0;j<size-1;j++){   
        for(int i=j+1;i<size;i++){
               temp=matrix[i][j]/matrix[j][j];
               for(int k=j;k<size+1;k++){
                matrix[i][k]=matrix[i][k]-temp*matrix[j][k];
            }    
        }
    }
        Display(matrix,size);
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
    cout<<"\n";
    upper_Triangular(matrix, row);
    RESULT(matrix,row);
    cout<<"\ndeleting the matrix\n\n";
    for (int i = 0; i < row; i++)
    {

        delete[] matrix[i];
        
    }
    delete[] matrix;
}
