#include <iostream>
#include "OA2.h"


int main(int argc, char **argv)
{
    cout << "Hello world!" << endl;
    int nums[][4] = {{1, 2, 3, 4}, {5, 6, 8, 9}, {0, 1, 4, 2}};
    vector< vector<int> > matrix(3, vector<int> (4, 1));
    vector< vector<int> > rotatedMatrix270(4, vector<int> (3, 1));
    vector< vector<int> > rotatedMatrix90(4, vector<int> (3, 1));
    list<TreeNode *> path;
    vector<int> a(2, 0);
    vector<int> b(2, 1);
    a.insert(a.end(), b.begin(), b.end());

    TreeNode *head = new TreeNode(3);
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(1);
    TreeNode *n3 = new TreeNode(2);
    TreeNode *n4 = new TreeNode(5);
    TreeNode *n5 = new TreeNode(1);
    head->left = n1;
    head->right = n2;
    n1->left = n3;
    n2->right = n4;
    n3->left = n5;

    MinTreePathSumStackoverflow(head, path);

    cout << MinTreePathSum(head) << endl;


    InitializeMatrix(matrix, nums);
    PrintMatrix(matrix);
    rotatedMatrix270 = RotateMatrix(matrix, 0);
    rotatedMatrix90 = RotateMatrix(matrix, 1);
    PrintMatrix(rotatedMatrix270);
    PrintMatrix(rotatedMatrix90);
    cout << "Minimum path sum = " << MinPathSum(matrix) << endl;
    cout << "GCD_Plain = " << GreatestCommonDividerNaive(120, 24) << endl;
    cout << "GCD_Euclid = " << GreatestCOmmonDividerEuclid(120, 24) << endl;

    cout << endl;


}
