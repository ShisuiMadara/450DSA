#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin>>n>>k;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    map<int,int>mp;

    int ans = 0;

    for(int i = 0; i<n; ++i) {

        if(mp[arr[i]]) {
            ans --;
        }

        ans++;
        mp[arr[i]] ++;
    }

    return 0;
}