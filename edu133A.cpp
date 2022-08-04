#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long


void solve()
{
    int n;
    cin>>n;

    int ans = n/3;
    if(n == 0)
    {
        cout<<0<<'\n';
        return;
    }
    if(n == 1)
    {
        cout<<2<<'\n';
        return;
    }
    if(n == 2)
    {
        cout<<1<<'\n';
        return;
    }
    if(n == 4)
    {
        cout<<2<<'\n';
        return;
    }

    if(n%3 == 0)
    {
        cout<<ans<<'\n';
        return;
    }
    
    else if(n%3 == 1)
    {
        ans  = 1;
        n = n+1;

        ans += n/3;

        cout<<ans<<'\n';
        return;
    }
    else
    {
        cout<<n/3 +1<<'\n';
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
