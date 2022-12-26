#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    string p;
    
    if(n <= 2) {
        cout<<s<<'\n';
        return;
    }
    int shuffles = 0;

    for(int i = 0; i < n; ++i) {
        if((i+1)%2) {
            shuffles ++;
        }
    }

    cout<<shuffles;
    shuffles--;

    if(shuffles % 2) {
        if(n % 2) {
            reverse(s.begin() , s.end());
        } else 
        {
            reverse(s.begin() , s.begin() + n -1 );
        }
        
    }

    cout<<s<<'\n';
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
