#include "Leetcode.h"


string Solution::LargestNumber(vector<int> &nums){
    vector<string> numStr;
    for(auto n : nums)
        numStr.push_back(IntToString(n));
    // sort(begin(numStr), end(numStr), [](string &s1, string &s2){return s1+s2 > s2+s1;});     // uncomment this line to submit
    string largestNum;
    for(auto nSorted : numStr)
        largestNum += nSorted;
    while(largestNum[0] == '0' && largestNum.size() > 1)
        largestNum.erase(0, 1);
    return largestNum;
}


string Solution::IntToString(int i){
    string str;
    stringstream tmp;
    tmp << i;
    return tmp.str();
}

