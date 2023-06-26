#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        
        int n = nums.size();
        
        for(int i = 0; i<n; ++i) {
            if(s[i] == 'R') {
                nums[i] +=d;
            }else {
                nums[i] -= d;
            }
        }
        
        sort(nums.begin(), nums.end());
        
        vector<long long>pre(n);
        
        for(int i = 0; i<n; ++i) {
            pre[i] = nums[i];
        }
        int MOD = 1e9;
        
        for(int i = 1; i < nums.size(); i++){
            pre[i] += pre[i - 1];
            pre[i] %= MOD;
        }

        long long ans = 0;
        for(int i = 1; i < nums.size(); i++){
            ans += i * nums[i] - pre[i - 1];
            ans %= MOD;
        }
        
        return ans;
    }
};