#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    int n;
    cin>>n;
    
    vector<int>arr(n);
    
    for(auto&c:arr)cin>>c;
    
    //reduce to increasing sequence 
    
    int mx = *max_element(arr.begin(), arr.end());
    int mi = *min_element(arr.begin(), arr.end());
    
    sort(arr.begin(), arr.end());
    
    int tar = 1;
    int ans = 0;
    map<int,int>mp;
    
    for(auto&c:arr){
        mp[c]++;
    }
    int i = 0;
    
    //111222
    //111112 - > 0
    //111222 -> 0
    //1112223333 -> 0
    // only one instance of increasing 
    
    while(i<n) {
        if(mp[tar]) {
            i+= mp[tar];
            tar++;
            continue;
        } else {
            ans += (arr[i] - tar);
            //cout<<ans<<endl;
            mp[arr[i]]--;
            mp[tar]++;
            i++;
        }
        tar++;
    }
    
    cout<<ans<<endl;
    
}


signed main()
{
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }
}