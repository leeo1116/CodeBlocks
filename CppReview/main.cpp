#include <iostream>
#include "ReviewNamespace.h"
#include "ReviewHeader.h"
// #include "ReviewFunction.cpp"

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
    return 0;
}
