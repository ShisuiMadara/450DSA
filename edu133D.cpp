#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long


void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int>dp(n+1,0);
    
    //dp[k] = 1;
    for(int constant = 1; constant <=n/k; constant++)
    {    
        for(int point = 0; point<=n; ++point)
        {
            int stride = k;

            dp[point + stride*constant] += (dp[point]+1);
            
            k++;
        }
    }


    for(int i = 1; i<=n; ++i)
    {
        cout<<dp[i]<<" ";
    }
    return;
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
