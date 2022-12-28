#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
	int n;
	cin>>n;
	
	int money;
	cin>>money;
	
	vector<int>cost(n),pages(n);
	
	for(auto&c:cost)cin>>c;
	
	for(auto&c:pages)cin>>c;
	
	vector<vector<int>>dp(n+1,vector<int>(money+1,0));
	
	for(int i = 1; i<= n; ++i)
	{
		for(int j = 0; j<=money; ++j)
		{
			dp[i][j] = dp[i-1][j];
			if(j -cost[i-1] >= 0)
			{
				dp[i][j] = max(dp[i][j], dp[i-1][j - cost[i-1]] + pages[i-1]);
			}
		}
	}
	
	cout<<dp[n][money];
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
