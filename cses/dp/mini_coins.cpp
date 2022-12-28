#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    int n, target;
    cin>>n>>target;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    vector<int>dp(target+1, INT_MAX);

    dp[0] = 0;

    for(int i = 0; i <= target; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i - arr[j] >= 0) {
                dp[i] = min(dp[i], 1+dp[i - arr[j]]);
            }
        }
    }

    cout << (dp[target] == INT_MAX ? -1 : dp[target]);
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
