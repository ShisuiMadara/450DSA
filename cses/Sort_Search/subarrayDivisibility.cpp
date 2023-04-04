#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    int n;
    cin>>n;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    vector<int>pre(n);
    
    pre[0] = arr[0];

    for(int i = 1; i<n; ++i) {
        pre[i] = pre[i-1] + arr[i];
    }

    map<int,int>mp;
    int ans= 0;

    for(int i = 0; i<n; ++i) {

        if((pre[i]%n + n)%n == 0) {
            ans ++;
        }

        if(mp[(pre[i]%n + n)%n]) {
            ans += mp[(pre[i]%n + n)%n];
        }

     

        mp[(pre[i]%n + n)%n]++;
    }

    // for(auto&c:pre)cout<<c<<" ";

    cout<<ans;

    return 0;
}

