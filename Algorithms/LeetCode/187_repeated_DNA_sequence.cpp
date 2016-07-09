#include "Leetcode.h"


vector<string> Solution::FindRepeatedDNA_Sequences(string s){
    if(s.size() < 10)
        return {};
    vector<string> repeatSeq;
    unordered_map<int, int> seqCountMap;
    for(unsigned i = 0; i <= s.size()-10; i++){
        if(seqCountMap[Str2Int(s.substr(i, 10))]++ == 1)
            repeatSeq.push_back(s.substr(i, 10));
    }
    return repeatSeq;
}


int Solution::Str2Int(string s){
    int code = 0;
    for(unsigned i = 0; i < s.size(); i++)
        code = (code<<3) + (s[i]&7);
    return code;
}
