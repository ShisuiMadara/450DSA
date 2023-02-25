#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    vector<int>dp(n+1,0);

    for(int i = 1; i<=n; ++i) {
        dp[i] = max(dp[i] , dp[i-1] + arr[i]);
    }

    // for(auto&c:dp)cout<<c<<" ";

    // cout<<endl; 
    int ans = 0;

    int flag = 0;
    int cnt = 0;

    for(int i = 0; i <=n; ++i) {

        if(dp[i] > 0) {
            flag =1 ;
         
        }
        
        if(flag)
            if(dp[i] > 0) {
                cnt ++;
            }
        }

    cout<<cnt;

}