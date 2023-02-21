#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s;
    cin>>s;

    int n = s.length();

    vector<vector<int>>dp(n+1, vector<int>(2,0));

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i-1]=='?'){
            dp[i][0] = dp[i-1][1] + 1;
            dp[i][1] = dp[i-1][0] + 1;
        } else if (s[i-1]=='0'){
            dp[i][0] = 1 +dp[i-1][1];
            dp[i][1] = 0;
        } else{
            dp[i][1] = 1 +dp[i-1][0];
            dp[i][0] = 0;
        }
        ans += max(dp[i][0],dp[i][1]);
    }
    cout<<ans<<"\n";
}


int main() {
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}