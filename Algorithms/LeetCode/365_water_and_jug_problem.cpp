#include "Leetcode.h"


bool Solution::CanMeasureWater(int x, int y, int z){
    if(x+y < z)
        return false;
    if(x == z || y == z)
        return true;
    return z%GCD(x, y) == 0;
}


int Solution::GCD(int a, int b){
    if(a == 0)
        return b;
    return GCD(b%a, a);

    // Iteratively
//    int tmp;
//    while(a != 0){
//        tmp = a;
//        a = b%a;
//        b = tmp;
//    }
}
