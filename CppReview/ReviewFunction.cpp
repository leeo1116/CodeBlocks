#include <iostream>
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
