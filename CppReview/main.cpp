#include <iostream>
#include <string>
#include "ReviewNamespace.h"
#include "ReviewHeader.h"
#include "Calculator.h"


using namespace review;


int main(int argc, char** argv) // argc: number of arguments; argv: argument vector
{
    char words[] = "Smile face";
    int index[]  = {1, 2, 3};
    int weight[5] = {0};
    int* date[7];
    char gender[3]; // declare on the stack and size is determined at compile time
    int num = 10;
    int* age = new int[num]; // declare on the heap and size is determined at runtime
    int swapA = 1, swapB = 2;
    float sum, result;
    string welcome = "Hi! ", name = "Charlie";
    Calculator calc; // Stack-based calculator
    Calculator* myCalc;
    float location[][3] = {{1, 2, 5}, {3, 6, 8}};
    int* p = &num;
    int array1[2] = {3, 9};
    int array2[2][3] = {{2, 3, 2}, {0, 1, 5}};
    int array3[N][N] = {{2, 3}, {0, 1}};
    int array4[N][N];
    int *p1[3]; // Pointer to an array
    int **p2; // Pointer to a pointer

    vector< vector<int> > array5(2, vector<int>(2));
    PrintArray(array5, 2, 2);
    cout << "*(*(array2+1)+1) = array2[1][1] = " << *(*(array2+1)+1) << " = " << array2[1][1] << endl;
    cout << "sizeof(array4)/sizeof(array4[0]) = " << sizeof(array4)/sizeof(array4[0]) << endl;
    A array2Rotated;
    array2Rotated = RotateArray90(array3);
    // array4 = array2Rotated; // Cannot convert array pointer to array
    for(int i = 0; i < N; i++)
    {
        cout << endl;
        for(int j = 0; j < N; j++)
        {
            cout << array2Rotated[i][j] << ' ';
            cout << *(*(array2Rotated+i)+j) << ' ';
        }
    }
    cout << endl << "p = " << p << endl;
    cout << "&p = " << &p << endl;
    cout << "*p = " << *p << endl;

    cout << "sizeof(array1) = " << sizeof(array1) << endl;
    cout << "array1 = " << array1 << endl;
    cout << "&array1 = " << &array1 << endl;
    cout << "*array1 = " << *array1 << endl;
    cout << "&array1[0] = " << &array1[0] << endl;
    cout << "&array1[1] = " << &array1[1] << endl;

    cout << "sizeof(array2) = " << sizeof(array2) << endl;
    cout << "array2 = " << array2 << endl;
    cout << "&array2 = " << &array2 << endl;
    cout << "*array2 = " << *array2 << endl;
    cout << "**array2 = " << **array2 << endl;

    cout << "size of stack-based: " << sizeof(calc)
    << "size of heap-based: " << sizeof(myCalc) << endl;
    myCalc = &calc; // myCalc = new Calculator;
    myCalc->SetAllowNegative(false);
    result = myCalc->divide(3, 2);
    cout << "3/2=" << result << endl;

    cout << "size of words is " << sizeof(words) << endl;
    calc.SetAllowNegative(true);
    sum = calc.add(2, -1);
    cout << "2+(-1)=" << sum << endl;
    cout << welcome+name << endl;
    cout << swapA << ' ' << swapB << endl;
    Swap(swapA, swapB);
    cout << swapA << ' ' << swapB << endl;

    date[0] = index;
    age[0] = 30;
    age[1] = 45;
    age[12] = 32; // not safe

    for(int i = 0; i < num; i++)
    {
        cout << age[i] << endl;
    }

    cout << "Hello world!" << endl;
    PrintName(words); // Function from a namespace
    cout << Factorial(5) << endl; // Function from external file

    switch(num)
    {
    case 1:
        cout << "Liang" << endl;
    default:
        break;
    }
    return 0;
}
