#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    int n;
    cin>>n;
 
    vector<long long>dp(n+1);
    dp[0] = 1;
 
    for(int i = 0; i<= n; ++i)
    {
        for(int j = 1; j<=6 && i-j >= 0; ++j)
        {
            dp[i] += dp[i-j];
            dp[i] = dp[i]%1000000007;
        }
    }
    cout<<dp[n];

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
