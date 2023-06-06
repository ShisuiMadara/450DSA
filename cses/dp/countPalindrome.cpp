#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int count(string s, int left, int right, vector<vector<int>>&dp) {

        if(dp[left][right] > -1) {
            return dp[left][right];
        }

         if(left >= right) {
            dp[left][right] = 1;
            return dp[left][right];
        }

        if(s[left] == s[right]) {
            dp[left][right] = count(s,left+1, right-1, dp);
        }

        count(s,left+1,right, dp);
        count(s,left,right-1, dp);

        return dp[left][right] == -1 ? 0 : 1;
    }

    int countSubstrings(string s) {
        
        vector<vector<int>>dp(s.length(), vector<int>(s.length(), -1));

        count(s,0,s.length()-1,dp);
        int ans = 0;
        int xtra = 0;
        for(int i = 0; i<s.length(); ++i) {
            for(int j = 0; j<s.length(); ++j) {
                if(dp[i][j] == 1) {
                    ans++;
                }
                if(dp[i][j] == 1 && dp[j][i] == 1 && (i != j)) {
                    xtra++;
                }
            }
           
        }
      
        return ans-xtra/2;
    }
};