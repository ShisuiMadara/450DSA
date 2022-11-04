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

    for(auto&c:arr) cin>>c;

    int pre_sum = arr[0];
    int ans = arr[0];
        
    for(int i = 1; i< n; ++i)
    {
        pre_sum = max(pre_sum+arr[i], arr[i]);
        ans = max(ans, pre_sum);
    }
    
    ans == INT_MIN ? cout<<-1 : cout<<ans;
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
