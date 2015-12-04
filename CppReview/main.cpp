#include <iostream>
#include <string>
#include "ReviewNamespace.h"
#include "ReviewHeader.h"
<<<<<<< HEAD
// #include "ReviewFunction.cpp"
=======
#include "Calculator.h"
>>>>>>> origin/master

using namespace std;
using namespace review;



int main(int argc, char** argv) // argc: number of arguments; argv: argument vector
{
    char words[] = "Liang Li";
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
