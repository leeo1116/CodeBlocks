#include "Leetcode.h"


int MaxGap(vector<int> &nums){
    int n = nums.size();
    if(n < 2)
        return 0;
    auto minMaxIt = minmax_element(nums.begin(), nums.end());
    int minNum = *(minMaxIt.first), maxNum = *(minMaxIt.second);
    int gap = max((maxNum-minNum)/(n-1), 1);
    int bucketNum = (maxNum-minNum)/gap+1;
    vector<vector<int>> buckets(bucketNum, {INT_MAX, INT_MIN});
    for(int num : nums){
        int i = (num-minNum)/gap;
        if(num < buckets[i][0])
            buckets[i][0] = num;
        if(num > buckets[i][1])
            buckets[i][1] = num;
    }
    int j = 0, k;
    gap = buckets[0][1] - buckets[0][0];
    while(j < bucketNum){
        k = j+1;
        while(k < bucketNum && buckets[k][0] == INT_MAX && buckets[k][1] == INT_MIN)
            k++;
        if(k == bucketNum)
            break;
        gap = max(gap, buckets[k][0]-buckets[k][1]);
        j = k;
    }
    return gap;
}
