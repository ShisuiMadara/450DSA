#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    int dp[k+1][n+1];

    memset(dp,0,sizeof(dp));

    for(int i = 1; i<= k; ++i)
    {
        for(int len = 1; len <= n; ++len)
        {
            dp[i][len] = dp[i][len-1];

            if(i >= arr[len-1])
            {
                dp[i][len] += dp[i/arr[len-1]][len-1] + 1;
            }
        }
    }

    cout<<dp[k][n]<<'\n';

}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

     ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
