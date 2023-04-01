#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    int n,x;
    cin>>n>>x;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    map<int,int>mp;

    for(int i = 0; i<n; ++i) {
        mp[arr[i]] ++;
    }

    for(int i = 0; i< n; ++i) {
        // cout<<arr[i]+x<<" ";
        // cout<<mp[arr[i] + x]<<endl;
        if(mp[arr[i] + x]) {
            // cout<<arr[i]<<" "<<arr[i]+x <<" "<<arr[i]-x<<endl;
            cout<<"Yes";
            return 0;
        }
    }

    cout<<"No";

 
    return 0;
}