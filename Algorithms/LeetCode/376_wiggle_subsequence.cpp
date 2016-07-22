#include "Leetcode.h"


int Solution::MaxWiggleLength(vector<int> &nums){
    int numsLen = nums.size();
    // wiggle length with last number is increasing or decreasing
    int incNum = 1, decNum = 1;
    for(int i = 1; i < numsLen; i++){
        if(nums[i] > nums[i-1])
            incNum = decNum+1;
        if(nums[i] < nums[i-1])
            decNum = incNum+1;
    }
    return min(numsLen, max(incNum, decNum));
}
