#include "OA1.h"


bool Search2DimMatrix(vector< vector<int> > &matrix, int target)
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
