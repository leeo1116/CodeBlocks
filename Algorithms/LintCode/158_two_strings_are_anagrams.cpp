#include "LintCode.h"


/** \brief Solution-1 using unorder_map
 *
 * \param s: first string
 * \param t: second string
 * \return true or false
 *
 */
bool Solution::AnagramSolution1(string s, string t){
    unordered_map<char, int> charCountMap;
    for (char c1 : s)
        charCountMap[c1]++;
    for (char c2 : t)
        charCountMap[c2]--;
    for (auto kv : charCountMap) {
        if (kv.second != 0)
            return false;
    }
    return true;
}


/** \brief Solution-2 using array as unorder_map
 *
 * \param s: first string
 * \param t: second string
 * \return true or false
 *
 */
bool Solution::AnagramSolution2(string s, string t){
    int ascii[256] = {0};
    for (char c1 : s)
        ascii[c1-'a']++;
    for (char c2 : t)
        ascii[c2-'a']--;
    for (unsigned i = 0; i < 256; i++) {
        if (ascii[i] != 0)
            return false;
    }
    return true;
}
