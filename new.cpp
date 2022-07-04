#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long

void solve()
{
    int n;
    cin>>n;

    if(n == 1)
    {
        cout<<-1<<'\n';
        return;
    }

    if(n%2 == 0)
    {
        cout<<0<<" "<<0<<" "<<n/2<<'\n';
        return;
    }
    
    cout<<<<" "<<(n-1)/2<<" "<<(n-1)/2<<'\n';
    return;
    
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
