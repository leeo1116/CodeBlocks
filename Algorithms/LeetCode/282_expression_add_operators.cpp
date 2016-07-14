#include "Leetcode.h"


vector<string> AddOperators(string num, int target){
    vector<string> exps;
    if(num.empty())
        return exps;
    for(unsigned i = 0; i < num.size(); i++){
        string s = num.substr(0, i);
        long cur = stol(s);
        if()
    }
}


void AddOperatorsDFS(vector<string> &exps, const string &num, const int target, string cur,
                     int pos, const long cv, const long pv, const char op){

}
