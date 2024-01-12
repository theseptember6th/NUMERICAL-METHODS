#include <iostream>
using namespace std;
void input(float **matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << "enter the value of matrix"
                 << "[" << i << "]"
                 << "[" << j << "]";
            cin >> matrix[i][j];
            cout << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = row; j < row + row; j++)
        {
            if (i == (j - row))  // u cant use i==j ,simple but important
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }
}


void display(float **matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void display_inverse(float **matrix, int row)
{
    cout << "inverse of the matrix is \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = row; j < row + row; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
void INVERSE(float **matrix, int row)
{
    for (int j = 0; j < row; j++)
    {
        if (matrix[j][j] == 0)
        {
            cout << "Error: Division by zero encountered. Unable to find the inverse.\n";
            return;
        }

        for (int i = 0; i < row; i++)
        {
            if (i != j)
            {
                float temp = matrix[i][j] / matrix[j][j];
                for (int k = 0; k < row + row; k++)
                {
                    matrix[i][k] = matrix[i][k] - temp * matrix[j][k];
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        if (matrix[i][i] == 0)
        {
            cout << "Error: Division by zero encountered. Unable to find the inverse.\n";
            return;
        }

        float temp = matrix[i][i];
        for (int j = 0; j < row + row; j++)
        {
            matrix[i][j] = matrix[i][j] / temp;
        }
    }
}
// Function to calculate the determinant of a square matrix
float calculateDeterminant(float **matrix, int row)
{
    if (row == 1)
    {
        return matrix[0][0];
    }
    else if (row == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        float sign = 1.0;
        float cumulativeSum = 0;

        for (int colNum = 0; colNum < row; colNum++)
        {
            // Create a submatrix excluding the first row and the current column
            float **submatrix = new float *[row - 1];
            for (int i = 0; i < row - 1; i++)
            {
                submatrix[i] = new float[row - 1];
            }

            for (int i = 1; i < row; i++)
            {
                int subIndex = 0;
                for (int j = 0; j < row; j++)
                {
                    if (j != colNum)
                    {
                        submatrix[i - 1][subIndex++] = matrix[i][j];
                    }
                }
            }

            float determinant = calculateDeterminant(submatrix, row - 1);
            cumulativeSum += matrix[0][colNum] * determinant * sign;

            // Deallocate memory for the submatrix
            for (int i = 0; i < row - 1; i++)
            {
                delete[] submatrix[i];
            }
            delete[] submatrix;

            sign = -sign;
        }

        return cumulativeSum;
    }
}


int main()
{
    int row, column;
    cout << "Enter the row of the matrix: \n";
    cin >> row;
    column = row + row;

    float **matrix = new float *[row]; // a[row][row+row]
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new float[column];
    }
    input(matrix,row);
    float determinant = calculateDeterminant(matrix, row);
    cout << "Determinant of the matrix is: " << determinant << "\n";

    if (determinant == 0)
    {
        cout << "Error: Determinant is zero. Unable to find the inverse.\n";
    }
    else
    {
        INVERSE(matrix, row);
        display_inverse(matrix, row);
    }
    cout << "\ndeleting the matrix\n\n";

    for (int i = 0; i < row; i++)
    {

        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}