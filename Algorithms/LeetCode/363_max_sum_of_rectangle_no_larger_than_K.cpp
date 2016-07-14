#include "Leetcode.h"


int MaxSumSubmatrix(vector<vector<int>> &matrix, int k){
    if(matrix.empty())
        return 0;
    int row = matrix.size(), col = matrix[0].size(), maxSum = INT_MIN;
    for(int left = 0; left < col; left++){
        vector<int> sums(row, 0);
        for(int right = left; right < col; right++){
            for(int i = 0; i < row; i++)
                sums[i] += matrix[i][right];
            // find max sub-array no more than k
            set<int> accumSumSet;
            accumSumSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for(int sum : sums){
                curSum += sum;
                set<int>::iterator it = accumSumSet.lower_bound(curSum-k);
                if(it != accumSumSet.end())
                    curMax = max(curMax, curSum-*it);
                accumSumSet.insert(curSum);
            }
            maxSum = max(maxSum, curMax);
        }
    }
    return maxSum;
}
