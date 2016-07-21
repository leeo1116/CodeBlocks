#include "Leetcode.h"


int Solution::CalculateMinimumHP(vector<vector<int>> &dungeon){
    int m = dungeon.size();
    int n = dungeon[0].size();

    // hp[i][j] denotes the min health point needed at position i, j, add row at bottom and right
    vector<vector<int>> hp(m+1, vector<int>(n+1, INT_MAX));
    hp[m][n-1] = 1;
    hp[m-1][n] = 1;
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            int need = min(hp[i+1][j], hp[i][j+1])-dungeon[i][j];
            hp[i][j] = need < 0 ? 1 : need;
        }
    }
    return hp[0][0];
}
