#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n);
    for(auto&c:arr)cin>>c;

    int dp[n];

    memset(dp,0,sizeof(dp));

    dp[0] = arr[0];
    dp[1] = max(dp[0], arr[1] + arr[0]);
    dp[2] = max(arr[0] + arr[2], max(arr[0] + arr[1], arr[1] + arr[2]));

    for(int i = 3; i< n; ++i)
    {
        dp[i] = max(dp[i-1], max(dp[i-2] + arr[i], dp[i-3] + arr[i] + arr[i-1]));
    }    

    cout<<dp[n-1]<<'\n';
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
