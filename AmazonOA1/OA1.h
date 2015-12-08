#ifndef OA1_H_INCLUDED
#define OA1_H_INCLUDED

#include <vector>

using namespace std;

#define row 3
#define col 3


bool Search2DimMatrix(vector< vector<int> > matrix, int target);
int *WindowMin(int nums[], int numsLen, int winLen);
int MaxMinPath(vector< vector<int> > matrix, int r, int c);


#endif // OA1_H_INCLUDED
