#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


int solve(int n, int m, vector<int>& v)
{
    int dp[n+2][m+2];
    memset(dp, 0, sizeof dp);
 
    for(int i = 1; i <= n; i++)
    {
        for(int x = 1; x <= m; x++)
        {
            if(i == 1)
            {
                if(v[i] == 0 || v[i] == x)
                    dp[i][x] = 1;
                else dp[i][x] = 0;
            }
            else
            {
                if(v[i] == 0 || v[i] == x){
                    dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%MOD + dp[i-1][x+1])%MOD;
                }
                else dp[i][x] = 0;
            }
        }
    }
 
    int ans = 0;
    for(int x = 1; x <= m; x++)
        ans = (ans + dp[n][x]) % MOD;
    return ans;
}
 
signed main() {

   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        int n,m;
        cin >> n >> m;
        vector<int> v(n+1);
        for(int i = 1; i<=n; ++i)
            cin >> v[i];
        cout << solve(n,m,v);
   }
   return 0;
}