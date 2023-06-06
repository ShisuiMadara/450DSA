#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1005][1005];
    int check(string s, int left, int right) {
        if(dp[left][right] != -1) {
            return dp[left][right];
        }
        if(left == right) {
            dp[left][right] = 1;
            return dp[left][right];
        }
        if(left > right) {
            return dp[left][right] = 0;
        }
        

        if(s[left] == s[right]) {
            return 2 + check(s, left+1, right-1);
        }

        return dp[left][right] = max(check(s,left+1,right), check(s,left, right-1));
    }


    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        memset(dp, -1, sizeof(dp));
     
        return check(s, 0, n-1);
    }
};