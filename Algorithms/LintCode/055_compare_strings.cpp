#include "LintCode.h"


bool Solution::CompareStrings(string A, string B){
    int letterCnt[26] = {0};
    for (char c1 : A)
        letterCnt[c1-'A']++;
    for (char c2 : B)
        letterCnt[c2-'A']--;
    for (int cnt : letterCnt)
        if (cnt < 0)
            return false;
    return true;
}
