#include<bits/stdc++.h>
using namespace std;
//#define int   long long
//const int inf=1000000000000000000;
const int mod=998244353; 
//const int mod=1000000007;
void solve() {

    int n;
    cin >> n;

    vector<double> p(n);
    for(auto&c:p)
        cin >> c;
    
    vector<vector<double>> dp(n+1, vector<double>(n+1));
 
    dp[0][0] = 1.0;
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i < j) {
                continue;
            }
            dp[i+1][j] += dp[i][j] * (1.0 - p[i]);
            dp[i+1][j+1] += dp[i][j] * p[i];
        }
    }
 
    double ans = 0.0;
 
    for(int i = n / 2 + 1; i <= n; i++){
        ans += dp[n][i];
    }
 
    cout << setprecision(9) << ans;
    
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
