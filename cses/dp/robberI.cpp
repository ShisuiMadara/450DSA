#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int rec (int i, vector<int>&nums, vector<int>&dp) {

        if(i == 0) {
            return nums[0];
        }
    
        if(i < 0) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        dp[i] = max(rec(i-2, nums,dp) + nums[i], rec(i-1, nums,dp));
        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int>dp(1000,-1);
        return rec(nums.size()-1, nums,dp);

    }
};