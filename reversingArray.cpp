#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    int n;
	    cin>>n;
	    
	    vector<int>v(n);
	    for(auto&c:v)cin>>c;
	    
	    for(int i = 0; i <n/2; ++i)
	    {
	        int x = v[i];
	        v[i] = v[n-1-i];
	        v[n-i-1] = x;
	    }
	    
	    for(auto&c:v)cout<<c<<" ";
	    cout<<'\n';
}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

     ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
