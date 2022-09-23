#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n);
    for(auto&c:arr){
        cin>>c;
    }

    map<int,int>mp;

    int flag2 = 0;

    for(int i = 0; i< n; ++i){
        mp[arr[i]]++;

        if(mp[arr[i]] >= 3){
            cout<<0<<'\n';
            return;
        }

        if(mp[arr[i]] == 2){
            flag2 = 1;
        }
    }

    sort(arr.begin(), arr.end());
    //sort(marked.begin(), marked.end());
    int ans = INT_MAX;

    if(flag2 == 1){
        for(int i = 0; i< n-1; ++i){
            if(arr[i] == arr[i+1]){
                if(i-1 >=0){
                    ans = min(ans, abs(arr[i] - arr[i-1]));
                }
                if(i+2 < n){
                    ans = min(ans, abs(arr[i+1] - arr[i+2]));
                }
            }
        }

        cout<<ans<<'\n';
        return;
    }else{
        int ans = INT_MAX;

        for(int i = 1; i< n-1; ++i){
            ans = min(ans, abs(arr[i] - arr[i-1])+abs(arr[i]-arr[i+1]));
        }

        cout<<ans<<'\n';
        return;
    }


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
