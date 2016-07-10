#include "Leetcode.h"


int Solution::LongestConsecutive(vector<int> &nums){
    int maxLen = 0;
    unordered_map<int, int> boundLenMap;
    for(int n : nums){
        if(boundLenMap.find(n) == boundLenMap.end()){
            int left = (boundLenMap.find(n-1) != boundLenMap.end()) ? boundLenMap[n-1] : 0;
            int right = (boundLenMap.find(n+1) != boundLenMap.end()) ? boundLenMap[n+1] : 0;
            int sum = left+right+1;
            boundLenMap[n] = boundLenMap[n-left] = boundLenMap[n+right] = sum;
            maxLen = max(maxLen, sum);
        }
    }
    return maxLen;
}
