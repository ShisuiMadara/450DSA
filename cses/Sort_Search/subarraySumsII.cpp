#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    int n, target;
    cin>>n>>target;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    vector<int>pre(n,0);

    pre[0] = arr[0];

    for(int i = 1; i<n; ++i) {
        pre[i] = pre[i-1] + arr[i];
    }

    map<int,int>mp;
    int ans = 0;
    for(int i = 0; i<n; ++i) {

        if(mp[pre[i] - target]) {
            ans += mp[pre[i] - target];
        }
        if(pre[i] == target) {
            ans ++;
        }

        mp[pre[i]]++;
    }

    cout<<ans;

    return 0;
}