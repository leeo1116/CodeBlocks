#include<limits.h>
#include "OA1.h"


bool Search2DimMatrix(vector< vector<int> > matrix, int target)
{
    int m = matrix.size();
    if(!m)
    {
        return false;
    }
    int n = matrix[0].size();

    int i = 0, j = n-1;
    while(i < m && j > -1)
    {
        if(matrix[i][j] < target)
            i++;
        else if(matrix[i][j] > target)
            j--;
        else
            return true;
    }
    return false;
}


/** Find minimum value inside window
 *
 * Parameter: nums[] - input array
 * Parameter: numsLen - input array length
 * Parameter: winLen - window size
 *
 */
int *WindowMin(int nums[], int numsLen, int winLen)
{
    int rNumLen = numsLen-winLen+1;
    int *rNums = new int[rNumLen];

    // int rNums[rNumLen];
    // After returning, the rNums will be out of its storage scope;
    // only first memory address will be maintained, cause problems later

    for(int i = 0; i <= numsLen-winLen; i++)
    {
        int tempMin = nums[i];
        for(int j = 0; j < winLen; j++)
        {
            if(nums[i+j] < tempMin)
                tempMin = nums[i+j];
        }
        rNums[i] = tempMin;
    }
    return rNums;
}


void DFS(vector< vector<int> > matrix, int r, int c, int i, int j, int localMin, int &globalMax)
{
    if(i >= r || j >= c)
        return;
    localMin = min(localMin, matrix[i][j]);
    if(i == r-1 && j == c-1)
    {
        globalMax = max(globalMax, localMin);
        return;
    }
    DFS(matrix, r, c, i+1, j, localMin, globalMax);
    DFS(matrix, r, c, i, j+1, localMin, globalMax);
}

int MaxMinPath(vector< vector<int> > matrix, int r, int c)
{
    int globalMax = INT_MIN;
    DFS(matrix, r, c, 0, 0, matrix[0][0], globalMax);
    return globalMax;
}
