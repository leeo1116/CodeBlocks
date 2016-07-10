#include "Leetcode.h"


/** \brief ab % k = (a%k)(b%k)%k
 *         a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (((a^123456) % k) ^ 10 ) % k * a^7 % k
 *         Suppose f(a, b) calculates a^b % k
 *         f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k
 *
 * \param
 * \param
 * \return
 *
 */
int Solution::SuperPow(int a, vector<int> &b){
    const int base = 1337;
    if(b.empty())
        return 1;
    int lastDigit = b.back();
    b.pop_back();
    return PowMod(SuperPow(a, b), 10, base)*PowMod(a, lastDigit, base)%base;
}


// a^k % base
int Solution::PowMod(int a, int k, const int base){
    a %= base;
    int result = 1;
    for(int i = 0; i < k; i++)
        result = (result*a)%base;
    return result;
}
