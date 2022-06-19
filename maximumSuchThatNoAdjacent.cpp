#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    int n;
    cin>>n;

    vector<int>v(n);

    for(auto&c:v)
    {
        cin>>c;

    }   

    int dp[n][2];
    //for each index -> what is the maximum if the index is included and what if its not
    
    memset(dp,0,sizeof(dp));

    dp[0][0] = 0;
    dp[0][1] = v[0];

    for(int i = 1; i< n; ++i)
    {
        dp[i][0] = max(dp[i][0], dp[i-1][1]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][0] + v[i]);
    } 

    cout<<max(dp[n-1][0], dp[n-1][1])<<'\n';

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
