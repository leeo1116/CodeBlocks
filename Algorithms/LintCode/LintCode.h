#ifndef LINTCODE_H_INCLUDED
#define LINTCODE_H_INCLUDED

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
private:

public:
    // 158. two strings are anagrams
    bool AnagramSolution1(string s, string t);
    bool AnagramSolution2(string s, string t);
    // 055. compare strings
    bool CompareStrings(string A, string B);
    // 013. strStr
    int StrStrNaive(const char *source, const char *target);
    int StrStrKMP(const char *source, const char *target);
};

#endif // LINTCODE_H_INCLUDED
