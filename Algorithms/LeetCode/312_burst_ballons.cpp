#include "Leetcode.h"


int Solution::MaxCoins(vector<int> &nums){
    int numsLen = nums.size();
    int auxNums[numsLen+2];
    auxNums[0] = auxNums[numsLen+1] = 1;
    int j = 1;
    for(int i = 0; i < numsLen; i++)
        auxNums[j++] = nums[i];

    vector<vector<int>> maxCoins(numsLen+2, vector<int>(numsLen+2, 0));
    for(int k = 2; k < numsLen+2; k++){
        for(int left = 0; left < numsLen+2-k; left++){
            int right = left+k;
            for(int i = left+1; i < right; i++){
                maxCoins[left][right] = max(maxCoins[left][right],
                                            maxCoins[left][i]+auxNums[left]*auxNums[i]*auxNums[right]+maxCoins[i][right]);
            }
        }
    }
    return maxCoins[0][numsLen+1];
}


int maxCoinsDP(vector<int>& nums) {
    int num[nums.size()+2];
    int n = 1;
    for(int x : nums){
        num[n++] = x;
        cout << num[n-1] << ' ';
    }
    num[0] = num[n++] = 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));   // dp[i][j] means the maxScore we can reach by bursting all the balloons between (i,j)
    for(int k = 2; k < n; k++){
        for(int left = 0; left + k < n; left++){
            int right = left + k;
            for(int i = left+1; i < right; i++){
                dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + num[left]*num[right]*num[i]);
            }
        }
    }
    return dp[0][n-1];
}
