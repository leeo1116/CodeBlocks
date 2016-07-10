#include "Leetcode.h"


int FindMinII(vector<int> &nums){
    int low = 0, mid = 0, high = nums.size()-1;
    while(low < high){
        mid = low+(high-low)/2;
        if(nums[mid] < nums[high])
            high = mid;
        else if(nums[mid] > nums[high])
            low = mid+1;
        else
            high --;
    }
    return nums[low];
}
