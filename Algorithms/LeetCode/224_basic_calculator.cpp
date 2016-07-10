#include "Leetcode.h"


int Solution::Calculate(string s){
    stack<int> nums, optr;
    int num = 0, result = 0, sign = 1;
    for(char c : s){
        if(isdigit(c))
            num = num*10+c-'0';
        else{
            result += sign*num;
            num = 0;
            if(c == '+')
                sign = 1;
            if(c == '-')
                sign = -1;
            if(c == '('){
                nums.push(result);
                optr.push(sign);
                result = 0;
                sign = 1;
               }
            if(c == ')' && optr.size()){
                result = optr.top()*result+nums.top();
                optr.pop();
                nums.pop();
            }
        }
    }
    result += sign*num;
    return result;
}
