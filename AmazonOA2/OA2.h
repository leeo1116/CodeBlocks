#ifndef OA2_H_INCLUDED
#define OA2_H_INCLUDED


#include<vector>
#include<iostream>
#include<cstddef>
#include "TreeNode.h"


using namespace std;

void InitializeMatrix(vector< vector<int> > &matrix, int nums[][4]);
void PrintMatrix(vector< vector<int> > matrix);
vector< vector<int> > RotateMatrix270(vector< vector<int> > matrix);
vector< vector<int> > RotateMatrix90(vector< vector<int> > matrix);
int MinPathSum(vector< vector<int> > grid);
int GreatestCommonDividerNaive(int a, int b);
int GreatestCOmmonDividerEuclid(int a, int b);
int MinTreePathSum(TreeNode *head);


#endif // OA2_H_INCLUDED
