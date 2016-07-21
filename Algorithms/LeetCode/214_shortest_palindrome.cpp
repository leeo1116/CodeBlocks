#include "Leetcode.h"


string Solution::ShortestPalindrome(string s){
    string sRev = s;
    reverse(sRev.begin(), sRev.end());
    string l = s+'#'+sRev;

    vector<int> p(l.size(), 0);
    for(int i = 1; i < l.size(); i++){
        int j = p[i-1];
        while(j > 0 && l[i] != l[j])
            j = p[j-1];
        p[i] = (j += l[i] == l[j]);
    }
    return sRev.substr(0, s.size()-p[l.size()-1])+s;
}
