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

    for(auto&c:arr)cin>>c;

    sort(arr.begin(), arr.end());;

    int tar ;

    if(n%2) {
        tar = arr[n/2];
    } else {
        tar = arr[n/2] + arr[n/2 - 1];
        tar = tar/2;
    }

    int ans = 0;

    for(int i = 0; i <n ; ++i) {
        ans += abs(arr[i] - tar);
    }

    cout<<ans;
}



signed main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


     ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
