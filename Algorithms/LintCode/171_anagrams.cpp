#include "LintCode.h"


vector<string> Solution::Anagrams(vector<string> &strs) {
    unordered_map<string, int> strCntMap = {};
    for (unsigned i = 0; i < strs.size(); i++) {
        string sortedStr = GetSortedStr(strs[i]);
        if (strCntMap.find(sortedStr) == strCntMap.end())
            strCntMap[sortedStr] = 1;
        else
            strCntMap[sortedStr] += 1;
    }

    vector<string> anagramsVec;
    for (unsigned i = 0; i < strs.size(); i++) {
        string sortedStr = GetSortedStr(strs[i]);
        if (strCntMap[sortedStr] > 1)
            anagramsVec.push_back(strs[i]);
    }
    return anagramsVec;
}


string Solution::GetSortedStr(string &str) {
    int cnt[26] = {0};
    for (unsigned i = 0; i < str.size(); i++)
        cnt[str[i]-'a'] += 1;
    string sortedStr = "";
    for (unsigned i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            sortedStr = sortedStr+static_cast<char>('a'+i);
        }
    }
    return sortedStr;
}
