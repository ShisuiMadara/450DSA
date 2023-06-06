#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001];
    int solve(string s, int i){
        
        int n = s.length();
        if(dp[i]!=-1) return dp[i];
        
        if(s[i]=='0') return 0;
        if(i==n-1) return 1;

        if(i>=n) {
            return 1;
        }
        
        int single = solve(s,i+1);
        
        string a = s.substr(i,2);
        int val = stoi(a);
        int pair=0;
        if(val>0 && val<=26){
            pair = solve(s,i+2);
        }
        return dp[i] = single+pair;
        
    }
    
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};