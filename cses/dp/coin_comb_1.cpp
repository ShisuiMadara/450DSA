#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    int n,target;
    cin>>n>>target;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    vector<int>dp(target+1,0);

    dp[0] = 1;

    for(int i = 1; i<=target; ++i) {
        for(int j = 0; j <n; ++j) {
            if(i - arr[j] >= 0) {
                dp[i] += (dp[i-arr[j]]) % MOD;
                dp[i]%=MOD;
            }
        } 
    }

    cout<<dp[target];

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
