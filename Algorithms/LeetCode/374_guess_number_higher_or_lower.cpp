#include "Leetcode.h"


int Solution::GuessNumber(int n){
    return GuessHelper(n, 1, n);
}


int Solution::GuessHelper(int n, int low, int high){
    int median = low+(high-low)/2;
    if(Guess(median) == -1)
        return GuessHelper(n, low, median);
    else if(Guess(median) == 1)
        return GuessHelper(n, median, high);
    else
        return median;
}
