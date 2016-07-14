#include "Leetcode.h"


int MaxProfit(int k, vector<int>& prices){
    if(k == 0 || prices.empty())
        return 0;
    const int n = prices.size();
    if(k >= n/2)
        return MaxProfitInf(prices);

    vector<int> balance(k+1, INT_MIN), profit(k+1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            balance[j] = max(profit[j-1]-prices[i], balance[j]);
        }
    }


}
