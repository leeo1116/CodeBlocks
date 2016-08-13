#include "LintCode.h"


int main(int argc, char **argv)
{
    string s1 = "bcade", s2 = "bcade";
    Solution s;
    cout << s.AnagramSolution1(s1, s2) << ' ' << s.AnagramSolution2(s1, s2) << endl;
    cout << s.CompareStrings("ABCD", "DEAC") << endl;
    const char *source = "aiangli", *target = "li";
    cout << s.StrStrNaive(source, target) << endl;
    vector<string> s3 = {"ac","bac", "ca", "bdca", "cab"};
    for (auto a : s.Anagrams(s3))
        cout << a << ' ';
    return 0;
}
