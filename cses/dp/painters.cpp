#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
     int memo(vector<int>&cost, vector<int> &time, int index, int walls, vector<vector<int>> &dp) {
         int n = cost.size();
        if(walls <= 0) return 0;//can be one of the possible way
        if(index >= n ) return 1e9;//Neglect this by returning unusually large value
        if(dp[index][walls] != -1) return dp[index][walls];

        int notTake = 0 + memo(cost, time, index + 1, walls, dp);
        int take = cost[index] + memo(cost, time, index + 1, walls- time[index] - 1, dp);
        return dp[index][walls] = min(notTake, take);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return memo(cost, time, 0, n, dp);

        
    }
};