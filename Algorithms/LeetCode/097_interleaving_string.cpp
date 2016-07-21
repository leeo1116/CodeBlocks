#include "Leetcode.h"


bool Solution::IsInterleave(string s1, string s2, string s3){
    if(s3.size() != s1.size()+s2.size())
        return false;
    bool interleaved[s1.size()+1][s2.size()+1];
    for(unsigned i = 0; i < s1.size()+1; i++){
        for(unsigned j = 0; j < s2.size()+1; j++){
            if(i == 0 && j ==0)
                interleaved[i][j] = true;
            else if(i == 0)
                interleaved[i][j] = (interleaved[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                interleaved[i][j] = (interleaved[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                interleaved[i][j] = (interleaved[i][j-1] && s2[j-1] == s3[i+j-1]) || (interleaved[i-1][j] && s1[i-1] == s3[i+j-1]);
        }
    }
    return interleaved[s1.size()][s2.size()];
}
