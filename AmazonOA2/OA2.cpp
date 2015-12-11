#include "OA2.h"


void InitializeMatrix(vector< vector<int> > &matrix, int nums[][4])
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            matrix[i][j] = nums[i][j];
        }
    }
}


void PrintMatrix(vector< vector<int> > matrix)
{
    int m = matrix.size();
    if(!m)
    {
        cout << "Empty Vector" << endl;
        return;
    }
    int n = matrix[0].size();
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;

}


vector< vector<int> > RotateMatrix270(vector< vector<int> > matrix)
{
    int m = matrix.size();
    if(!m)
        return matrix;
    int n = matrix[0].size();
    vector< vector<int> > rotatedMatrix(n, vector<int> (m, 0));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            rotatedMatrix[j][m-i-1] = matrix[i][j];
        }
    }
    return rotatedMatrix;

}


vector< vector<int> > RotateMatrix90(vector< vector<int> > matrix)
{
    int m = matrix.size();
    if(!m)
        return matrix;
    int n = matrix[0].size();
    vector< vector<int> > rotatedMatrix(n, vector<int> (m, 0));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            rotatedMatrix[n-j-1][i] = matrix[i][j];
        }
    }
    return rotatedMatrix;

}


int MinPathSum(vector< vector<int> > grid)
{
    int m = grid.size();
    if(!m)
        return 0;
    int n = grid[0].size();

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 and j == 0)
                grid[i][j] = grid[i][j];
            else if(i == 0 and j != 0)
                grid[i][j] += grid[i][j-1];
            else if(j == 0 and i != 0)
                grid[i][j] += grid[i-1][j];
            else
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[m-1][n-1];
}



