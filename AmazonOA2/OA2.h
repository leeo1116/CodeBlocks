#ifndef OA2_H_INCLUDED
#define OA2_H_INCLUDED


#include<vector>
#include<iostream>
#include<cstddef>
#include<deque>
#include<list>
#include<string>
#include<stack>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<queue>
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
ListNode *InsertCyclicLinkedList(ListNode *start, int x);

bool IsSameTree(TreeNode *h1, TreeNode *h2);
bool IsSubTree(TreeNode *r1, TreeNode *r2);

int IsValidParenthesis(string p);
int Maze(vector< vector<int> > m);
vector<int> DayChange(vector<int> cells, int days);
int LRU_Cache(vector<int> data, unsigned capacity);

float ShortestJobFirst(vector<int> arrivalTime, vector<int> exeTime);
float RoundRobin(vector<int> arrivalTime, vector<int> exeTime, int q);

#endif // OA2_H_INCLUDED
