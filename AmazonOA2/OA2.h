#ifndef OA2_H_INCLUDED
#define OA2_H_INCLUDED


#include<vector>
#include<iostream>
#include<cstddef>


using namespace std;

void InitializeMatrix(vector< vector<int> > &matrix, int nums[][4]);
void PrintMatrix(vector< vector<int> > matrix);
vector< vector<int> > RotateMatrix270(vector< vector<int> > matrix);
vector< vector<int> > RotateMatrix90(vector< vector<int> > matrix);
int MinPathSum(vector< vector<int> > grid);
int MinTreePathSum()

#endif // OA2_H_INCLUDED
