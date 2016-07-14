#include "Leetcode.h"


int Solution::MaxEnvelopes(vector<pair<int, int>> &envelopes){
    vector<int> temp;
    sort(envelopes.begin(), envelopes.end(), CompareFirst);
    for(unsigned i  = 0; i < envelopes.size(); i++){
        vector<int>::iterator it = lower_bound(temp.begin(), temp.end(), envelopes[i].second);
        if(it == temp.end())
            temp.push_back(envelopes[i].second);
        else
            *it = envelopes[i].second;
    }
    return temp.size();
}


bool Solution::CompareFirst(const pair<int, int> &i, const pair<int, int> &j){
    if(i.first == j.first)
        return i.second > j.second;
    return i.first < j.first;
}
