#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int& target, int i, int last, vector<int>& dp){
        if(i == nums.size()-1) return 0;
        if(dp[i] != INT_MIN) return dp[i];
        int res = -1;
        for(int j = i+1; j < nums.size(); ++j){
            if(abs(nums[j] - last) <= target) {
                int t = solve(nums, target, j, nums[j], dp);
                if(t != -1) res = max(res, 1 + t );
            }
        }
        return dp[i] = res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), INT_MIN);
        return solve(nums, target, 0, nums[0], dp);
    }
};