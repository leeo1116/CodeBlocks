#include "Leetcode.h"


int Solution::CountDigitOne(int n){
    int ones = 0;
    for(long long i = 1; i <= n; i *= 10){
        int leftPart = n/i, rightPart = n%i;
        ones += (leftPart+8)/10*i+(leftPart%10 == 1)*(rightPart+1);
    }
    return ones;
}
