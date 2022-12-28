#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;

bool ok[1000][1000];
ll dp[1000][1000];

int travel(int x, int y,vector<vector<char>>arr, vector<vector<int>>dp) {
    int n = arr.size();

    if(x == n-1 && y == n-1) {
        cout<<"Reached";
        return 1;
    }

    if(arr[x][y] == '*') {
        return 0;
    }

    dp[x][y] = travel(x-1,y,arr,dp) + travel(x, y-1,arr,dp);
    
    return dp[x][y];
}


void solve()
{
    int n; cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < n; j++) {
			if(s[j] == '.') ok[i][j] = true;
			else ok[i][j] = false;
		}
	}

	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(!ok[i][j]) dp[i][j] = 0;
			else {
				if(i > 0) dp[i][j] += dp[i - 1][j];
				if(j > 0) dp[i][j] += dp[i][j - 1];
				dp[i][j] %= 1000000007;
			}
		}
	}

	cout << dp[n - 1][n - 1];
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
