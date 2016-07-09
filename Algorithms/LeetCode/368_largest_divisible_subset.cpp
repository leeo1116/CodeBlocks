#include "Leetcode.h"


vector<int> Solution::LargestDivisibleSubset(vector<int> &nums){
    int maxSubsetLen = 0, maxIndex;
    vector<int> subsetLen(nums.size(), 0);
    vector<int> preDivNum(nums.size(), 0);

    sort(nums.begin(), nums.end());
    for(unsigned i = 0; i < nums.size(); i++){
        for(int j = i; j > -1; j--){
            if(nums[i] % nums[j] == 0 && subsetLen[i] < subsetLen[j]+1){
                subsetLen[i] = subsetLen[j]+1;
                preDivNum[i] = j;
            }
        }
        if(subsetLen[i] > maxSubsetLen){
            maxSubsetLen = subsetLen[i];
            maxIndex = i;
        }
    }
    vector<int> subset;
    for(int i = 0; i < maxSubsetLen; i++){
        subset.insert(subset.begin(), nums[maxIndex]);
        maxIndex = preDivNum[maxIndex];
    }
    return subset;
}
//vector<int> Solution::LargestDivisibleSubset(vector<int> &nums){
//    sort(nums.begin(), nums.end());
//    vector<int> T(nums.size(), 0);
//    vector<int> parent(nums.size(), 0);
//    vector<int> subset;
//    int m = 0, mi = 0;
//
//    for(int i = nums.size()-1; i > -1; i--){
//        for(int j = i; j < nums.size(); j++){
//            if(nums[j] % nums[i] == 0 && T[i] < 1+T[j]){
//                T[i] = 1+T[j];
//                parent[i] = j;
//                if(T[i] > m){
//                    m = T[i];
//                    mi = i;
//                }
//            }
//        }
//    }
//
//    for(int i = 0; i < m; i++){
//        subset.push_back(nums[mi]);
//        mi = parent[mi];
//    }
//
//    return subset;
//}



