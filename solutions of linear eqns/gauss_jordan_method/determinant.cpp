#include <iostream>
using namespace std;
void getInput(float **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "enter the elements in the matrix "
                 << "a[" << i << "]"
                 << "[" << j << "]"
                 << " ";
            cin >> matrix[i][j];
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

    int row;
    cout << "Enter the row of the square matrix: \n";
    cin >> row;
    float **matrix = new float *[row]; // a[row][row+row]
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new float[row];
    }
    getInput(matrix, row);
    cout << "the determinant of the matrix is " << calculateDeterminant(matrix, row);
    cout << "\ndeleting the matrix";

    for (int i = 0; i < row; i++)
    {

        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;

    return 0;
}