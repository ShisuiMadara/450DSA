#include<bits/stdc++.h>
using namespace std;


void solve() {

    int n,k;
    cin>>n>>k;

    vector<int>a1(n),a2(n);

    for(auto&c:a1)cin>>c;

    for(auto&c:a2)cin>>c;

    map<int,vector<int>> mp;

    for(int i = 0; i<n; ++i) {
        mp[a1[i]].push_back(i);
    }

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    vector<int>ans(n,0);

    for(int i = 0; i<n; ++i) {
        // cout<<a1[i]<<" was at "<<mp[a1[i]][0];
        ans[mp[a1[i]][0]] = a2[i];
        mp[a1[i]].erase(mp[a1[i]].begin());
    }
    
    for(auto&c:ans)cout<<c<<" ";

    cout<<endl;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}