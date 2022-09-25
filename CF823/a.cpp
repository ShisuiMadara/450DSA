#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;
 
 
void solve()
{
    int n,c;
    cin>>n>>c;
 
    vector<int>arr(n);
 
    for(auto&c:arr)cin>>c;
 
    map<int,int>mp;
 
    set<int>se;
 
    for(int i = 0; i< n; ++i){
        mp[arr[i]]++;
        if(mp[arr[i]] >= c){
            se.insert(arr[i]);
        }
    }
 
    int i = 0;
 
    int ans = 0;
 
    for(auto&d:mp){ 
        if(se.find(d.first) != se.end()){ ans += c; }else{ ans += mp[d.first]; } }
 
    cout<<ans<<'\n';
}
 
 
 
signed main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
     ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}