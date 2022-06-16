#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long


void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int ans = n;

    int last0, last1;

    for(int i = 0; i< n-1; ++i)
    {
        if(s[i] != s[i+1])
        {
            ans+=i+1;
        }
    }
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
