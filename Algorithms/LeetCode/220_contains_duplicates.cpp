#include "Leetcode.h"

bool Solution::ContainsDuplicatesIII(vector<int>& nums, int k, int t){
    map<int, int> valIndexMap;
    int i = 0;
    for(int j = 0; j < (int)nums.size(); j++){
        if(j-i > k && valIndexMap[nums[i]] == i)
            valIndexMap.erase(valIndexMap.begin());
        auto it = valIndexMap.lower_bound(nums[j]-t);
        if(it != valIndexMap.end() && abs(it->first-nums[j]) <= t) return true;
        valIndexMap[nums[j]] = j;
    }
    return false;
}
