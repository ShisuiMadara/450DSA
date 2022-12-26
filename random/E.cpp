#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    for(int i = 0; i< n; ++i) {
        if( m >= arr[i]) {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";

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
