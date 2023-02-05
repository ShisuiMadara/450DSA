#include<bits/stdc++.h>
using namespace std;
//#define int   long long
//const int inf=1000000000000000000;
const int mod=998244353; 
//const int mod=1000000007;
typedef long long ll;


double dp[3003][3003],a[3003];
ll n;
 
void solve() {
 
    cin>>n;
    
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = dp[i-1][0] * (1 - a[i]);
        
        for(int heads = 1;heads <= i; heads++)
        {
            dp[i][heads] = a[i] * (dp[i-1][heads - 1]) + (1 - a[i]) * (dp[i-1][heads]);
        }
    }
    
    double ans = 0;
    
    for(int i=n/2 + 1;i <= n;i++)
    {
        ans += dp[n][i];
    }
    
    cout<<setprecision(10)<<ans;
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



    int test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
