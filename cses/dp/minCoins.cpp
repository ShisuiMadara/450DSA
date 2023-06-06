#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int dp[13][10001];
    int minCoin(vector<int> &coins, int cur, int amount) 
    {
        if(cur==0)
            return (amount%coins[0]==0) ? amount/coins[0] : 1e9;
        if(dp[cur][amount]!=-1)
            return dp[cur][amount];
        int doNotTakeCoin = 0 + minCoin(coins, cur-1, amount);
        int takeCoin = INT_MAX;
        if(coins[cur] <= amount) 
            takeCoin = 1 + minCoin(coins, cur, amount-coins[cur]);
        return dp[cur][amount] = min(takeCoin, doNotTakeCoin);
    }
    int coinChange(vector<int> &coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        int res = minCoin(coins, coins.size()-1, amount);
        return (res >= 1e9) ? -1 : res;
    }
};