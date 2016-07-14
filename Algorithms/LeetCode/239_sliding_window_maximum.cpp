#include "Leetcode.h"


vector<int> MaxSlideWindow(vector<int> &nums, int k){
    deque<int> dq;
    vector<int> win;
    for(int i = 0; i < (int)nums.size(); i++){
        // Maintaining that there are k numbers in the window
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();
        // If the tail element is smaller than current element, pop it until it is greater or reaches the front
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if(i >= k-1)
            win.push_back(nums[dq.front()]);
    }
    return win;
}
