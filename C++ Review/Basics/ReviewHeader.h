#ifndef REVIEW_H_INCLUDED
#define REVIEW_H_INCLUDED

#include <vector>
#define N 2

typedef int (*A)[N];

using namespace std;

int Factorial(int k);
void Swap(int& a, int& b);
int (*RotateArray90(int inputArray[][N]))[N];
void PrintArray(vector< vector<int> > matrix, int m, int n);

#endif // REVIEW_H_INCLUDED
