#include "Leetcode.h"


void SummaryRanges::AddNum(int val){
    auto Compare = [](Interval a, Interval b){return a.start < b.start;};
    vector<Interval>::iterator it = lower_bound(intervalVec.begin(), intervalVec.end(), Interval(val, val), Compare);
    int start = val, stop = val;
    if(it != intervalVec.begin() && (it-1)->stop+1 >= val)
        it--;
    while(it != intervalVec.end() && val+1 >= it->start && val-1 <= it->stop){
        start = min(start, it->start);
        stop = max(stop, it->stop);
        it = intervalVec.erase(it);
    }
    intervalVec.insert(it, Interval(start, stop));
}


vector<Interval> SummaryRanges::GetIntervals(){
    return intervalVec;
}
