#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    int n;
    cin>>n;

    vector<int>dp(n+1,INT_MAX);

    dp[0] = 0;

    for(int i = 1; i<= n; ++i) {
        string s = to_string(i);

        if(s.length() == 1) {
            dp[i] = 1;
            continue;
        }

        for(int j = 0; j< s.length() ; ++j) {
            dp[i] = min(dp[i],dp[i-(s[j] - '0')] + 1);
        }
    }

    cout<< (dp[n] == INT_MAX ? -1 : dp[n]);
}



signed main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


     ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
