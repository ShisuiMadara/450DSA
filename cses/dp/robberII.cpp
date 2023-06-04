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
        vector<int>dp(101,-1);
        vector<int> withLast, withFirst;
        
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        for(int i = 1; i<n; ++i) {
            withLast.push_back(nums[i]);
        }

        for(int i = 0; i<n-1; ++i) {
            withFirst.push_back(nums[i]);
        }

        int ans1 = rec(n-2, withLast, dp);

        for(int i = 0;i<101; ++i) {
            dp[i] = -1;
        }

        int ans2 = rec(n-2, withFirst, dp);
        return max(ans1,ans2);

    }
};