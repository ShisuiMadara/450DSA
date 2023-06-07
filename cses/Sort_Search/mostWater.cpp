#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    int rec(vector<int>&height, int left, int right) {
        if(right <= left) {
            return 0;
        }

        if(dp[left][right] != -1) {
            return dp[left][right];
        }

        int ans = min(height[left], height[right]) * (right-left);
        cout<<ans<<" HI ";
        dp[left][right] = max(ans, dp[left][right]);
        rec(height, left+1, right);
        rec(height, left, right-1);

        return dp[left][right];
        
    }

    int maxArea(vector<int>& height) {

        int n = height.size();

        int left = 0;
        int right = n-1;
        int ans = -1;

        while(right > left) {
            ans = max(ans, min(height[left], height[right])*(right-left));

            if(height[left] >= height[right]) {
                right--;
            }else {
                left++;
            }
        }
        return ans;
    }
};