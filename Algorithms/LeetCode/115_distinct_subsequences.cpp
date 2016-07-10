#include "Leetcode.h"


int Solution::DistinctNum(string s, string t){
    int distinctNum_ij[t.size()+1][s.size()+1];
    for(unsigned j = 0; j <= s.size(); j++)
        distinctNum_ij[0][j] = 1;

    for(unsigned i = 0; i < t.size(); i++){
        for(unsigned j = 0; j < s.size(); j++){
            if(t[i] == s[j])
                distinctNum_ij[i+1][j+1] = distinctNum_ij[i][j]+distinctNum_ij[i+1][j];
            else
                distinctNum_ij[i+1][j+1] = distinctNum_ij[i+1][j];
        }
    }
    return distinctNum_ij[t.size()][s.size()];
}
