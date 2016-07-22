#include "Leetcode.h"


int Solution::GetSum(int a, int b){
    if(b == 0)
        return a;
    int sum, carryIn;
    sum = a ^ b;
    carryIn = (a & b) << 1;
    return GetSum(sum, carryIn);
}
