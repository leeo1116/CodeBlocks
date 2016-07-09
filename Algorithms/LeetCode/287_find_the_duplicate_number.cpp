#include "Leetcode.h"


int Solution::FindDuplicate(vector<int> &nums){
    if(nums.size() < 2)
        return -1;
    int slow = nums[0];
    int fast = nums[nums[0]];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = 0;
    while(fast != slow){
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}
