#include <iostream>
#include "OA2.h"


int main(int argc, char **argv)
{
    cout << "Hello world!" << endl;
    int nums[][4] = {{1, 2, 3, 4}, {5, 6, 8, 9}, {0, 1, 4, 2}};
    int mazeArray[][4] = {{1, 0, 0, 0}, {1, 1, 1, 0}, {0, 1, 1, 9}, {0, 0, 0, 0}};
    int cellsArray[] = {0, 1, 1, 1};


    int dataArray[] = {1, 2, 3, 4, 5, 4, 1};
    int exeTimeArray[] = {5, 3, 8, 6};
    int arrivalTimeArray[] = {0, 1, 2, 3};
    vector< vector<int> > matrix(3, vector<int> (4, 1));
    vector< vector<int> > rotatedMatrix270(4, vector<int> (3, 1));
    vector< vector<int> > rotatedMatrix90(4, vector<int> (3, 1));
    vector< vector<int> > maze(4, vector<int> (4, 0));
    vector<int> cells(sizeof(cellsArray)/sizeof(cellsArray[0]), 0);
    vector<int> data(sizeof(dataArray)/sizeof(dataArray[0]), 0);
    vector<int> arrivalTime(sizeof(arrivalTimeArray)/sizeof(arrivalTimeArray[0]));
    vector<int> exeTime(sizeof(exeTimeArray)/sizeof(exeTimeArray[0]));


    list<TreeNode *> path;
    ListNode *l1 = new ListNode(7);
    ListNode *l2 = new ListNode(7);
    ListNode *l3 = new ListNode(7);
    ListNode *l4 = new ListNode(7);
    ListNode *l5 = new ListNode(7);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l1;

    string p = "(())()";
    cout << IsValidParenthesis(p) << endl;
    ListNode *pNewNode = InsertCyclicLinkedList(l3, 7);
    ListNode *pNewNodeTemp = pNewNode;
    cout << pNewNode->val << endl;
    pNewNode = pNewNode->next;
    while(pNewNode != pNewNodeTemp)
    {
        cout << pNewNode->val << endl;
        pNewNode = pNewNode->next;
    }

//    ListNode *newHead = ReverseHalfLinkedList(l1);
//    while(newHead)
//    {
//        cout << newHead->val << endl;
//        newHead = newHead->next;
//    }

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

    if(IsSameTree(head, n1))
        cout << "Same Tree!" << endl;
    else
        cout << "Not same tree" << endl;
    if(IsSubTree(head, n3))
        cout << "Is sub tree!" << endl;
    else
        cout << "Not sub tree" << endl;
    MinTreePathSumStackoverflow(head, path);

    cout << MinTreePathSum(head) << endl;


    InitializeMatrix(matrix, nums);
    InitializeMatrix(maze, mazeArray);

    PrintMatrix(matrix);
    rotatedMatrix270 = RotateMatrix(matrix, 0);
    rotatedMatrix90 = RotateMatrix(matrix, 1);
    PrintMatrix(rotatedMatrix270);
    PrintMatrix(rotatedMatrix90);
    cout << "Minimum path sum = " << MinPathSum(matrix) << endl;
    cout << "GCD_Plain = " << GreatestCommonDividerNaive(120, 24) << endl;
    cout << "GCD_Euclid = " << GreatestCOmmonDividerEuclid(120, 24) << endl;

    cout << endl;

    cout << Maze(maze) << endl;


    for(unsigned i = 0; i < sizeof(cellsArray)/sizeof(cellsArray[0]); i++)
    {

        cout << cellsArray[i] << " ";
        cells[i] = cellsArray[i];
    }
    cout << endl;
    vector<int> newCells = DayChange(cells, 2);
    for(unsigned i = 0; i < newCells.size(); i++)
        cout << newCells[i] << " ";
    cout << endl;

    for(unsigned i = 0; i < sizeof(dataArray)/sizeof(dataArray[0]); i++)
    {
        cout << dataArray[i] << " ";
        data[i] = dataArray[i];
    }
    cout << endl;
    cout << LRU_Cache(data, 4) << endl;


    for(unsigned i = 0; i < sizeof(arrivalTimeArray)/sizeof(arrivalTimeArray[0]); i++)
    {

        cout << arrivalTimeArray[i] << " ";
        arrivalTime[i] = arrivalTimeArray[i];
    }
    for(unsigned i = 0; i < sizeof(arrivalTimeArray)/sizeof(arrivalTimeArray[0]); i++)
    {

        cout << exeTimeArray[i] << " ";
        exeTime[i] = exeTimeArray[i];
    }
    cout << endl;
    cout << "Average wait time = " << ShortestJobFirst(arrivalTime, exeTime) << endl;

    cout << endl;
    cout << "Average wait time (RR) = " << RoundRobin(arrivalTime, exeTime, 3) << endl;
}
