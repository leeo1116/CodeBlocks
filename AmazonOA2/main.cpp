#include <iostream>
#include "OA2.h"


int main()
{
    cout << "Hello world!" << endl;
    int nums[][4] = {{1, 2, 3, 4}, {5, 6, 8, 9}, {0, 1, 4, 2}};
    vector< vector<int> > matrix(3, vector<int> (4, 1));
    vector< vector<int> > rotatedMatrix270(4, vector<int> (3, 1));
    vector< vector<int> > rotatedMatrix90(4, vector<int> (3, 1));

    InitializeMatrix(matrix, nums);
    PrintMatrix(matrix);
    rotatedMatrix270 = RotateMatrix270(matrix);
    rotatedMatrix90 = RotateMatrix90(matrix);
    PrintMatrix(rotatedMatrix270);
    PrintMatrix(rotatedMatrix90);
    cout << MinPathSum(matrix) << endl;



    cout << endl;


}
