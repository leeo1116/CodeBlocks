#include <iostream>
#include "ReviewHeader.h"

using namespace std;


int Factorial(int k)
{
    int result = 1;
    for(int i = k; i > 0; i--)
    {
        result *= i;
    }
    return result;
}

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int (*RotateArray90(int inputArray[][N]))[N]
{
    // int (*A)[N]: a pointer to array, this pointer can be pointed to a continuous memory space
    if(sizeof(inputArray) == 0)
    {
        return NULL;
    }
    int arraySize = sizeof(inputArray);
    int array0Size = sizeof(inputArray[0]);
    int row = sizeof(inputArray[0])/sizeof(inputArray[0][0]);
    int col = sizeof(inputArray)/sizeof(inputArray[0]); // inputArray is just a int pointer at this stage, size is 4
    int left = 0, right = N-1;

    // Swap left-right
    while(left < right)
    {
        for(int r = 0; r < row; r++)
        {
            Swap(inputArray[r][left], inputArray[r][right]);
        }
        left += 1;
        right -= 1;
    }

    // Transpose
    for(int i = 0; i < row; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            Swap(inputArray[i][j], inputArray[j][i]);
        }
    }
    return inputArray;
}


void PrintArray(vector< vector<int> > matrix, int row, int col)
{
    cout << "Printing array";
    for(int i = 0; i < row; i++)
    {
        cout << endl;
        for(int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << ' ';
        }
    }
    cout << endl;
}


