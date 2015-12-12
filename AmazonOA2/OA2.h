#ifndef OA2_H_INCLUDED
#define OA2_H_INCLUDED


#include<vector>
#include<iostream>
#include<cstddef>
#include<deque>
#include<list>
#include "TreeNode.h"
#include "ListNode.h"


using namespace std;

void InitializeMatrix(vector< vector<int> > &matrix, int nums[][4]);
void PrintMatrix(vector< vector<int> > matrix);
vector< vector<int> > RotateMatrix(vector< vector<int> > matrix, bool flag);
int MinPathSum(vector< vector<int> > grid);

int MinTreePathSum();

int GreatestCommonDividerNaive(int a, int b);
int GreatestCOmmonDividerEuclid(int a, int b);
int MinTreePathSum(TreeNode *head);
int MinTreePathSumStackoverflow(TreeNode *head, list<TreeNode *> &path);

ListNode *ReverseHalfLinkedList(ListNode *head);


#endif // OA2_H_INCLUDED
