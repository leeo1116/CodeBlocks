#include "Leetcode.h"


int Solution::MinCut(string s){
    int n = s.size(), cut[n];
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    for(int j = 0; j < n; j++){
        // initialize cut[j] as j for the worst case
        cut[j] = j;
        for(int i = 0; i <= j; i++){
            if(s[i] == s[j] && (j-i <= 1 || isPal[i+1][j-1])){
                isPal[i][j] = true;
                // consider cutting on left only
                if(i > 0)
                    cut[j] = min(cut[j], cut[i-1]+1);
                else
                    cut[j] = 0;
            }
        }
    }
    return cut[n-1];
}
