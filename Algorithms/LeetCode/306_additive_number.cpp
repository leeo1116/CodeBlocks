#include "Leetcode.h"


bool Solution::IsAdditiveNumber(string num){
    // Traverse i from 1 to half of the length of num, first number is [0, i), second number is [i, i+j)
    for(unsigned i = 1; i <= num.size()/2; i++){
        for(unsigned j = 1; j <= (num.size()-i)/2; j++){
            if(Check(num.substr(0, i), num.substr(i, j), num.substr(i+j))) return true;
        }
    }
    return false;
}


bool Solution::Check(string num1, string num2, string num){
    if((num1.size()>1 && num1[0] == '0') || (num2.size()>1 && num2[0] == '0')) return false;
    string sum = Add(num1, num2);
    if(num == sum) return true;
    if(num.size() < sum.size() || sum.compare(num.substr(0, sum.size())) != 0) return false;
    else return Check(num2, sum, num.substr(sum.size()));
}


string Solution::Add(string s1, string s2){
    string s;
    int i = s1.size()-1, j = s2.size()-1, carryIn = 0;
    while(i >= 0 || j >= 0 || carryIn > 0){
        int digitSum = carryIn+(i>=0 ? (s1[i--]-'0') : 0)+(j>=0 ? (s2[j--]-'0') : 0);
        s.insert(s.begin(), digitSum%10+'0');
        carryIn = digitSum/10;
    }
    return s;
}
